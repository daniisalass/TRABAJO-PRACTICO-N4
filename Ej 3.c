#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int  VerificarNombredeArchivo( char *A );

int VerifacionExisteOrigen( FILE *A , char *B );

int VerifacionExisteDestino( FILE *A , char *B );

void RemplazarPalabara(char *TextoLeido,char *PalabraBuscar, char *PalabraRemplazar, char *TextoMedificado);

int main(int argc, char *argv[]) {
	char NombreDeArchivoOrigen[30];
	char NombreDeArchivoDestino[30];
	int BytesLeidos;
	char PalabraABuscar[20];
	char PalabraARemplazar[20];
	char TextoLeido[1000],TextoModificado[1000];
	FILE *ArchivoOrigen;
	FILE *ArchivoDestino;

	do
	{
		printf("Ingrese el nombre del Archivo origen: ");
		gets(NombreDeArchivoOrigen);
		fflush(stdin);
	}
	while( (VerifacionExisteOrigen (ArchivoOrigen,NombreDeArchivoOrigen) != 1 ) || ( ( VerificarNombredeArchivo (NombreDeArchivoOrigen) ) !=1 ) );
	
	do
	{
		printf("Ingrese el nombre del Archivo destino: ");
		gets(NombreDeArchivoDestino); /*	*/
		fflush(stdin);
	}
	while( ((VerificarNombredeArchivo (&NombreDeArchivoDestino[0]) ) !=1 ) || (VerifacionExisteDestino (ArchivoDestino,NombreDeArchivoDestino) != 1 ));
	
	printf("Ingresar la palabara a buscar: ");
	gets(PalabraABuscar);
	
	printf("Ingresar la palabara a remplazar: ");
	char PalabraARemplazarAux[20];
	gets(PalabraARemplazar);
	puts(PalabraARemplazar);
	strcpy(PalabraARemplazarAux,PalabraARemplazar);

	if( ArchivoOrigen=fopen(NombreDeArchivoOrigen,"rb+") )
	{

		BytesLeidos=fread(TextoLeido,sizeof(char),1000,ArchivoOrigen);
		TextoLeido[BytesLeidos]='\0';
		puts(TextoLeido);

	}
	else{
		puts("Error");
	}
	fclose(ArchivoOrigen);
	RemplazarPalabara(TextoLeido,PalabraABuscar,PalabraARemplazarAux,TextoModificado);
	if(ArchivoDestino=fopen(NombreDeArchivoDestino,"wb+"))
	{	
		fwrite(TextoModificado,sizeof(char),strlen(TextoModificado),ArchivoDestino);
	}
	fclose(ArchivoDestino);
	if(ArchivoDestino=fopen(NombreDeArchivoDestino,"rb"))
	{
		fread(TextoLeido,sizeof(char),1000,ArchivoDestino);
		puts("El texto en la carpeta Destino.txt Se lee:");
		puts(TextoLeido);
	}
	fclose(ArchivoDestino);
	
	
	
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
int VerifacionExisteOrigen(FILE *A, char *B)
{	
	int ExisteOrigen=0;
	if (( A=fopen (B,"r") )!=NULL)
	{
		ExisteOrigen=1;
	}
	else {
		ExisteOrigen=0;
	}
	fclose(A);
	return(ExisteOrigen);
}
int VerifacionExisteDestino( FILE *A , char *B )
{
	int ExisteOrigen=0;
	if (( A=fopen (B,"r") )!=NULL)
	{
		ExisteOrigen=1;
	}
	else 
	{
		ExisteOrigen=0;
	}
	fclose(A);
	return(ExisteOrigen);
}

void RemplazarPalabara(char *TextoLeido,char *PalabraBuscar, char *PalabraRemplazar,char *TextoModificado)
{
	char NuevoTexto[1000];
	char *posicion;
	char *paux;
	int indice =0;
	int contador=0;
	
	posicion=strstr(TextoLeido,PalabraBuscar);/* Encontramos la primer palabra a buscar es decir su posicion */
	
	while ( posicion != NULL )
	{
		
		strncpy(NuevoTexto+indice,TextoLeido,posicion-TextoLeido);/*Copiamos cierta tramo del texto leido al Nuevo texto + indice, el tramo es el calculo de la posicion con el principio del texto */
		
		indice=indice+(posicion-TextoLeido); /*Actualizamos el indice, es decir donde esta ya la posicion de la palabra a buscar*/
		
		strcpy(NuevoTexto+indice,PalabraRemplazar);/* Copiamos la palabra a remplazar en el nuevo texto + el indice*/
		
		indice=indice+strlen(PalabraRemplazar);/* Incrementamos el indice hasta el tramo del texto modificado y la palabra a remplazar*/
		
		TextoLeido=posicion+strlen(PalabraBuscar);/* ahora movemos el puntero del texto leido hasta la primera posicion mas el largo de la palabra a buscar*/
		
		paux=posicion;/* Apuntamos un paux a la posicion para poder calcular al final de todo los caracteres que faltan imprimir, lo hacemos antes porque despues posicon es Nulo*/
		
		posicion=strstr(TextoLeido,PalabraBuscar);/*Volvemos a buscar la palabra a buscar */
		
		
/*		Ver la posicion de donde esta el Puntero y imprimir caracater por caracter hasta llegar a la posicion usar un puntero a la pimera cadena y correrla hasta llegar a la posicion*/
	}
	

	while(*paux!='\0')
	{
		paux++;
		contador++;/* contamos la cantidad de carcteres que nos falto pasar al nuevo texto*/
	}

	strncpy(NuevoTexto+indice,TextoLeido,contador);/*Copiamos el tramo de texto final que nos quedo, en el nuevo texto, donde indice se mueve hasta al final del nuevo texto, solamente copiamos el tramo que falto*/
	strcpy(TextoModificado,NuevoTexto);
	
}
