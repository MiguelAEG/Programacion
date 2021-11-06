#include <stdio.h> 
#include <string.h>
//#include "limpieza.h" 
//#define fflush(stdin) limpieza()

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
    //Fecha actual
};

struct inscripcion
{
    int grupo, matricula;
    //Fecha actual
};

int escogerModo(void);
void ingresarAlumnos(struct datosAlumno *, int *);

int main()
{
    int opcion, contAlumnos;
    struct datosAlumno listaAlumnos[100]; // A lo mucho 100 alumnos

    contAlumnos = 0; // Esto es para asegurarse de que siempre se ponga un alumno nuevo en la siguiente casilla disponible
    while ((opcion = escogerModo()) != 7) 
    {
        switch(opcion)
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
        printf("\nSeleccionar una opción\n? ");
        scanf("%d", &opcionMenuP);
    } while (opcionMenuP < 1 || opcionMenuP > 7);

    return opcionMenuP;
}

void ingresarAlumnos(struct datosAlumno *alumnos, int *offset)
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
    } while (strlen(alumnos[*offset].nombre) == 0);

    do
    {
        printf("\n3) Carrera: ");
        fflush(stdin);
        gets(alumnos[*offset].carrera);
    } while (strlen(alumnos[*offset].carrera) == 0);
    
    do
    {
        printf("\n4) Semestre (0-10): ");
        scanf("%d", &alumnos[*offset].semestre);
    } while (alumnos[*offset].semestre < 1 || alumnos[*offset].semestre > 10);

    // TODO: Fecha de nacimiento, validar que sea menor a la actual

    do
    {
        printf("\n6) Correo electronico (Debe tener \'@\' y \'.\'): ");
        fflush(stdin);
        gets(alumnos[*offset].correo);
    } while (strchr(alumnos[*offset].correo, '@') == NULL || strchr(alumnos[*offset].correo, '.') == NULL);

    do
    {
        printf("\n7) Telefono (10 digitos): ");
        scanf("%lld", &alumnos[*offset].telefono);
    } while (alumnos[*offset].telefono < 1000000000LL || alumnos[*offset].telefono > 9999999999LL);
}
