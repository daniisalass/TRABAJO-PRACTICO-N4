#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int  VerificarNombredeArchivo(char *A);

int main(int argc, char *argv[]) {
	FILE *Archivo;
	char NombreDeArchivo[50];
	char TextoArchivo[150];
	char TextoLeido[150];
	int selecionador,salir=0;
	do
	{
	printf("Ingrese el nombre del Archivo: ");
	gets(NombreDeArchivo);
	fflush(stdin);
	}
	while(VerificarNombredeArchivo(&NombreDeArchivo[0])!=1);
	while(salir!=1){
	printf("\nQue desea hacer ? \n1-Ingresar texto\n2-Mostrar su contenido\n3-Salir\n");
	scanf("%d",&selecionador);
	fflush(stdin);
	switch(selecionador)
	{
	case 1:
			if((Archivo=fopen(NombreDeArchivo,"a"))!=NULL)
			{
				puts("Se creo exitosamente");
				printf("Ingrese el texto a escribir en el Archivo''%s'': ",NombreDeArchivo);
				gets(TextoArchivo);
				fprintf(Archivo,TextoArchivo);
			}
			fclose(Archivo);
			break;
			
		break;
	case 2:
		if((Archivo=fopen(NombreDeArchivo,"r"))!=NULL)
		{
			printf("\nEl texto leido''%s'': ",NombreDeArchivo);
			fgets(TextoLeido,100,Archivo);
			puts(TextoLeido);
		}
		fclose(Archivo);
		break;
	case 3: 
		salir=1;
		break;
	default: 
		break;
	}
	}
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
	int VerficacionDeExtension=0;
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
				VerficacionDeExtension=1;
			}
			else 
			{
				if(strcmp(Aux2,"c")==0)
				{
					VerficacionDeExtension=1;
				}
				else
				{
					if(strcmp(Aux2,"cpp")==0)
					{
						VerficacionDeExtension=1;
					}
					else
					{
						VerficacionDeExtension=0;
					}
				}
			}

			if( (VerficacionDeExtension==1) && (VerificacionDeNombre ==1) )
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

