#include <stdio.h> 
//#include "limpieza.h" 
//#define fflush(stdin) limpieza()

struct fecha
{
    int dia, mes, año;
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
    
    
    return 0;
}