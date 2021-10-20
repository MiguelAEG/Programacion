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
<<<<<<< HEAD
    int resp;
    printf("Menu principal \n"); 
    printf("1.-Alumnos\n2.-Materias\n3.-Profesor\n4.-Grupo\n5.-Inscripcion\n6.-Reportes\n7.-Salir\n");

    do {
        printf("Ingrese el codigo: \n");
        scanf("%d", &resp);
    }while (resp<1 &&resp>7);
    
    switch(resp){
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

=======
    int opc;

    printf("\nMenu principal\n"); 
    printf("1.-Alumnos\n2.-Materias\n3.-Profesor\n4.-Grupo\n5.-Inscripcion\n6.-Reportes\n7.-Salir\n");

    do
    {
        printf("Seleccione la opción\n-> ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 7);

    while (opc != 7) {
        switch(opc){
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

        printf("\nMenu principal\n"); 
        printf("1.-Alumnos\n2.-Materias\n3.-Profesor\n4.-Grupo\n5.-Inscripcion\n6.-Reportes\n7.-Salir\n");

        do
        {
            printf("Seleccione la opción\n-> ");
            scanf("%d", &opc);
        } while (opc < 1 || opc > 7);
>>>>>>> 4d6fc07d393fc2430f408106fdbe6add687de565
    }

    return 0;
}
