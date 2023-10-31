#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
struct BaseDePuntos
{
	float X;
	float Y;
}Puntos[101];

struct FuncionLineal
{
	float X;
	float Y;
}Puntos_Recta[101];

void CargarXCuadrado(struct BaseDePuntos *A,float B);
void ImprimirBaseDePuntos(struct BaseDePuntos *A);
void ImprimirFuncionLineal(struct FuncionLineal *A);
void GenerarRecta(struct FuncionLineal *A, float M, float B);
void InterseccionFunciones(struct BaseDePuntos *A,struct FuncionLineal *B);
void EscribirArchivo(FILE *A);
void LeerArchivo(FILE *A);
int main(int argc, char *argv[]) 
{
	FILE *ArchivoFuncion;
	int i;
	int bandera=0;
	float x=-5;
	float m,b;
	printf("\n La recta tiene la forma y=mx+b, donde:\nm=pendiente \nb=ordenada al origen\n");
	printf("Ingrese la pendiente: ");
	scanf("%f",&m);
	printf("\nIngrese la ordenada al origen: ");
	scanf("%f",&b);
	for(i=0;i<101;i++)
	{	
		CargarXCuadrado(&Puntos[i],x);
		x=x+0.1;
	}
	GenerarRecta(&Puntos_Recta[0],m,b);
	ImprimirFuncionLineal(&Puntos_Recta[0]);
	ImprimirBaseDePuntos(&Puntos[0]);
	for(i=0;i<101;i++)
	{
		if(Puntos[i].Y==Puntos_Recta[i].Y)
		{
			puts("\nCorta a la funcion entre los siguientes puntos:");
			printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos_Recta[i].Y);
			bandera=1;
		}
		else
		{
			if( (Puntos[i].Y < Puntos_Recta[i].Y) && (Puntos[i+1].Y > Puntos_Recta[i+1].Y))
			{
				bandera=1;
				puts("\nCorta a la funcion entre los siguientes puntos:");
				printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos[i].Y);
				printf("\nEje x:%.2f Eje y:%.2f",Puntos[i+1].X,Puntos[i+1].Y);
			}
			if((Puntos[i].Y > Puntos_Recta[i].Y) && (Puntos[i+1].Y < Puntos_Recta[i+1].Y))
			{
				bandera=1;
				puts("\nCorta a la funcion entre los siguientes puntos:");
				printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos[i].Y);
				printf("\nEje x:%.2f Eje y:%.2f",Puntos[i+1].X,Puntos[i+1].Y);
			}
		}
	}
	if(bandera==0)
	{
		puts("\nLa funcion lineal no corta a la funcion cuadratica entre x=-5 y x=5");
	}
	puts("\nSe creo el archivo:");
	EscribirArchivo(ArchivoFuncion);
	puts("Se leyo que:");
	LeerArchivo(ArchivoFuncion);
	return 0;
}

void CargarXCuadrado(struct BaseDePuntos *A, float B)
{	
		A->Y=pow(B,2);
		A->X=B;
	
}
void ImprimirBaseDePuntos(struct BaseDePuntos *A)
{
	float x=-5;
	while(x<=5)
	{
		printf("x=%f y=%f \n",A->X,A->Y);
		x=x+0.1;
		A++;
	}
}
void ImprimirFuncionLineal(struct FuncionLineal *A)
{
	float x=-5;
	while(x<=5)
	{
		printf("x=%f y=%f \n",A->X,A->Y);
		x=x+0.1;
		A++;
	}
}

void GenerarRecta(struct FuncionLineal *A, float M, float B)
{
	float x=-5;
	while(x<=5){
		A->Y=M*x+B;
		A->X=x;
		x=x+0.1;
		A++;
	}
}
void EscribirArchivo(FILE *A)
{
	if((A=fopen("Funcion.txt","wb+"))!=NULL)
	{
		fwrite(&Puntos,sizeof(struct BaseDePuntos),101,A);
		fwrite(&Puntos_Recta,sizeof(struct FuncionLineal),101,A);
	}
	fclose(A);
}
void LeerArchivo(FILE *A)
{
	int i=0;
	int bandera=0;
	if((A=fopen("Funcion.txt","rb+"))!=NULL)
	{	
		fread(&Puntos,sizeof(struct BaseDePuntos),101,A);
		fread(&Puntos_Recta,sizeof(struct FuncionLineal),101,A);

		for(i=0;i<101;i++)
		{
			if(Puntos[i].Y==Puntos_Recta[i].Y)
			{
				puts("\nCorta a la funcion entre los siguientes puntos:");
				printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos_Recta[i].Y);
				bandera=1;
			}
			else
			{
				if( (Puntos[i].Y < Puntos_Recta[i].Y) && (Puntos[i+1].Y > Puntos_Recta[i+1].Y))
				{
					bandera=1;
					puts("\nCorta a la funcion entre los siguientes puntos:");
					printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos[i].Y);
					printf("\nEje x:%.2f Eje y:%.2f",Puntos[i+1].X,Puntos[i+1].Y);
				}
				if((Puntos[i].Y > Puntos_Recta[i].Y) && (Puntos[i+1].Y < Puntos_Recta[i+1].Y))
				{
					bandera=1;
					puts("\nCorta a la funcion entre los siguientes puntos:");
					printf("Eje x:%.2f Eje y:%.2f",Puntos[i].X,Puntos[i].Y);
					printf("\nEje x:%.2f Eje y:%.2f",Puntos[i+1].X,Puntos[i+1].Y);
				}
			}
		}
		if(bandera==0)
		{
			puts("\nLa funcion lineal no corta a la funcion cuadratica entre x=-5 y x=5");
		}
			
	}
	fclose(A);
}