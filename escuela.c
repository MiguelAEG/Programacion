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

struct datosProfesor
{
    long long int telefono;
    int numEmpleado, coordinacion;
    char nombre[40], correo[40];
    struct fecha fechaNac;
};

struct datosGrupo
{
    int numGrupo, semestre, materias[7], profesores[7];
    struct fecha fechaCreacion;
};

struct inscripcion
{
    int grupo, matricula;
    struct fecha fechaActual;
};

struct fecha obtenerFechaActual();
int validarFecha(struct fecha, struct fecha);
int escogerModo(void);
void ingresarAlumnos(struct datosAlumno *, int *);
<<<<<<< HEAD
void ingresarMaterias(struct materia *, int *);
int main()
{
    int opcion, contAlumnos, contMaterias;
    struct datosAlumno listaAlumnos[100]; // A lo mucho 100 alumnos
    struct materia listaMaterias[100];

=======
void ingresarProfesores(struct datosProfesor *, int *);
void ingresarGrupos(struct datosGrupo *, int *);

int main()
{
    int opcion, contAlumnos, contProfesores, contGrupos;
    struct datosAlumno listaAlumnos[100]; // A lo mucho 100 alumnos
    struct datosProfesor listaProfesores[100]; // A lo mucho 100 profesores
    struct datosGrupo listaGrupos[100]; // A lo mucho 100 grupos
>>>>>>> 820a6fa865df08db5569da1b74634c3cfee8efce


    contMaterias=0;
    contAlumnos = 0; // Esto es para asegurarse de que siempre se ponga un alumno nuevo en la siguiente casilla disponible
    contProfesores = 0; // Lo mismo para los profesores
    contGrupos = 0; // Y para los grupos
    while ((opcion = escogerModo()) != 7) 
    {
        switch(opcion) // A las funciones se les pasa el apuntador al array correspondiente, y en algunos casos el indice donde se debe guardar
        {
            case 1:
                ingresarAlumnos(listaAlumnos, &contAlumnos);
                break;

            case 2:
                ingresarMaterias(listaMaterias, &contMaterias);
                break;

            case 3:
                ingresarProfesores(listaProfesores, &contProfesores);
                break;

            case 4:
                ingresarGrupos(listaGrupos, &contGrupos);
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

struct fecha obtenerFechaActual() {
    time_t t = time(NULL); // Inicializar la variable que se usara para la estructura
    struct tm *fechayhora; // Estructura tm definida en time.h
    fechayhora = localtime(&t); // Inicializa la estructura tm para obtener el tiempo actial

    struct fecha fechaConvertida = { // Inicializar una estructura fecha para regresar en la funcion
        .aaaa = fechayhora->tm_year + 1900, // El año de la estructura tm empieza en 1900
        .mm = fechayhora->tm_mon + 1, // El mes de la estructura tm va de 0 a 11
        .dd = fechayhora->tm_mday // mday es el dia del mes (0-31)
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
            printf("\nAgregar otro alumno? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100); // Va de 0 a 99, el offset termina siendo 100 que representa la cantidad total
}

<<<<<<< HEAD
void ingresarMaterias(struct materia *materias, int *offset){

    char res;
    do {
        do {
            printf("\n1)Nombre: ");
            fflush(stdin);
            gets(materias[*offset]. nombre);
        }while (strlen(materias[*offset].nombre)==0);

        do {       
            printf("\n2)Semestre: ");
            scanf("%d", &materias[*offset].semestre);
        }while (materias[*offset].semestre<1 || materias[*offset].semestre>10);

    }while (res=='s' &&*offset<100);

}

void tiempo() {
=======
void ingresarProfesores(struct datosProfesor *profesores, int *offset)
{
    char res;
    do
    {
        do
        {
            printf("\n1) Numero de empleado (Mayor que cero): ");
            scanf("%d", &profesores[*offset].numEmpleado);
        } while (profesores[*offset].numEmpleado <= 0);

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(profesores[*offset].nombre);
        } while (strlen(profesores[*offset].nombre) == 0); // Longitud al menos 1

        do
        {
            printf("\n3) Coordinacion (1-6): ");
            scanf("%d", &profesores[*offset].coordinacion);
        } while (profesores[*offset].coordinacion < 1 || profesores[*offset].coordinacion > 6);

        do // Este es para validar que la fecha introducida sea menor que la actual
        {
            printf("\n4) Fecha de nacimiento\n");

            do
            {
                printf("\ta) A%co: ", 164); // 164 = ñ
                scanf("%d", &profesores[*offset].fechaNac.aaaa);
            } while (profesores[*offset].fechaNac.aaaa <= 1900);

            do
            {
                printf("\tb) Mes: ");
                scanf("%d", &profesores[*offset].fechaNac.mm);
            } while (profesores[*offset].fechaNac.mm < 1 || profesores[*offset].fechaNac.mm > 12);
            
            do
            {
                printf("\tc) Dia: ");
                scanf("%d", &profesores[*offset].fechaNac.dd);
            } while (profesores[*offset].fechaNac.dd < 1 || profesores[*offset].fechaNac.dd > 31);
        } while (validarFecha(profesores[*offset].fechaNac, obtenerFechaActual()) == 0); // 0 significa que la fecha introducida es mayor o igual a la actual
        
        do
        {
            printf("\n5) Correo electronico (Debe tener \'@\' y \'.\'): ");
            fflush(stdin);
            gets(profesores[*offset].correo);
        } while (strchr(profesores[*offset].correo, '@') == NULL || strchr(profesores[*offset].correo, '.') == NULL); // strchr regresa NULL si no se encontro el caracter

        do
        {
            printf("\n6) Telefono (10 digitos): ");
            scanf("%lld", &profesores[*offset].telefono);
        } while (profesores[*offset].telefono < 1000000000LL || profesores[*offset].telefono > 9999999999LL); //LL es de long long int para que sea posible comparar los numeros grandes

        (*offset)++; // Aumenta la cantidad de alumnos

        do
        {
            printf("\nAgregar otro profesor? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100);
}

void ingresarGrupos(struct datosGrupo *grupos, int *offset)
{
    char res;
    do
    {
        do
        {
            printf("\n1) Numero de grupo (Mayor que cero): ");
            scanf("%d", &grupos[*offset].numGrupo);
        } while (grupos[*offset].numGrupo <= 0);
>>>>>>> 820a6fa865df08db5569da1b74634c3cfee8efce

        do
        {
            printf("\n2) Semestre (1-10): ");
            scanf("%d", &grupos[*offset].semestre);
        } while (grupos[*offset].semestre < 1 || grupos[*offset].semestre > 10);

        // 3) Materias

        // 4) Profesores, necesito primero las materias para esto

        grupos[*offset].fechaCreacion = obtenerFechaActual();

        do
        {
            printf("\nAgregar otro grupo? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100);
}
