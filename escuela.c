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
    int numGrupo;
    long int matricula;
    struct fecha fechaCreacion;
};

bool validarFecha(struct fecha, struct fecha);
bool validarInt(int, int, int, char[2]);
bool validarString(char *, int, int);
bool validarRes(char);
bool validarCorreo(char [40]);
bool validarTelefono(long long int);

bool buscarMateria(struct datosMateria *, int, int);
bool buscarProfesor(struct datosProfesor *, int, int);
bool buscarGrupo(struct datosGrupo *, int, int);
bool buscarAlumno(struct datosAlumno *, int, int);

struct fecha obtenerFechaActual();

int escogerModo(void);
char escogerModoReportes();

void ingresarAlumnos(struct datosAlumno *, int *);
void ingresarMaterias(struct datosMateria *, int *);
void ingresarProfesores(struct datosProfesor *, int *);
void ingresarGrupos(struct datosGrupo *, int *, struct datosMateria [], int, struct datosProfesor [], int);
void inscripcion(struct datosInscripcion *, int *, struct datosGrupo [], int, struct datosAlumno [], int);
void menuReportes(struct datosAlumno [], int, struct datosProfesor [], int, struct datosMateria [], int,
    struct datosGrupo [], int, struct datosInscripcion [], int);
void listaAlumnos();
void listaMaterias();
void listaGrupos();
void listaInscripcion();

int main()
{
    int opcion, contAlumnos, contProfesores, contGrupos, contInscripciones, contMaterias;
    struct datosAlumno listaAlumnos[100] = {
        {.matricula = 1212143, .telefono = 4343434343LL, .nombre = "Cesar", .carrera = "Computacion", .correo = "@.", .semestre = 7, .fechaNac = {.dd = 5, .mm = 9, .aaaa = 2002}},
        {.matricula = 1818182, .telefono = 8898484848LL, .nombre = "Miguel", .carrera = "Computacion", .correo="miguel@gmail.com", .semestre =2, .fechaNac={.dd=4, .mm=1, .aaaa=2002}},
        {.matricula = 1919142, .telefono = 8282854528LL, .nombre = "Pepe", .carrera = "Dibujo", .correo="pepe@gmail.com", .semestre=3,.fechaNac={.dd=2, .mm=2, .aaaa=2002}},
        {.matricula = 1982823, .telefono = 8118234543LL, .nombre = "Juan", .carrera = "Computacion", .correo="juan@gmail.com" , .semestre=1, .fechaNac={.dd=1, .mm=3, .aaaa=2010}},
        {.matricula = 1234323, .telefono = 9292921763LL, .nombre = "Jose", .carrera = "Dibujo", .correo="jose@gmail.com", .semestre=5, .fechaNac={.dd=4, .mm=5, .aaaa=2020}}
    }; // A lo mucho 100 alumnos
    struct datosProfesor listaProfesores[100] = {
        {.telefono = 1029394939LL, .numEmpleado = 11, .coordinacion = 3, .nombre = "Pabla", .correo = "pabla@gmail.com", .fechaNac = {.dd = 1, .mm = 3, .aaaa = 1997}},
        {.telefono = 1029394939LL, .numEmpleado = 14, .coordinacion = 1, .nombre = "Pablo", .correo = "pablo@gmail.com", .fechaNac = {.dd = 1, .mm = 2, .aaaa = 1960}},
        {.telefono = 2029394939LL, .numEmpleado = 254, .coordinacion = 2, .nombre = "Tenorio", .correo = "tenorio@gmail.com", .fechaNac = {.dd = 2, .mm = 3, .aaaa = 2020}},
        {.telefono = 3029394939LL, .numEmpleado = 32, .coordinacion = 3, .nombre = "Luis", .correo = "luis@gmail.com", .fechaNac = {.dd = 3, .mm = 4, .aaaa = 1978}},
        {.telefono = 4029394939LL, .numEmpleado = 44, .coordinacion = 4, .nombre = "Jose", .correo = "jose@gmail.com", .fechaNac = {.dd = 4, .mm = 5, .aaaa = 2012}}
    }; // A lo mucho 100 profesores
    struct datosGrupo listaGrupos[100] = {
        {.numGrupo = 543, .semestre = 2, .materias = {31, 13, 21}, .profesores = {14, 14, 254}, .fechaCreacion = {.dd = 27, .mm = 10, .aaaa = 2021}},
        {.numGrupo = 53, .semestre = 4, .materias = {34, 42}, .profesores = {32, 44}, .fechaCreacion = {.dd = 25, .mm = 10, .aaaa = 2021}},
        {.numGrupo = 43, .semestre = 2, .materias = {31, 21, 34}, .profesores = {254, 32, 44}, .fechaCreacion = {.dd = 30, .mm = 10, .aaaa = 2021}}
    }; // A lo mucho 100 grupos
    struct datosInscripcion listaInscripciones[100] = {
        {.matricula = 1818182, .numGrupo = 53, .fechaCreacion = {.dd = 4, .mm = 11, .aaaa = 2021}},
        {.matricula = 1234323, .numGrupo = 43, .fechaCreacion = {.dd = 5, .mm = 11, .aaaa = 2021}},
        {.matricula = 1919142, .numGrupo = 53, .fechaCreacion = {.dd = 3, .mm = 11, .aaaa = 2021}},
        {.matricula = 1982823, .numGrupo = 543, .fechaCreacion = {.dd = 2, .mm = 11, .aaaa = 2021}},
        {.matricula = 1212143, .numGrupo = 43, .fechaCreacion = {.dd = 6, .mm = 11, .aaaa = 2021}},
    }; // A lo mucho 100 inscripciones
    struct datosMateria listaMaterias[100]={
        {.clave = 31, .semestre = 1, .nombre = "Algebra"},
        {.clave = 13, .semestre = 1, .nombre = "Fisica"},
        {.clave = 21, .semestre = 2, .nombre = "Calculo"},
        {.clave = 34, .semestre = 3, .nombre = "Programacion"},
        {.clave = 42, .semestre = 4, .nombre = "Artes"}
    }; // A lo mucho 100 materias

    contAlumnos = 5; // Esto es para asegurarse de que siempre se ponga un alumno nuevo en la siguiente casilla disponible
    contProfesores = 5; // Lo mismo para los profesores
    contGrupos = 3; // Y para los grupos
    contInscripciones = 5; // Y las inscripciones
    contMaterias = 5; // Y las materias
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
                inscripcion(listaInscripciones, &contInscripciones, listaGrupos, contGrupos, listaAlumnos, contAlumnos);
                break;

            case 6:
                menuReportes(listaAlumnos, contAlumnos, listaProfesores, contProfesores, listaMaterias,
                    contMaterias, listaGrupos, contGrupos, listaInscripciones, contInscripciones);
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

bool validarCorreo(char validando[40])
{
    bool valido;

    if (strchr(validando, '@') == NULL || strchr(validando, '.') == NULL)  // strchr regresa NULL si no se encontro el caracter
        valido = 0;
    else
        valido = 1;

    return valido;
}

bool validarTelefono(long long int validando)
{
    bool valido;

    if (validando >= 1000000000LL || validando <= 9999999999LL) //LL es de long long int para que sea posible comparar los numeros grandes
        valido = 1;
    else
        valido = 0;

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
    } while (!validarInt(opcionMenuP, 1, 7, "[]"));

    return opcionMenuP;
}

void ingresarAlumnos(struct datosAlumno *alumnos, int *offset)
{
    char res;

    do
    {
        do
        {
            do
            {
                printf("\n1) Matricula (Mayor que cero): ");
                scanf("%ld", &alumnos[*offset].matricula);
            } while (!validarInt(alumnos[*offset].matricula, 0,  __INT_MAX__, "(]")); // (0, maximo]
        } while (buscarAlumno(alumnos, alumnos[*offset].matricula, *offset - 1)); // Validar que no exista ya, el -1 es para que no se encuentre a si mismo

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(alumnos[*offset].nombre);
        } while (!validarString(alumnos[*offset].nombre, 1, 40)); // Longitud al menos 1

        do
        {
            printf("\n3) Carrera: ");
            fflush(stdin);
            gets(alumnos[*offset].carrera);
        } while (!validarString(alumnos[*offset].carrera, 1, 40)); // Longitud al menos 1. No lo pide pero es bueno añadirlo
        
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
        } while (!validarFecha(alumnos[*offset].fechaNac, obtenerFechaActual())); 

        do
        {
            printf("\n6) Correo electronico (Debe tener \'@\' y \'.\'): ");
            fflush(stdin);
            gets(alumnos[*offset].correo);
        } while (!validarCorreo(alumnos[*offset].correo));

        do
        {
            printf("\n7) Telefono (10 digitos): ");
            scanf("%lld", &alumnos[*offset].telefono);
        } while (!validarTelefono(alumnos[*offset].telefono)); 

        (*offset)++; // Aumenta la cantidad de alumnos

        do
        {
            printf("\nAgregar otro alumno? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (!validarRes(res));
    } while (res == 's' && *offset < 100); // Va de 0 a 99, el offset termina siendo 100 que representa la cantidad total
}

void ingresarMaterias(struct datosMateria *materias, int *offset)
{
    char res;

    do
    {
        do
        {
            do
            {
                printf("\n1) Clave (Mayor que cero): ");
                scanf("%d", &materias[*offset].clave);
            } while (!validarInt(materias[*offset].clave, 0, __INT_MAX__, "(]"));
        } while (buscarMateria(materias, materias[*offset].clave, *offset - 1)); // Validar que no exista ya, el -1 es para que no se encuentre a si mismo

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(materias[*offset].nombre);
        } while (!validarString(materias[*offset].nombre, 1, 40));

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
        } while (!validarRes(res));
    } while (res == 's' && *offset < 100);
}

void ingresarProfesores(struct datosProfesor *profesores, int *offset)
{
    char res;

    do
    {
        do
        {
            do
            {
                printf("\n1) Numero de empleado (Mayor que cero): "); 
                scanf("%d", &profesores[*offset].numEmpleado);
            } while (!validarInt(profesores[*offset].numEmpleado, 0, __INT_MAX__, "(]"));
        } while (buscarProfesor(profesores, profesores[*offset].numEmpleado, *offset - 1)); // Validar que no exista ya, el -1 es para que no se encuentre a si mismo

        do
        {
            printf("\n2) Nombre: ");
            fflush(stdin);
            gets(profesores[*offset].nombre);
        } while (!validarString(profesores[*offset].nombre, 1, 40)); // Longitud al menos 1

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
        } while (!validarFecha(profesores[*offset].fechaNac, obtenerFechaActual())); 
        
        do
        {
            printf("\n5) Correo electronico (Debe tener \'@\' y \'.\'): ");
            fflush(stdin);
            gets(profesores[*offset].correo);
        } while (!validarCorreo(profesores[*offset].correo));

        do
        {
            printf("\n6) Telefono (10 digitos): ");
            scanf("%lld", &profesores[*offset].telefono);
        } while (!validarTelefono(profesores[*offset].telefono)); 

        (*offset)++; // Aumenta la cantidad de alumnos

        do
        {
            printf("\nAgregar otro profesor? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (!validarRes(res));
    } while (res == 's' && *offset < 100);
}

void ingresarGrupos(struct datosGrupo *grupos, int *offset,
    struct datosMateria materias[], int maxMaterias, struct datosProfesor profesores[], int maxProfesores)
{
    char res;
    int i, j;

    do
    {
        do
        {
            do
            {
                printf("\n1) Numero de grupo (Mayor que cero): "); 
                scanf("%d", &grupos[*offset].numGrupo);
            } while (!validarInt(grupos[*offset].numGrupo, 0, __INT_MAX__, "(]"));
        } while (buscarGrupo(grupos, grupos[*offset].numGrupo, *offset - 1));

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
            printf("Materia #%d de 7 maximo\n", i+1);
            do
            {
                do
                {
                    printf("Ingrese el numero de materia\n? " );
                    scanf("%d", &grupos[*offset].materias[i]);
                } while (!validarInt(grupos[*offset].materias[i], 0, __INT_MAX__, "(]"));
            } while (!buscarMateria(materias, grupos[*offset].materias[i], maxMaterias));
            
            i++;

            do
            {
                printf("\nAgregar otra materia? (s/n)\n? ");
                fflush(stdin);
                scanf("%c", &res);
            } while (res != 's' && res != 'n');
        }

        printf("\n4) Profesores\n");
        j = 0;
        res = 's';
        while (j < i && res == 's')
        {
            printf("Profesor de la materia #%d\n", j);
            do
            {
                do
                {
                    printf("Ingrese la clave del profesor\n? " );
                    scanf("%d", &grupos[*offset].profesores[i]);
                } while (!validarInt(grupos[*offset].profesores[i], 0, __INT_MAX__, "(]"));
            } while (!buscarProfesor(profesores, grupos[*offset].profesores[i], maxProfesores));
        }

        grupos[*offset].fechaCreacion = obtenerFechaActual();

        (*offset)++;

        do
        {
            printf("\nAgregar otro grupo? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (!validarRes(res));
    } while (res == 's' && *offset < 100);
}

void inscripcion(struct datosInscripcion *inscripciones, int *offset, 
    struct datosGrupo grupos[], int maxGrupos, struct datosAlumno alumnos[], int maxAlumnos)
{
    char res;

    do
    {
        do
        {
            do
            {
                printf("1) Grupo (numero): " );
                scanf("%d", &inscripciones[*offset].numGrupo);
            } while (!validarInt(inscripciones[*offset].numGrupo, 0, __INT_MAX__, "(]"));
        } while (!buscarGrupo(grupos, inscripciones[*offset].numGrupo, maxGrupos));
                   
        do
        {
            do
            {
                printf("\n2) Matricula (Mayor que cero): ");
                scanf("%ld", &inscripciones[*offset].matricula);
            } while (!validarInt(inscripciones[*offset].matricula, 0,  __INT_MAX__, "(]")); // (0, maximo]
        } while (!buscarAlumno(alumnos, inscripciones[*offset].matricula, maxAlumnos)); // Validar que no exista ya, el -1 es para que no se encuentre a si mismo

        inscripciones[*offset].fechaCreacion = obtenerFechaActual();

        (*offset)++;

        do
        {
            printf("\nAgregar otra inscripcion? (s/n)\n? ");
            fflush(stdin);
            scanf("%c", &res);
        } while (!validarRes(res));
    } while (res == 's' && *offset < 100);
}

char escogerModoReportes()
{
    char opcionMenuR;

    printf("\n\tMenu de reportes\n"
        "a) Listado de alumnos por carrera\n"
        "b) Listado de materias que imparte un profesor\n"
        "c) Listado de grupos por fecha\n"
        "d) Listado de inscripciones por grupo\n"
        "e) Generar archivo de alumnos\n"
        "f) Generar archivo de profesores\n"
        "g) Mostrar un archivo\n"
        "h) Salir\n");

    do
    {
        printf("\nSeleccionar una opcion\n? ");
        fflush(stdin);
        scanf("%c", &opcionMenuR);
    } while (!validarInt(opcionMenuR, 'a', 'h', "[]"));

    return opcionMenuR;
}

void listaAlumnos(struct datosAlumno alumnos[], int maxAlumnos)
{

    char carrera[40];
    int i;
    printf("Carrera: \n");
    scanf("%s", carrera);
    printf("%-10s%-12s%-14s%-20s%-40s\n",
                "Matricula", "telefono", "carrera", "correo", "nombre");

    for (i=0; i<maxAlumnos; i++) {
        if (strncmp(carrera, alumnos[i].carrera, strlen(carrera))==0) {
    
            printf("%-10ld%-12lld%-14s%-20s%-40s\n",alumnos[i].matricula, alumnos[i].telefono,
                     alumnos[i].carrera, alumnos[i].correo, alumnos[i].nombre);
        }
    }
}
void listaMaterias(struct datosMateria materias[], int maxMaterias)
{

    int i, clave;
    printf("Clave Profesor: \n");
    scanf("%d", &clave);

    printf("%-7s%-15s\n", "Clave", "Nombre Materia");
    for (i=0; i<maxMaterias; i++) {
        if (clave==materias[i].clave) {
            printf("%-7d%-15s\n", materias[i].clave, materias[i].nombre);
        }
    }
}
void listaGrupos(struct datosGrupo grupos[], int maxGrupos)
{

    struct fecha fechaL;

    int i;
    printf("Ingresar la fecha: \n");
            do
            {
                printf("\ta) A%co: ", 164); // 164 = ñ
                scanf("%d", &fechaL.aaaa);
            } while (!validarInt(fechaL.aaaa, 1900, __INT_MAX__, "(]"));

            do
            {
                printf("\tb) Mes: ");
                scanf("%d", &fechaL.mm);
            } while (!validarInt(fechaL.mm, 1, 12, "[]"));
            
            do
            {
                printf("\tc) Dia: ");
                scanf("%d", &fechaL.dd);
            } while (!validarInt(fechaL.mm, 1, 31, "[]"));

    printf("%-10s%-14s%-10s%-20s\n","Num grupo", "materias", "semestre", "profesores");
    for (i=0; i<maxGrupos; i++) {
        if(!validarFecha(grupos[i].fechaCreacion, fechaL) )           
    printf("%-10d%-14ls%-10d%-20ls",grupos[i].numGrupo, grupos[i].materias, grupos[i].semestre, grupos[i].profesores);
    }
}
void listaInscripciones(struct datosInscripcion inscripciones[], int maxInscripciones)
{

    int i, grupo;
    printf("Ingrese el grupo: \n");
    scanf("%d", &grupo);
    printf("%-20s%-18s%-18s\n", "Fecha Inscripcion", "Num grupo", "Matricula");
    for (i=0; i<maxInscripciones; i++) {
        if (grupo==inscripciones[i].numGrupo) {
    printf("%4d/%02d/%02d", inscripciones[i].fechaCreacion.aaaa, inscripciones[i].fechaCreacion.mm, inscripciones[i].fechaCreacion.dd);
    printf("%18d%18ld\n", inscripciones[i].numGrupo,inscripciones[i].matricula);
        }
    }
}


void menuReportes(struct datosAlumno alumnos[], int maxAlumnos, struct datosProfesor profesores[], int maxProfesores,
    struct datosMateria materias[], int maxMaterias, struct datosGrupo grupos[], int maxGrupos,
    struct datosInscripcion inscripciones[], int maxInscripciones)
{
    char opcion;

    while ((opcion = escogerModoReportes()) != 'h') 
    {
        switch(opcion) // A las funciones se les pasa el apuntador al array correspondiente, y en algunos casos el indice donde se debe guardar
        {
            case 'a':
                listaAlumnos(alumnos, maxAlumnos);
                break;

            case 'b':
                listaMaterias(materias, maxMaterias);
                break;

            case 'c':
                listaGrupos(grupos, maxGrupos);
                break;

            case 'd':
                listaInscripciones(inscripciones, maxInscripciones);
                break;

            case 'e':
                // generarArchivoAlum();
                break;

            case 'f':
                // generarArchivoProf();
                break;
                
            case 'g':
                // abrirArchivo();
                break;
            
        }
    }
}
