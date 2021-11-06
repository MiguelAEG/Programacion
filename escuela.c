#include <stdio.h> 
#include <conio.h>
#include <time.h>
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
} persona[100];

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

int menuPrincipal();
void matricula(int);
void nombre(int);
void carrera(int);
void semestre(int);
void fecha_nac(int);
void correo(int);
void telefono(int);
void tiempo();

int main()
{
    int opcion, opc2;
 	int i = 0;		
    
    while ((opcion = menuPrincipal()) != 7) {
        switch(opcion){
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
                    case 1:
                        matricula(i);
                        break;
                    case 2: 
                        nombre(i);
                        break;
                    case 3: 
                        carrera(i);
                        break;
                    case 4: 
                        semestre(i);
                        break;
                    case 5: 
                        fecha_nac(i);
                        break;
                    case 6: 
                        correo(i);
                        break;
                    case 7: 
                        telefono(i);
                        break;
                }

                break;

            case 2:
                //Menu materias
                printf("\n1.-Clave\n2.-Nombre\n3.-Semestre\n");

                do {            
                    printf("Seleccione la opcion -> ");
                    scanf("%d", &opc2);
                } while (opc2 < 1 || opc2 > 3);

                switch (opc2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                }

                break;

            case 3:
                //Menu profesores
                printf("\n1.-Numero\n2.-Nombre\n3.-Coordinacion\n4.-Fecha de nacimiento\n 5.-Correo\n6.-Telefono");

                do {
                    printf("Selecciona la opcion -> ");
                    scanf("%d", &opc2);
                } while (opc2 < 1 || opc2 > 6);

                switch (opc2) {
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
                }

                break;

            case 4:
                // Menu grupos
                printf("\n1.-Numero\n2.-Semestre\n3.-Numero de materia\n4.-Clave del profesor\n");

                do {
                    printf("Selecciona la opcion -> ");
                    scanf("%d", &opc2);
                } while (opc2 < 1 || opc2 > 4);

                switch (opc2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }

                break;

            case 5:
                // Menu inscripcion
                printf("\n1.-Numero\n2.-Matricula\n"); 

                do {
                    printf("Selecciona la opcion -> ");
                    scanf("%d", &opc2);
                } while (opc2 < 1 || opc2 > 2);
                
                switch (opc2) {
                    case 1:
                        break;
                    case 2:
                        break;
                }

                break;
            case 6:
                // menu reportes
                printf("\n1.-Listado de alumnos por carrera\n2.-Listado de materias que imparte un profesor\n3.-Listado de grupos por fecha\n4.-Listado de inscripcion por grupo\n5.- Generar archivo de alumnos\n6.-Generar archivo de profesores\n7.-Mostrar archivo\n8.-Salir\n");

                do {
                    printf("Selecciona la opcion -> ");
                    scanf("%d", &opc2);
                } while (opc2 < 1 || opc2 > 8);

                switch (opc2) {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                }

                break;

        }
    }

    return 0;
}

int menuPrincipal()
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

// Funciones para los datos de alumnos
void matricula(int i)
{
	do
	{
		printf("\nIngrese la matricula del alumno %d: ", i+1);
		scanf("%ld", &persona[i].matricula);
	} while(persona[i].matricula <= 0);

  	return;
}

void nombre(int i)
{
	int j= 0;
	int cont = 0;
	do
	{
		printf("Ingrese el nombre del alumno %d:", i+1);
		fflush(stdin);
		gets(persona[i].nombre);
		for(j=0; persona[i].nombre != '\0'; j++) // FIXME: nononononono esto esta mal muy muy mal aaaaaaaaaaaaaaaa
    	{
	    	cont=cont + 1;
    	}
	}while(cont<1||cont>40);

	return;
}

void carrera(int i)
{
	printf("Ingrese la carrera del alumno %d:", i+1);
	fflush(stdin);
	gets(persona[i].carrera);
	return;
}

void semestre(int i)
{
	do
	{
		printf("Ingrese el semestre del alumno %d:", i+1);
		scanf("%d", &persona[i].semestre);
	} while (persona[i].semestre < 1 || persona[i].semestre > 10);
}

void fecha_nac(int i)
{
	do
	{
		printf("Ingrese el dia de nacimiento del alumno %d:", i+1);
		scanf("%d", &persona[i].fecha_nac.dd);
	}while (persona[i].fecha_nac.dd < 1 || persona[i].fecha_nac.dd > 31);

	do
	{
		printf("Ingrese el mes de nacimiento del alumno %d:", i+1);
		scanf("%d", &persona[i].fecha_nac.mmm);
	} while (persona[i].fecha_nac.mmm < 1 || persona[i].fecha_nac.mmm > 12);

	do
	{
		printf("Ingrese el a%co de nacimiento del alumno %d", 164, i+1); // Aqui si fue necesario usar esto xd
		scanf("%d", &persona[i].fecha_nac.aaaa);
	} while (persona[i].fecha_nac.aaaa <= 0 || persona[i].fecha_nac.aaaa > 2021);
}
void correo(int i)
{/* FIXME: usar strchr()
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

	if(band == 'F') // FIXME: pasar esto a 1 y 0
	{
		printf("El correo ingresado no lleva @ ");
	} */
}

void telefono(int i)
{
	do
	{
		printf("Ingrese el telefono del alumno %d:", i+1);
		scanf("%ld", &persona[i].telefono);
	} while (persona[i].telefono < 10); // FIXME: esta validacion no me parece correcta...
}

void tiempo()
{ //TODO: convertir esto en algo que se pueda guardar en la estructura

    time_t t; //TODO: nombres de variables mas descriptivos
    struct tm *tm;
    char fechayhora[100];

    t = time(NULL);
    tm = localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y", tm);
    printf("Hoy es: %s\n", fechayhora);
}
