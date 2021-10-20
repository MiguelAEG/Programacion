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

    }


    return 0;
}
