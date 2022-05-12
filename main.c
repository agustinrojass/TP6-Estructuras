#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//FALTA 7 - 8 - 9
typedef struct
{
    int matricula;
    char nombre[30];
    char sexo; //m|f
} stalumno;

void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();

int carga(stalumno alumno[]);
void cargaAlumno(stalumno alumno[],int i);
void muestra(stalumno alumno[],int cantidad);
void muestraAlumno(stalumno alumno[],int i);
void muestraAlumnoPorMatricula(stalumno alumno[],int cantidad);
int busquedaMatricula(stalumno alumno[],int cantidad);
void ordenSeleccion(stalumno alumno[],int cantidad);
int posicionMenor(stalumno alumno[],int i,int cantidad);
void muestraAlumnoPorSexo(stalumno alumno[],int cantidad);
char busquedaSexo(stalumno alumno[],int cantidad);
void ordenInsercion(stalumno alumno[],int validos);
void insertar(stalumno alumno[],int i);

int main()
{
    int ejercicio;
    do
    {
        do
        {
            printf("EJERCICIOS                                                 INGRESAR");
            printf("\nEJERCICIO 1  ...................................................  1");
            printf("\nEJERCICIO 2  ...................................................  2");
            printf("\nEJERCICIO 3  ...................................................  3");
            printf("\nEJERCICIO 4  ...................................................  4");
            printf("\nEJERCICIO 5  ...................................................  5");
            printf("\nEJERCICIO 6  ...................................................  6");
            printf("\nEJERCICIO 7  ...................................................  7");
            printf("\nEJERCICIO 8  ...................................................  8");
            printf("\nEJERCICIO 9  ...................................................  9\n");
            printf("\nIngrese el ejercicio: ");
            scanf("%i",&ejercicio);
        }
        while(ejercicio!=1 && ejercicio!=2 && ejercicio!=3 && ejercicio!=4 && ejercicio!=5 && ejercicio!=6 && ejercicio!=7 && ejercicio!=8 && ejercicio!=9 && ejercicio!=0);
        if(ejercicio!=0)
        {
            printf("\nEJERCICIO %i\n\n",ejercicio);
        }
        switch(ejercicio)
        {
            case 1:
            {
                ejercicio1();
            }
            break;
            case 2:
            {
                ejercicio2();
            }
            break;
            case 3:
            {
                ejercicio3();
            }
            break;
            case 4:
            {
                ejercicio4();
            }
            break;
            case 5:
            {
                ejercicio5();
            }
            break;
            case 6:
            {
                ejercicio6();
            }
            break;
            case 7:
            {
                ejercicio7();
            }
            break;
            case 8:
            {
                ejercicio8();
            }
            break;
            case 9:
            {
                ejercicio9();
            }
            break;
        }
    }
    while(ejercicio!=0);
    printf("\nTP6 TERMINADO\n");
    printf("\nVersion 1.0\n");
    return 0;
}

int carga(stalumno alumno[])                                                                //FUNCION CARGA
{
    int i;
    char continuar='s';
    for(i=0;i<30 && continuar=='s';i++)
    {
        cargaAlumno(alumno,i);                                                              //FUNCION CARGAALUMNO
        printf("Desea continuar? (s|n): ");
        fflush(stdin);
        scanf("%c",&continuar);
        printf("\n");
    }
    return i;
}
void cargaAlumno(stalumno alumno[],int i)                                                   //FUNCION CARGAALUMNO
{
    printf("Ingrese la matricula del alumno: ");
    scanf("%i",&alumno[i].matricula);
    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    gets(alumno[i].nombre);
    printf("Ingrese el sexo del alumno (m|f): ");
    fflush(stdin);
    scanf("%c",&alumno[i].sexo);
}
void muestra(stalumno alumno[],int cantidad)                                                //FUNCION MUESTRA
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        muestraAlumno(alumno,i);                                                            //FUNCION MUESTRAALUMNO
    }
}
void muestraAlumno(stalumno alumno[],int i)                                                 //FUNCION MUESTRAALUMNO
{
    printf(" ________________________________________ \n");
    printf("| LEGAJO DE ALUMNO                       |\n");
    printf("|________________________________________|\n");
    printf("| MATRICULA: %-27i |\n",alumno[i].matricula);
    printf("|________________________________________|\n");
    printf("| NOMBRE: %-30s |\n",alumno[i].nombre);
    printf("|________________________________________|\n");
    if(alumno[i].sexo=='m')
    {
        printf("| SEXO: Masculino                        |\n");
        printf("|________________________________________|\n");
    }
    else
    {
        printf("| SEXO: Femenino                         |\n");
        printf("|________________________________________|\n");
    }
    printf("\n");
}
void muestraAlumnoPorMatricula(stalumno alumno[],int cantidad)                              //FUNCION MUESTRAALUMNOPORMATRICULA
{
    int i;
    i=busquedaMatricula(alumno,cantidad);                                                   //FUNCION BUSQUEDAMATRICULA
    muestraAlumno(alumno,i);
}
int busquedaMatricula(stalumno alumno[],int cantidad)                                       //FUNCION BUSQUEDAMATRICULA
{
    int i=0,flag=0,busqueda;
    printf("Ingrese la matricula que desea buscar: ");
    scanf("%i",&busqueda);
    while(i<cantidad && flag==0)
    {
        if(busqueda==alumno[i].matricula)
        {
            flag=1;
        }
        i++;
    }
    return i-1;
}
void ordenSeleccion(stalumno alumno[],int cantidad)                                         //INICIO FUNCION ORDENSELLECION
{
    int i=0,posicion,auxM;
    char auxN[1][30],auxS;
    while (i<cantidad-1)
    {
        posicion=posicionMenor(alumno,i,cantidad);                                          //FUNCION POSICIONMENOR
        auxM=alumno[posicion].matricula;
        strcpy(auxN[0],alumno[posicion].nombre);
        auxS=alumno[posicion].sexo;

        alumno[posicion].matricula=alumno[i].matricula;
        strcpy(alumno[posicion].nombre,alumno[i].nombre);
        alumno[posicion].sexo=alumno[i].sexo;

        alumno[i].matricula=auxM;
        strcpy(alumno[i].nombre,auxN[0]);
        alumno[i].sexo=auxS;

        i++;
    }
}
int posicionMenor(stalumno alumno[],int i,int cantidad)                                     //INICIO FUNCION POSICIONMENOR
{
    int posicion=i;
    int j=i+1;
    int menor=alumno[i].matricula;
    while (j<cantidad)
    {
        if(menor>alumno[j].matricula)
        {
            menor=alumno[j].matricula;
            posicion=j;
        }
        j++;
    }
    return posicion;
}
void muestraAlumnoPorSexo(stalumno alumno[],int cantidad)                                   //FUNCION MUESTRAALUMNOPORMATRICULA
{
    int i;
    char busqueda;
    busqueda=busquedaSexo(alumno,cantidad);                                                 //FUNCION BUSQUEDAMATRICULA

    for(i=0;i<cantidad;i++)
    {
        if(busqueda==alumno[i].sexo)
        {
            muestraAlumno(alumno,i);
        }
    }

}
char busquedaSexo(stalumno alumno[],int cantidad)                                           //FUNCION BUSQUEDAMATRICULA
{
    char busqueda;
    printf("Ingrese el sexo que desea mostrar (m|f): ");
    fflush(stdin);
    scanf("%c",&busqueda);
    return busqueda;
}
void ordenInsercion(stalumno alumno[],int cantidad)                                         //FUNCION ORDENINSERCION
{
    int i=0;
    while (i<cantidad)
    {
        insertar(alumno,i);                                                                 //FUNCION INSERTAR
        i++;
    }
}
void insertar(stalumno alumno[],int i)                                                      //FUNCION INSERTAR
{
    int valorM=alumno[i+1].matricula;
    char valorN[1][30];
    strcpy(valorN[0],alumno[i+1].nombre);
    char valorS=alumno[i+1].sexo;
    while(i>=0 && valorM<alumno[i].matricula)
    {
        alumno[i+1].matricula=alumno[i].matricula;
        strcpy(alumno[i+1].nombre,alumno[i].nombre);
        alumno[i+1].sexo=alumno[i].sexo;
        i--;
    }
    alumno[i+1].matricula=valorM;
    strcpy(alumno[i+1].nombre,valorN[0]);
    alumno[i+1].sexo=valorS;
}

void ejercicio1()
{
    //Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    muestra(alumno,cantidad);                                                               //FUNCION MUESTRA
    printf("\n");
}
void ejercicio2()
{
    //Hacer una funcion que muestre un arreglo de alumnos por pantalla.
    //Modularizar.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    muestra(alumno,cantidad);                                                               //FUNCION MUESTRA
    printf("\n");
}
void ejercicio3()
{
    //Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula.
    //Modularizar.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    muestraAlumnoPorMatricula(alumno,cantidad);                                             //FUNCION MUESTRAALUMNOPORMATRICULA
    printf("\n");
}
void ejercicio4()
{
    //Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion.
    //El criterio de ordenacion es el numero de matricula.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    ordenSeleccion(alumno,cantidad);                                                        //FUNCION ORDENSELECCION
    muestra(alumno,cantidad);                                                               //FUNCION MUESTRA
    printf("\n");
}
void ejercicio5()
{
    //Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envía por parzmetro).
    //Modularizar.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    muestraAlumnoPorSexo(alumno,cantidad);                                                  //FUNCION MUESTRAALUMNOPORSEXO
    printf("\n");
}
void ejercicio6()
{
    //Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato, conservando el orden.
    int cantidad;
    stalumno alumno[30];
    cantidad=carga(alumno);                                                                 //FUNCION CARGA
    ordenSeleccion(alumno,cantidad);                                                        //FUNCION ORDENSELECCION
    muestra(alumno,cantidad);                                                               //FUNCION MUESTRA
    cargaAlumno(alumno,cantidad);                                                           //FUNCION CARGAALUMNO
    ordenInsercion(alumno,cantidad+1);                                                      //FUNCION ORDENINSERCION
    muestra(alumno,cantidad+1);                                                             //FUNCION MUESTRA
}
void ejercicio7()
{
    //Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
    //El criterio de ordenación es el nombre.
}
void ejercicio8()
{
    //Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado (se envia por parametro) que tiene un arreglo de alumnos.
}
void ejercicio9()
{
    //Hacer una funcion principal que pruebe el funcionamiento de todos los incisos anteriores, con un menu de opciones para poder ejecutar todas las funciones requeridas.
    //Tengan presente la correcta declaracion y el ambito de variables.
}
