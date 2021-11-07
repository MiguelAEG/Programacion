#include <stdio.h> 
#include <string.h>
#include <time.h>

struct fecha
{
    int dd, mm, aaaa;
};

struct datosAlumno
{
    long int matricula;
    long long int telefono;
    char nombre[40], carrera[40], correo[40];
    int semestre;
    struct fecha fechaNac;
};

struct materia
{
    int clave, semestre;
    char nombre[40];
};

struct profesor
{
    long long int telefono;
    int numEmpleado, coordinacion;
    char nombre[40], correo[40];
    struct fecha fecha_nac;
};

struct grupo
{
    int numero, semestre, materias[7], profesores[7];
    struct fecha fechaActual;
};

struct inscripcion
{
    int grupo, matricula;
    struct fecha fechaActual;
};

int escogerModo(void);
void ingresarAlumnos(struct datosAlumno *, int *);
struct fecha obtenerFechaActual();
int validarFecha(struct fecha, struct fecha);

int main()
{
    int opcion, contAlumnos;
    struct datosAlumno listaAlumnos[100]; // A lo mucho 100 alumnos

    contAlumnos = 0; // Esto es para asegurarse de que siempre se ponga un alumno nuevo en la siguiente casilla disponible
    while ((opcion = escogerModo()) != 7) 
    {
        switch(opcion) // A las funciones se les pasa el apuntador al array correspondiente, y en algunos casos el indice donde se debe guardar
        {
            case 1:
                ingresarAlumnos(listaAlumnos, &contAlumnos);
                break;

            case 2:
                // materias
                break;

            case 3:
                // profesores
                break;

            case 4:
                // grupos
                break;

            case 5:
                // inscripcion
                break;

            case 6:
                // reportes
                break;
            
        }
    }

    return 0;
}

int escogerModo()
{
    int opcionMenuP;

    printf("\n\tMenu principal\n"
        "1) Alumnos\n"
        "2) Materias\n"
        "3) Profesores\n"
        "4) Grupos\n"
        "5) Inscripcion\n"
        "6) Reportes\n"
        "7) Salir\n");

    do
    {
        printf("\nSeleccionar una opcion\n? ");
        scanf("%d", &opcionMenuP);
    } while (opcionMenuP < 1 || opcionMenuP > 7);

    return opcionMenuP;
}

void ingresarAlumnos(struct datosAlumno *alumnos, int *offset)
{
    char res;

    do
    {
        do
        {
            printf("\n1) Matricula (Mayor que cero): ");
            scanf("%ld", &alumnos[*offset].matricula);
        } while (alumnos[*offset].matricula <= 0);

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(alumnos[*offset].nombre);
        } while (strlen(alumnos[*offset].nombre) == 0); // Longitud al menos 1

        do
        {
            printf("\n3) Carrera: ");
            fflush(stdin);
            gets(alumnos[*offset].carrera);
        } while (strlen(alumnos[*offset].carrera) == 0); // Longitud al menos 1. No lo pide pero es bueno añadirlo
        
        do
        {
            printf("\n4) Semestre (0-10): ");
            scanf("%d", &alumnos[*offset].semestre);
        } while (alumnos[*offset].semestre < 1 || alumnos[*offset].semestre > 10);

        do // Este es para validar que la fecha introducida sea menor que la actual
        {
            printf("\n5) Fecha de nacimiento\n");

            do
            {
                printf("\ta) A%co: ", 164); // 164 = ñ
                scanf("%d", &alumnos[*offset].fechaNac.aaaa);
            } while (alumnos[*offset].fechaNac.aaaa <= 1900);

            do
            {
                printf("\tb) Mes: ");
                scanf("%d", &alumnos[*offset].fechaNac.mm);
            } while (alumnos[*offset].fechaNac.mm < 1 || alumnos[*offset].fechaNac.mm > 12);
            
            do
            {
                printf("\tc) Dia: ");
                scanf("%d", &alumnos[*offset].fechaNac.dd);
            } while (alumnos[*offset].fechaNac.dd < 1 || alumnos[*offset].fechaNac.dd > 31);
        } while (validarFecha(alumnos[*offset].fechaNac, obtenerFechaActual()) == 0); // 0 significa que la fecha introducida es mayor o igual a la actual
        
        do
        {
            printf("\n6) Correo electronico (Debe tener \'@\' y \'.\'): ");
            fflush(stdin);
            gets(alumnos[*offset].correo);
        } while (strchr(alumnos[*offset].correo, '@') == NULL || strchr(alumnos[*offset].correo, '.') == NULL); // strchr regresa NULL si no se encontro el caracter

        do
        {
            printf("\n7) Telefono (10 digitos): ");
            scanf("%lld", &alumnos[*offset].telefono);
        } while (alumnos[*offset].telefono < 1000000000LL || alumnos[*offset].telefono > 9999999999LL); //LL es de long long int para que sea posible comparar los numeros grandes

        (*offset)++; // Aumenta la cantidad de alumnos

        do
        {
            printf("\nIngresar otro alumno? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100); // Va de 0 a 99, el offset termina siendo 100 que representa la cantidad total
}

struct fecha obtenerFechaActual() {
    time_t t = time(NULL); // Inicializar la variable que se usara para la estructura
    struct tm *fechayhora; // Estructura tm definida en time.h
    fechayhora = localtime(&t); // Inicializa la estructura tm para obtener el tiempo actial

    struct fecha fechaConvertida = { // Inicializar una estructura fecha para regresar en la funcion
        .aaaa = fechayhora->tm_year + 1900, // El año de la estructura tm empieza en 1900
        .mm = fechayhora->tm_mon + 1, // El mes de la estructura tm va de 0 a 11
        .dd = fechayhora->tm_mday
    };

    return fechaConvertida;
}

int validarFecha(struct fecha fechaIntroducida, struct fecha fechaActual)
{
    int valido;

    if (fechaIntroducida.aaaa < fechaActual.aaaa) // Si el año es menor es valido
        valido = 1;
    else if (fechaIntroducida.aaaa > fechaActual.aaaa) // Si el año es mayor no es valido
        valido = 0;
    else if (fechaIntroducida.mm < fechaActual.mm) // El otro caso es que el año sea igual, si el mes es menor, es valido
        valido = 1;
    else if (fechaIntroducida.mm > fechaActual.mm) // Si el mes es mayor, no es valido
        valido = 0;
    else if (fechaIntroducida.dd < fechaActual.dd) // El otro caso es que el mes sea igual, si el dia es menor es valido
        valido = 1;
    else // El otro caso es que el dia sea igual o mayor, no es valido
        valido = 0;

    return valido;
}
