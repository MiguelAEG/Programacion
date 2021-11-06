#include <stdio.h> 
//#include "limpieza.h" 
//#define fflush(stdin) limpieza()

struct fecha
{
    int dd, mmm, aaaa;
};

struct alumno
{
    long int matricula, telefono;
    char nombre[40], carrera[40], correo[40];
    int semestre;
    struct fecha fecha_nac;
};

struct materia
{
    int clave, semestre;
    char nombre[40];
};

struct profesor
{
    long int telefono;
    int num_empleado, coordinacion;
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

int main()
{
    int opcion;
    struct alumno alumnos[100];

    while ((opcion = escogerModo()) != 7) {
        switch(opcion){
            case 1:
                // alumnos
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

    printf("\nMenu principal\n"
        "1) Alumnos\n"
        "2) Materias\n"
        "3) Profesores\n"
        "4) Grupos\n"
        "5) Inscripcion\n"
        "6) Reportes\n"
        "7) Salir\n");

    do
    {
        printf("Seleccionar una opción\n? ");
        scanf("%d", &opcionMenuP);
    } while (opcionMenuP < 1 || opcionMenuP > 7);

    return opcionMenuP;
}
