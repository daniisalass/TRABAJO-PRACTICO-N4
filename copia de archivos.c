#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int  VerificarNombredeArchivo(char *A);

int main(int argc, char *argv[]) 
{
	char cadenaauxiliar[200];
	char NombreDeArchivo[25];
	char CadenaInicial[200];
	char Destino[25]="A";
	FILE *archivo;
	FILE *archivo1;
	do
	{
		printf("Ingrese el nombre del Archivo: ");
		gets(NombreDeArchivo);
		fflush(stdin);
	}
	while(VerificarNombredeArchivo(&NombreDeArchivo[0])!=1);
	if((archivo=fopen(NombreDeArchivo,"w+"))!=NULL)
	{
		puts("\nIngrese el texto que desea escribir en el archivo Origen: ");
		gets(CadenaInicial);
		fflush(stdin);
		fprintf(archivo,"%s",CadenaInicial);
	}
	
	fclose(archivo);
	strcat(Destino,NombreDeArchivo);
	
	if((archivo=fopen(NombreDeArchivo,"r")) != NULL)
	{
		fgets(cadenaauxiliar,200,archivo);
		printf("\nSe lee desde el archivo: %s",cadenaauxiliar);
		archivo1=fopen(Destino,"w");
		if(archivo1 !=NULL)
		{
			fprintf(archivo1,"%s",cadenaauxiliar);
		}
		else
		{
			printf("\nProblemas para abrir el archivo");
		}

	}
	else
	{
		printf("\nProblemas para abrir el archivo");
	}
	fclose(archivo);
	fclose(archivo1);
	
	return 0;
}
int  VerificarNombredeArchivo(char *A)
{
	char Aux[30],Aux2[20];
	int i=0;
	char *CadAux=&A[0];
	char *VerfPunto=A;
	int ExistePunto=0;
	int VerificacionDeNombre=0,verificacion=0;
	int VerificacionDeExtension=0;
	while(*VerfPunto!='\0')
	{
		if(*VerfPunto == '.')
		{
			ExistePunto=1;
		}
		VerfPunto++;
	}
	if(ExistePunto == 1)
	{
		while(*A!='.')
		{
			Aux[i]=*A;
			i++;
			A++;
			Aux[i]='\0';
		}
		A++;
		i=0;
		while(*A!='\0')
		{
			Aux2[i]=*A;
			A++;
			i++;
			Aux2[i]='\0';
		}
		while(*CadAux!='\0')
		{
			if(*CadAux=='[' || *CadAux=='{'||*CadAux==','||*CadAux=='-'||*CadAux=='*'||*CadAux=='?'||*CadAux=='/'||*CadAux==';'||*CadAux=='+'||*CadAux=='!'||*CadAux=='$'||*CadAux=='%'|| *CadAux=='*'){
				
				VerificacionDeNombre=0;
				break;
			}
			else
			{
				VerificacionDeNombre=1;
			}
			
			CadAux++;
		}
		if(strcmp(Aux2,"txt")==0)
		{
			VerificacionDeExtension=1;
		}
		else 
		{
			if(strcmp(Aux2,"c")==0)
			{
				VerificacionDeExtension=1;
			}
			else
			{
				if(strcmp(Aux2,"cpp")==0)
				{
					VerificacionDeExtension=1;
				}
				else
				{
					VerificacionDeExtension=0;
				}
			}
		}
		
		if( (VerificacionDeExtension==1) && (VerificacionDeNombre ==1) )
		{
			verificacion=1;
		}
		else 
		{
			puts("Vuelva a ingresarlo correctamente \n");
		}
	}
	return(verificacion);
}

