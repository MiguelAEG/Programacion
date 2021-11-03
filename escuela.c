#include <stdio.h> 
#include<conio.h>

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
}persona[100];

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
    int opc, opc2;

    printf("\nMenu principal\n"); 
    printf("1.-Alumnos\n2.-Materias\n3.-Profesor\n4.-Grupo\n5.-Inscripcion\n6.-Reportes\n7.-Salir\n");

    do
    {
        printf("Seleccione la opción\n-> ");
        scanf("%d", &opc);
    } while (opc < 1 || opc > 7);
 	
 	int i = 0;		
    
    switch(opc){
        case 1:
                // menu alumnos 
                printf("1.-Matricula\n2.-Nombre\n3.-Carrera\n4.-Semestre\n5.-Fecha de Nacimiento \n6.-Correo\n7.-Telefono\n");
                do
    			{
        			printf("Seleccione la opcion-> ");
        			scanf("%d", &opc2);
    			} while (opc2 < 1 || opc2 > 7);
    			
    			switch(opc2)
    			{
    				case 1: Matricula(i);
    					break;
    				case 2: Nombre(i);
    					break;
    				case 3: Carrera(i);
    					break;
    				case 4: Semestre(i);
    				    break;
    				case 5: Fecha_nac(i);
    				    break;
    				case 6: Correo(i);
    				    break;
    				case 7: Telefono(i);
    				default: break;
			    }
			
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

    return 0;
}
//Funciones para los datos de alumnos
void Matricula( int i)
{
	
	do
	{
		printf("\nIngrese la matricula del alumno %d: ", i+1);
		scanf("%ld", &persona[i].matricula);
	}while(persona[i].matricula <= 0);
  	return;
}

void Nombre( int i)
{
	int j= 0;
	int cont = 0;
	do
	{
		printf("Ingrese el nombre del alumno %d:", i+1);
		fflush(stdin);
		gets(persona[i].nombre);
		for(j=0; persona[i].nombre != '\0';j++)
    	{
	    	cont=cont + 1;
    	}
	}while(cont<1||cont>40);

	return;
}

void Carrera(int i)
{
	printf("Ingrese la carrera del alumno %d:", i+1);
	fflush(stdin);
	gets(persona[i].carrera);
	return;
}

void Semestre(int i)
{
	do
	{
		printf("Ingrese el semestre del alumno %d:", i+1);
		scanf("%d", &persona[i].semestre);
	}while(persona[i].semestre<1||persona[i].semestre>10);
	return;
}

void Fecha_nac(int i)
{
	do
	{
		printf("Ingrese el dia de nacimiento del alumno %d:", i+1);
		scanf("%d", &persona[i].fecha_nac.dd);
	}while(persona[i].fecha_nac.dd<1||persona[i].fecha_nac.dd>31);
	do
	{
		printf("Ingrese el mes de nacimiento del alumno %d:", i+1);
		scanf("%d", &persona[i].fecha_nac.mmm);
	}while(persona[i].fecha_nac.mmm<1||persona[i].fecha_nac.mmm>12);
	do
	{
		printf("Ingrese el a�o de nacimiento del alumno %d", i+1);
		scanf("%d", &persona[i].fecha_nac.aaaa);
	}while(persona[i].fecha_nac.aaaa<=0||persona[i].fecha_nac.aaaa>2021);
	return;
}
void Correo(int i )
{
	char dato='@', band;
	int j=0;

	printf("Ingrese el correo electronico del alumno %d:", i+1);
	fflush(stdin);
	gets(persona[i].correo);
	
	while((band == 'F') && (j<40))
	{
		if(persona[i].correo == dato)
		{
			band= 'V';
		}
		i++;
	}
	if(band == 'F')
	{
		printf("El correo ingresado no lleva @ ");
	}
	return;
}

void Telefono(int i)
{
	do
	{
		printf("Ingrese el telefono del alumno %d:", i+1);
		scanf("%ld", &persona[i].telefono);
	}while(persona[i].telefono<10);
	return;
}
