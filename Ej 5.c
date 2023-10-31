#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

struct BaseDeSensores
{
	char MarcaSensor[15];
	char TipoSensor[15];
	char UnidadMedida[15];
	
}SensorTipo[2];

struct Mediciones
{
	char Fecha[15];
	char Hora[15];
	struct BaseDeSensores Sensor;
	float ValorMedido;
	char Comentarios[150];
}MedidasLaboratorio[MAX];

//DECLARO LAS FUNCIONES A USAR//

void AgregarMedicion(struct Mediciones *A);

void ImprimirMediciones(struct Mediciones *A);

void EliminarMediciones(struct Mediciones *A);

void ModificarMediciones(struct Mediciones *A);

int BusquedaPorFecha(struct Mediciones *A, char *B);

int BusquedaPorHora(struct Mediciones *A, char *B);

int BusquedaPorSensor(struct Mediciones *A, int B);

int BusquedaPorValorMedido(struct Mediciones *A, float B);

void EscribirArchivo(FILE *A,int Contador);

void LeerArchivo(FILE *A, int Contador);

int main(int argc, char *argv[]) {
	int i,selector=0,salir=0,Cantidad=0;
	int NroMedicion;
	FILE *ArchivoMediciones;
	char BuscadorLetras[15];
	int buscador=0,BuscadorSensor=0,control=0;
	float BuscadorValorMedido;
	// DATOS YA CARGADOS
	//==================
	
	strcpy(SensorTipo[0].MarcaSensor,"Sony");
	strcpy(SensorTipo[0].TipoSensor,"HPR");
	strcpy(SensorTipo[0].UnidadMedida,"Milimetros");
	
	strcpy(SensorTipo[1].MarcaSensor,"Philips");
	strcpy(SensorTipo[1].TipoSensor,"JPG");
	strcpy(SensorTipo[1].UnidadMedida,"Decimetros");
	
	strcpy(SensorTipo[2].MarcaSensor,"Liliana");
	strcpy(SensorTipo[2].TipoSensor,"PKH");
	strcpy(SensorTipo[2].UnidadMedida,"Nanometros");
	
	// =================
	while(salir!=1)
	{
		printf("       MENU PRINCIPAL \n 1-Agregar una nueva medicion.\n 2-Eliminar medicones existentes.\n 3-Modificar mediciones existentes. \n 4-Busquedas por fecha,sensor o valor medido. \n 5-Salir. \n 6-Crear un Archivo (Se guarda y lee)\n");
		scanf("%d",&selector);
		fflush(stdin);
		switch(selector)
		{
			case 1:
				printf("Cuantas mediciones desea agreagar? -> ");
				scanf("%d",&Cantidad);
				fflush(stdin);
					for(i=control;i<Cantidad+control;i++)
					{	
						printf("\n\t========MEDICION %d========\n",i+1);
						AgregarMedicion(&MedidasLaboratorio[i]);
					}
					
					for(i=0;i<Cantidad+control;i++)
					{	
						printf("\n\t========MEDICION %d========\n",i+1);
						ImprimirMediciones(&MedidasLaboratorio[i]);
						
					}
					control=Cantidad+control;
				break;
				
			case 2:
				for(i=0;i<control;i++)
				{	
					printf("\n\t========MEDICION %d========\n",i+1);
					ImprimirMediciones(&MedidasLaboratorio[i]);
					
				}
				printf("\nIngrese que medicon desea eliminar: ");
				scanf("%d",&NroMedicion);
				EliminarMediciones(&MedidasLaboratorio[NroMedicion-1]);
				break;
				
			case 3:
				
				for(i=0;i<control;i++)
				{	
					printf("\n\t========MEDICION %d========\n",i+1);
					ImprimirMediciones(&MedidasLaboratorio[i]);
					
				}
				printf("Que mediocion desea modificar?");
				scanf("%d",&NroMedicion);
				fflush(stdin);
				ModificarMediciones(&MedidasLaboratorio[NroMedicion-1]);
				break;
				
			case 4:
				printf("Porque lo desea buscar ?\n1-Fecha.\n2-Hora.\n3-Sensor.\n4-Valor Medido.\n5-Volver.\n");
				scanf("%d",&buscador);
				fflush(stdin);
				switch(buscador)
				{
					case 1:
						printf("Ingrese la fecha a buscar(dia/mes/año): ");
						gets(BuscadorLetras);
						fflush(stdin);
						for(i=0;i<control;i++)
						{
							if((BusquedaPorFecha(&MedidasLaboratorio[i],BuscadorLetras))==1)
							{
								printf("\n    SE ENCONTRO LA MEDICION N°%d",i+1);
								ImprimirMediciones(&MedidasLaboratorio[i]);
							}
						}
						break;
					case 2:
						printf("Ingrese la hora a buscar(hora:minutos): ");
						gets(BuscadorLetras);
						fflush(stdin);
						for(i=0;i<control;i++)
						{
							if((BusquedaPorHora(&MedidasLaboratorio[i],BuscadorLetras))==1)
							{
								printf("\n    SE ENCONTRO LA MEDICION N°%d",i+1);
								ImprimirMediciones(&MedidasLaboratorio[i]);
							}
						}
						break;
					case 3:
						printf("QUE TIPO DE SENSOR DESEA BUSCAR?:\n");
						printf("SENSOR N° 1: ");
						printf("%s",SensorTipo[0].MarcaSensor);
						
						printf("\nSENSOR N° 2: ");
						printf("%s",SensorTipo[1].MarcaSensor);

						printf("\nSENSOR N° 3: ");
						printf("%s",SensorTipo[2].MarcaSensor);
						
						printf("\nIngrese el N° de sensor: ");
						scanf("%d",&BuscadorSensor);
						
						for(i=0;i<control;i++)
						{
							if(BusquedaPorSensor(&MedidasLaboratorio[i],BuscadorSensor)==1)
							{	
								printf("\n    SE ENCONTRO LA MEDICION N°%d",i+1);
								ImprimirMediciones(&MedidasLaboratorio[i]);
							}
						}
						
						break;
					case 4:
						printf("Ingrese el valor medido a buscar: ");
						scanf("%f",&BuscadorValorMedido);
						fflush(stdin);
						for(i=0;i<control;i++)
						{
							if((BusquedaPorValorMedido(&MedidasLaboratorio[i],BuscadorValorMedido))==1)
							{
								printf("\n    SE ENCONTRO LA MEDICION N°%d",i+1);
								ImprimirMediciones(&MedidasLaboratorio[i]);
							}
						}
						break;
					case 5:
						system("cls");
						break;
					default :
						break;
				}
				break;
				
			case 5:
				salir=1;
				break;
			case 6:
					puts("Se creo el Archivo");
					EscribirArchivo(ArchivoMediciones,control);
					puts("Donde se lee del Archivo:");
					LeerArchivo(ArchivoMediciones,control);
				break;
			
			default: 
				break;
		}
		
	}
	return 0;
}

void AgregarMedicion(struct Mediciones *A)
{
	int i;
	printf("Ingrese la fecha de la medicion (dia/mes/año): ");
	gets(A->Fecha);
	fflush(stdin);
	printf("\nIngresar la hora en que se realizo la medida (hora:minutos): ");
	gets(A->Hora);
	fflush(stdin);
	printf("\nIngrese la marca del sensor que uso: \n 1-Sony\n 2-Philips\n 3-Liliana\n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.MarcaSensor,SensorTipo[i-1].MarcaSensor);
	printf("\nIngrese el tipo de sensor:\n 1-HPR \n 2-JPG\n 3-PKH \n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.TipoSensor,SensorTipo[i-1].TipoSensor);
	printf("\nIngrese la unidad de medida:\n 1-Milimetros \n 2-Decimetros \n 3-Nanometros\n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.UnidadMedida,SensorTipo[i-1].UnidadMedida);
	printf("\nIngrese el valor medido: ");
	scanf("%f",&A->ValorMedido);
	fflush(stdin);
	printf("\nAgregue algunos comentarios: ");
	gets(A->Comentarios);
	fflush(stdin);
}

void ImprimirMediciones(struct Mediciones *A)
{
	printf("\n\tFecha: ");
	puts(A->Fecha);
	printf("\n\tHora: ");
	puts(A->Hora);
	printf("\n\tMarca: ");
	puts(A->Sensor.MarcaSensor);
	printf("\n\tSensor: ");
	puts(A->Sensor.TipoSensor);
	printf("\n\tUnidad de medida: ");
	puts(A->Sensor.UnidadMedida);
	printf("\n\tValor medido: %f\n",A->ValorMedido);
	printf("\n\tComentarios: ");
	puts(A->Comentarios);
}

void EliminarMediciones(struct Mediciones *A)
{
	strcpy(A->Fecha,"");
	strcpy(A->Hora,"");
	strcpy(A->Sensor.MarcaSensor,"");
	strcpy(A->Sensor.TipoSensor,"");
	strcpy(A->Sensor.UnidadMedida,"");
	A->ValorMedido=0;
	strcpy(A->Comentarios,"");
}

void ModificarMediciones(struct Mediciones *A)
{
	int i;
	printf("Ingrese la nueva fecha de la medicion (dia/mes/año): ");
	gets(A->Fecha);
	fflush(stdin);
	printf("\nIngresar la nueva hora en que se realizo la medida (hora:minutos): ");
	gets(A->Hora);
	fflush(stdin);
	printf("\nIngrese la marca del sensor que uso: \n 1-Sony\n 2-Philips\n 3-Liliana\n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.MarcaSensor,SensorTipo[i-1].MarcaSensor);
	printf("\nIngrese el tipo de sensor:\n 1-HPR \n 2-JPG\n 3-PKH \n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.TipoSensor,SensorTipo[i-1].TipoSensor);
	printf("\nIngrese la unidad de medida:\n 1-Milimetros \n 2-Decimetros \n 3-Nanometros\n");
	scanf("%d",&i);
	fflush(stdin);
	strcpy(A->Sensor.UnidadMedida,SensorTipo[i-1].UnidadMedida);
	printf("\nIngrese el valor medido: ");
	scanf("%f",&A->ValorMedido);
	fflush(stdin);
	printf("\nAgregue algunos comentarios: ");
	gets(A->Comentarios);
	fflush(stdin);
	
}

int BusquedaPorFecha(struct Mediciones *A, char *B)
{
	int encontro=0;
	if(strcmp(B,A->Fecha)==0)
	{
		encontro=1;
	}
	return(encontro);
}
int BusquedaPorHora(struct Mediciones *A, char *B)
{
	int encontro=0;
	if(strcmp(B,A->Hora)==0)
	{
		encontro=1;
	}
	return(encontro);
}
int BusquedaPorValorMedido(struct Mediciones *A, float B)
{
	int encontro=0;
	if(B==A->ValorMedido)
	{
		encontro=1;
	}
	return(encontro);
}
int BusquedaPorSensor(struct Mediciones *A, int B)
{
	int encontro=0;
	switch(B)
	{
	case 1: 
			if((strcmp(SensorTipo[0].MarcaSensor,A->Sensor.MarcaSensor))==0)
			{
				encontro=1;
			}
		break;
	case 2:
		if((strcmp(SensorTipo[1].MarcaSensor,A->Sensor.MarcaSensor))==0)
		{
			encontro=1;
		}
		break;
	case 3:
		if((strcmp(SensorTipo[2].MarcaSensor,A->Sensor.MarcaSensor))==0)
		{
			encontro=1;
		}
		break;
	default :
		break;
	}
	
	return(encontro);
}

void EscribirArchivo(FILE *A, int Contador)
{
	if((A=fopen("Mediciones.txt","wb+"))!=NULL)
	{
		fwrite(&MedidasLaboratorio,sizeof(struct Mediciones),Contador,A);
	}
	fclose(A);
}
void LeerArchivo(FILE *A, int Contador)
{
	int i=0;
	if((A=fopen("Mediciones.txt","rb+"))!=NULL)
	{
		fread(&MedidasLaboratorio,sizeof(struct Mediciones),Contador,A);
		for(i=0;i<Contador;i++)
		{
			ImprimirMediciones(&MedidasLaboratorio[i]);
		}
	}
	fclose(A);
}