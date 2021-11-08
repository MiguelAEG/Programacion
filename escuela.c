#include <stdio.h> 
#include <string.h>
#include <time.h>
#include <stdbool.h>

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

struct datosMateria
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

struct datosInscripcion
{
    int numGrupo, matricula;
    struct fecha fechaCreacion;
};

bool validarFecha(struct fecha, struct fecha);
bool validarInt(int, int, int, char[2]);
bool validarString(char *, int, int);
bool validarRes(char);

bool buscarMateria(struct datosMateria *, int, int);
bool buscarProfesor(struct datosProfesor *, int, int);
bool buscarGrupo(struct datosGrupo *, int, int);
bool buscarAlumno(struct datosAlumno *, int, int);

struct fecha obtenerFechaActual();
int escogerModo(void);

void ingresarAlumnos(struct datosAlumno *, int *);
void ingresarMaterias(struct datosMateria *, int *);
void ingresarProfesores(struct datosProfesor *, int *);
void ingresarGrupos(struct datosGrupo *, int *, struct datosMateria [], int, struct datosProfesor [], int); //TODO: esto tambien llevara los datos de la materia y profesores
void inscripcion(struct datosInscripcion *, struct datosGrupo *, struct datosAlumno *, int *);

int main()
{
    int opcion, contAlumnos, contProfesores, contGrupos, contInscripciones, contMaterias;
    struct datosAlumno listaAlumnos[100]; // A lo mucho 100 alumnos
    struct datosProfesor listaProfesores[100]; // A lo mucho 100 profesores
    struct datosGrupo listaGrupos[100]; // A lo mucho 100 grupos
    struct datosInscripcion listaInscripciones[100]; // A lo mucho 100 inscripciones
    struct datosMateria listaMaterias[100]; // A lo mucho 100 materias

    contAlumnos = 0; // Esto es para asegurarse de que siempre se ponga un alumno nuevo en la siguiente casilla disponible
    contProfesores = 0; // Lo mismo para los profesores
    contGrupos = 0; // Y para los grupos
    contInscripciones = 0; // Y las inscripciones
    contMaterias = 0; // Y las materias
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
                ingresarGrupos(listaGrupos, &contGrupos, listaMaterias, contMaterias, listaProfesores, contProfesores);
                break;

            case 5:
                inscripcion(listaInscripciones, listaGrupos, listaAlumnos, &contInscripciones);
                break;

            case 6:
                // reportes
                break;
            
        }
    }

    return 0;
}

bool validarFecha(struct fecha fechaIntroducida, struct fecha fechaActual)
{
    bool valido;

    if (fechaIntroducida.aaaa < fechaActual.aaaa) // Si el año es menor es valido
        valido = true;
    else if (fechaIntroducida.aaaa > fechaActual.aaaa) // Si el año es mayor no es valido
        valido = false;
    else if (fechaIntroducida.mm < fechaActual.mm) // El otro caso es que el año sea igual, si el mes es menor, es valido
        valido = true;
    else if (fechaIntroducida.mm > fechaActual.mm) // Si el mes es mayor, no es valido
        valido = false;
    else if (fechaIntroducida.dd < fechaActual.dd) // El otro caso es que el mes sea igual, si el dia es menor es valido
        valido = true;
    else // El otro caso es que el dia sea igual o mayor, no es valido
        valido = false;

    return valido;
}

bool validarInt(int validando, int min, int max, char modo[2])
{
    bool valido; // Los parentesis () significan intervalo abierto, corchetes [] intervalo cerrado, la combinacion (] o [) denota intervalo semiabierto

    if ((strncmp(modo, "()", 2) == 0 && (validando > min && validando < max))
        || (strncmp(modo, "(]", 2) == 0 && (validando > min && validando <= max))
        || (strncmp(modo, "[)", 2) == 0 && (validando >= min && validando < max))
        || (strncmp(modo, "[]", 2) == 0 && (validando >= min && validando <= max)))
        valido = true;
    else
        valido = false;

    return valido;
}

bool validarString(char *validando, int minL, int maxL)
{
    bool valido;

    if (validarInt(strlen(validando), minL, maxL, "[]"))
        valido = true;
    else
        valido = false;

    return valido;
}

bool validarRes(char validando)
{
    bool valido;

    if(validando == 's' || validando == 'n')
        valido=true;
    else
        valido=false;

    return valido;
}

bool buscarMateria(struct datosMateria *materias, int busqueda, int max)
{
    int i;
    bool encontrado = false;

    for (i = 0; i < max; i++)
    {
        if (materias[i].clave == busqueda)
        {
            printf("Materia encontrada en la base de datos\n");
            encontrado = true;
        }
    }
    
    return encontrado;
}

bool buscarProfesor(struct datosProfesor *profesores, int busqueda, int max)
{
    int i;
    bool encontrado = false;

    for (i = 0; i < max; i++)
    {
        if (profesores[i].numEmpleado == busqueda)
        {
            printf("Profesor encontrado en la base de datos\n");
            encontrado = true;
        }
    }
    
    return encontrado;
}

bool buscarGrupo(struct datosGrupo *grupos, int busqueda, int max)
{
    int i;
    bool encontrado = false;

    for (i = 0; i < max; i++)
    {
        if (grupos[i].numGrupo == busqueda)
        {
            printf("Grupo encontrado en la base de datos\n");
            encontrado = true;
        }
    }
    
    return encontrado;
}

bool buscarAlumno(struct datosAlumno *alumnos, int busqueda, int max)
{
    int i;
    bool encontrado = false;

    for (i = 0; i < max; i++)
    {
        if (alumnos[i].matricula == busqueda)
        {
            printf("Alumno encontrado en la base de datos\n");
            encontrado = true;
        }
    }
    
    return encontrado;
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
        } while (!validarInt(alumnos[*offset].matricula, 0,  __INT_MAX__, "(]")); // (0, maximo]

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
        } while (!validarInt(alumnos[*offset].semestre, 1, 10, "[]"));

        do // Este es para validar que la fecha introducida sea menor que la actual
        {
            printf("\n5) Fecha de nacimiento\n");

            do
            {
                printf("\ta) A%co: ", 164); // 164 = ñ
                scanf("%d", &alumnos[*offset].fechaNac.aaaa);
            } while (!validarInt(alumnos[*offset].fechaNac.aaaa, 1900, __INT_MAX__, "(]"));

            do
            {
                printf("\tb) Mes: ");
                scanf("%d", &alumnos[*offset].fechaNac.mm);
            } while (!validarInt(alumnos[*offset].fechaNac.mm, 1, 12, "[]"));
            
            do
            {
                printf("\tc) Dia: ");
                scanf("%d", &alumnos[*offset].fechaNac.dd);
            } while (!validarInt(alumnos[*offset].fechaNac.mm, 1, 31, "[]"));
        } while (!validarFecha(alumnos[*offset].fechaNac, obtenerFechaActual())); // 0 significa que la fecha introducida es mayor o igual a la actual
        
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

void ingresarMaterias(struct datosMateria *materias, int *offset){

    char res;
    do
    {
        do
        {
            printf("\n1) Clave (Mayor que cero): ");
            scanf("%d", &materias[*offset].clave);
        } while (!validarInt(materias[*offset].clave, 0, __INT_MAX__, "(]"));

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(materias[*offset].nombre);
        } while (strlen(materias[*offset].nombre) == 0);

        do
        {       
            printf("\n3) Semestre: ");
            scanf("%d", &materias[*offset].semestre);
        } while (!validarInt(materias[*offset].semestre, 0, 10, "[]"));

        (*offset)++;

        do
        {
            printf("\nAgregar otra materia? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100);

}

void ingresarProfesores(struct datosProfesor *profesores, int *offset)
{
    char res;
    do
    {
        do
        {
            printf("\n1) Numero de empleado (Mayor que cero): "); 
            scanf("%d", &profesores[*offset].numEmpleado);
        } while (!validarInt(profesores[*offset].numEmpleado, 0, __INT_MAX__, "(]"));

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
        } while (!validarInt(profesores[*offset].coordinacion, 0, 6, "[]"));

        do // Este es para validar que la fecha introducida sea menor que la actual
        {
            printf("\n4) Fecha de nacimiento\n");

            do
            {
                printf("\ta) A%co: ", 164); // 164 = ñ
                scanf("%d", &profesores[*offset].fechaNac.aaaa);
            } while (!validarInt(profesores[*offset].fechaNac.aaaa, 1900, __INT_MAX__, "(]"));

            do
            {
                printf("\tb) Mes: ");
                scanf("%d", &profesores[*offset].fechaNac.mm);
            } while (!validarInt(profesores[*offset].fechaNac.mm, 1, 12, "[]"));
            
            do
            {
                printf("\tc) Dia: ");
                scanf("%d", &profesores[*offset].fechaNac.dd);
            } while (!validarInt(profesores[*offset].fechaNac.mm, 1, 31, "[]"));
        } while (!validarFecha(profesores[*offset].fechaNac, obtenerFechaActual())); // 0 significa que la fecha introducida es mayor o igual a la actual
        
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

void ingresarGrupos(struct datosGrupo *grupos, int *offset, struct datosMateria materias[], int maxMaterias, struct datosProfesor profesores[], int maxProfesores)
{
    char res;
    int i;

    do
    {
        do
        {
            printf("\n1) Numero de grupo (Mayor que cero): "); 
            scanf("%d", &grupos[*offset].numGrupo);
        } while (!validarInt(grupos[*offset].numGrupo, 0, __INT_MAX__, "(]"));

        do
        {
            printf("\n2) Semestre (1-10): ");
            scanf("%d", &grupos[*offset].semestre);
        } while (!validarInt(grupos[*offset].numGrupo, 1, 10, "[]"));

        printf("\n3) Materias\n");
        res = 's';
        i = 0;
        while (i < 7 && res == 's')
        {
            printf("Materia %d de 7 maximo\n", i+1);
            do
            {
                do
                {
                    printf("Ingrese el codigo del grupo\n?" );
                    scanf("%d", &grupos[*offset].materias[i]);
                } while (!validarInt(grupos[*offset].materias[i], 0, __INT_MAX__, "(]")); // Primero validar que sea mayor que cero
            } while (!buscarMateria(materias, grupos[*offset].materias[i], maxMaterias));
            
            do
            {
                printf("\nAgregar otra materia? (s/n)\n? ");
                fflush(stdin);
                scanf("%c", &res);
            } while (res != 's' && res != 'n');
        }

        // TODO: 4) Profesores

        grupos[*offset].fechaCreacion = obtenerFechaActual();

        do
        {
            printf("\nAgregar otro grupo? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (res != 's' && res != 'n');
    } while (res == 's' && *offset < 100);
}

void inscripcion(struct datosInscripcion *inscripciones, struct datosGrupo *grupos,
    struct datosAlumno *alumnos, int *offset)
{
    
}
