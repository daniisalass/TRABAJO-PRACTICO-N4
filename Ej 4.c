#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
struct ListadodeImagenes{
	int Codigo;
	char NombredeArchivo[MAX];
	char ExtensiondeArchivo[MAX];
	int Bytes;
	float Precio;
}stock[MAX];

void AgregarImagen(struct ListadodeImagenes *A);

void EliminarImagen(struct ListadodeImagenes *A,int i);

void ImprimirImagen(struct ListadodeImagenes *A);

void ModificarImagen(struct ListadodeImagenes *A, int j,int);

int BusquedadeImagen(struct ListadodeImagenes *A,char *B, int p, int Bytes);

void AgregarArchivo(FILE *A, int ContadorLineas);

void LeerArchivo(FILE *A, int ContadorLineas);

int main(int argc, char *argv[]) {
	FILE *ArchivoImagen;
	int i,cantidad=0,selecionador,salir=0;
	int buscarcodigo,DatoBuscar=0;
	int buscador,encontro;
	int ContadorParaArchivo=0;
	int Bytes=0,control=0;
	char busqueda[MAX];
	while(salir!=1){
	printf(" \n 1-Agregar una nueva imagen\n 2-Eliminar un elemento existente.\n 3-Modificar los datos de algún elemento. \n 4-Búsquedas por nombre de archivo, extensión, tamaño\n 5-Salir\n 6-Para Crear un Archivo(Se escribe y se Lee)");
	scanf("%d",&selecionador);
	switch(selecionador){
	case 1:
		
		printf("Cuantas imagenes desea agregar?  ");
		scanf("%d",&cantidad);
		for(i=control;i<cantidad+control;i++)
		{
			printf("IMAGEN %d",i+1);
			AgregarImagen(&stock[i]);
		}
		control=cantidad+control;
		ContadorParaArchivo=control;
		break;
		
	case 2:
		
		printf("Ingrese el Codigo de la imagen: ");
		scanf("%d",&buscarcodigo);
		for(i=0;i<cantidad+control;i++)
		{
			EliminarImagen(&stock[i],buscarcodigo);
		}
		for(i=0;i<cantidad+control;i++)
		{	
			printf("Imagen %d",i+1);
			ImprimirImagen(&stock[i]);
		}
		
		break;
		
	case 3:
		
		printf("Ingrese el Codigo de la imagen a modificar: ");
		scanf("%d",&buscarcodigo);
		for(i=0;i<cantidad+control;i++)
		{
			ModificarImagen(&stock[i],buscarcodigo,i);
		}
		break;
		
	case 4:
		
			printf("Desea como lo quiere buscar\n 1-Nombre de Archivo \n 2-Nombre de extension \n 3-Tamaño \n ");
			scanf("%d",&buscador);
			switch(buscador)
			{
				case 1:
					
					fflush(stdin);
					printf("Nombre de Archivo a buscar: ");
					gets(busqueda);
					DatoBuscar=1;
					for(i=0;i<cantidad+control;i++)
					{
						encontro=BusquedadeImagen(&stock[i],busqueda,DatoBuscar,Bytes);
							if(encontro==1)
							{
								printf("Se Encontro Imagen %d\n",i+1);
								
								ImprimirImagen(&stock[i]);
							}
					}
					break;
					
				case 2:
					
					fflush(stdin);
					printf("Nombre de extension del Archivo: ");
					gets(busqueda);
					DatoBuscar=2;
					for(i=0;i<cantidad+control;i++)
					{
						encontro=BusquedadeImagen(&stock[i],busqueda,DatoBuscar,Bytes);
							if(encontro==1)
							{
								printf("Se Encontro Imagen %d:\n",i+1);
								ImprimirImagen(&stock[i]);
							
							}
					}
					break;
					
				case 3:
					
					fflush(stdin);
					printf("Tamaño del Archivo en Bytes:");
					scanf("%d",&Bytes);
					DatoBuscar=3;
					for(i=0;i<cantidad+control;i++)
					{
						encontro=BusquedadeImagen(&stock[i],busqueda,DatoBuscar,Bytes);
							if(encontro==1)
							{	
								printf("Se Encontro Imagen %d\n",i+1);
								ImprimirImagen(&stock[i]);
							
							}
					}
					break;
					
				default :
					break;
					
			}
		break;
			
	case 5: 
		salir=1;
		break;
	case 6: 
			AgregarArchivo(ArchivoImagen,ContadorParaArchivo);
			puts("Se Creo el Archivo");
			puts("Donde se lee:");
			LeerArchivo(ArchivoImagen,ContadorParaArchivo);
			printf("\nEl contador vale:%d",ContadorParaArchivo);
	break;
		
	default: break;
	
	}
	}
	return 0;
}

void AgregarImagen(struct ListadodeImagenes *A)
{
	printf("\nCodigo: ");
	scanf("%d",&A->Codigo);
	fflush(stdin);
	printf("\nNombre de Archivo: ");
	gets(A->NombredeArchivo);
	printf("\nExtension de Archivo ej (tiff, jpg, png): ");
	gets(A->ExtensiondeArchivo);
	printf("\nBytes: ");
	scanf("%d",&A->Bytes);
	printf("\nPrecio es: ");
	scanf("%f",&A->Precio);
}

void EliminarImagen(struct ListadodeImagenes *A, int j)
{
	if(A->Codigo == j)
	{	
		
		A->Codigo = 0;
		strcpy(A->NombredeArchivo,"vacio");
		strcpy(A->ExtensiondeArchivo,"vacio");
		A->Bytes = 0;
		A->Precio = 0.0; 
	}
}

void ModificarImagen(struct ListadodeImagenes *A, int j,int i)
{	
	if (A->Codigo==j)
	{	
		printf("\nIMAGEN %d",i+i);
		printf("\nCodigo nuevo: ");
		scanf("%d",&A->Codigo);
		fflush(stdin);
		printf("\nNombre de Archivo nuevo: ");
		gets(A->NombredeArchivo);
		printf("\nExtension de Archivo nuevo ej (tiff, jpg, png): ");
		fflush(stdin);
		gets(A->ExtensiondeArchivo);
		printf("\nLa cantidad de Bytes ahora es: ");
		scanf("%d",&A->Bytes);
		printf("\nPrecio nuevo es: ");
		scanf("%f",&A->Precio);
	}
}

int BusquedadeImagen(struct ListadodeImagenes *A, char *B,int p, int Bytes)
{ 
	int encontro=0;
	switch(p){
		case 1:
				if(strcmp(B,A->NombredeArchivo)==0)
				{
						encontro=1;
				}
			break;
		case 2:
			if(strcmp(B,A->ExtensiondeArchivo)==0)
			{
				encontro=1;
			}
			break;
		case 3:
			if(Bytes==A->Bytes)
			{
				encontro=1;
			}
			break;
		default : 
			break;
	}
	return(encontro);
}

void ImprimirImagen(struct ListadodeImagenes *A)
{
	printf("\nCodigo: %d",A->Codigo);
	printf("\nNombre de Archivo: ");
	puts(A->NombredeArchivo);
	printf("\nExtension de Archivo ej (tiff, jpg, png): ");
	puts(A->ExtensiondeArchivo);
	printf("\nBytes: %d",A->Bytes);
	printf("\nPrecio es: %f",A->Precio);
}
void AgregarArchivo(FILE *A, int ContadorLineas)
{
	if((A=fopen("ArchivoImagen.txt","wb+"))!=NULL)
	{
		fwrite(&stock,sizeof(struct ListadodeImagenes),ContadorLineas,A);
	}
	fclose(A);
}
void LeerArchivo(FILE *A, int ContadorLineas)
{
	int i=0;
	if((A=fopen("ArchivoImagen.txt","rb+"))!=NULL)
	{
		fread(&stock,sizeof(struct ListadodeImagenes),ContadorLineas,A);
		for(i=0;i<ContadorLineas;i++)
		{
		ImprimirImagen(&stock[i]);
		}
	}
	fclose(A);
}
