#include <stdio.h> 
//#include "limpieza.h" 
//#define fflush(stdin) limpieza()

struct Alumn{
 long int Matricula;
 char nombre[40];
 char carrera[40];
 int semestre;
 int fecha_nac;
 char correo[40];
 int telefono;
};

struct materia{
 int clave;
 char nombre[40];
 int semestre;
};

struct profesor{
 int num_empleado;
 char nombre[40];
 int coordinacion;
 int fecha_nac;
 char correo[40];
 int telefono;
};

struct fecha_nac{
 int dia;
 int mes;
 int año;
};

struct grupo{
 int numero;
 int semestre;
 int clave;
 //Fecha actual
 int N_empleado;
};

struct inscripcion{
 int num;
 int matricula;
 //Fecha actual
 
};
int main()
{
    
    
    return 0;
};
