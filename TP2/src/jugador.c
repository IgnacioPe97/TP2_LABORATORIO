/*
 * jugador.c
 *
 *  Created on: 22-10-2022
 *      Author: Ignacio Pereyra
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jugador.h"
#include "informes.h"
#include "confederaciones.h"
#include "utnValidaciones.h"

/**
 * @brief inicializa el array para que no muestre basura
 *
 * @param jugador
 * @param tam
 * @return retorna 0 en caso de EXITO y 1 en caso de FRACASO
 */
int inicializaJugador(eJugador jugador[], int tam)
{
	int retorno=1;
			for(int i=0; i<tam; i++)
			{
				jugador[i].isEmpty=1;
				retorno=0;
			}
	return retorno;
}
/**
 * @brief BUSCA UN LUGAR LIBRE PARA CARGAR CON DATOS
 *
 * @param jugador
 * @param tam
 * @return -1 EN CASO DE FRACASO Y 0 EN CASO DE QUE NO HAYA ENNCONTRADO Y EL INDICE PARA CARGAR EN CASO QUE LO ENCUENTRE
 */
int buscaLugarLibre(eJugador jugador[], int tam)
{
	int respuesta=-1;
	int i;
	if(jugador != NULL && tam > 0)
	{
		respuesta=0;
		for(i=0; i<tam; i++)
		{
			if(jugador[i].isEmpty==1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * @brief busca el indice cargado
 *
 * @param jugador
 * @param tam
 * @return -1 en caso FRACASO 0 en caso que no haya y el indice en caso que lo encontro
 */
int buscaIndice(eJugador jugador[], int tam)
{
	int respuesta=-1;
	int i;
	if(jugador != NULL && tam > 0)
	{
		respuesta=0;
		for(i=0; i<tam; i++)
		{
			if(jugador[i].isEmpty==0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
int cuentaCantidadJugadoresIngresados(eJugador jugador[], int tam,int *contadorJugadores)
{
	int respuesta=-1;
	int i;
	if(jugador != NULL && tam > 0)
	{
		respuesta=0;
		for(i=0; i<tam; i++)
		{
			if(jugador[i].isEmpty==0)
			{
				(*contadorJugadores)=(*contadorJugadores)+1;
				respuesta=0;
			}
		}
	}
	return respuesta;
}
/**
 * @brief Pide alta de array
 *
 * @param array
 * @param tam
 * @param idIncremental id inicializado en el main y lo devuelve incrementado en 1 para el siguiente jugador
 * @param confederaciones
 * @param tamConfe
 * @param indice indice para llenar
 * @return retorna 1 en caso FRACASO y 0 en caso de EXITO
 */
int altaJugador(eJugador array[], int tam, int *idIncremental, eConfederaciones confederaciones[],int tamConfe, int indice)
{
	eJugador jugador;
	int numeroPosicion;
	int retorno=1;

				if( array != NULL && tam>0 && confederaciones != NULL && tamConfe >0 && idIncremental != NULL && indice>=0)
				{
					if(
						!utn_getNombre(jugador.nombre,"Ingrese nombre:\n","Error, ingrese otra vez\n",LARGE,5) &&
						!utn_getNumero(&numeroPosicion,"Ingrese posicion 1-Arquero\n2-Defensor\n3-Mediocampista\n 4-Delantero:\n","Error, ingrese otra vez\n",1,4,5) &&
						!utn_getNumeroShort(&jugador.numeroCamiseta,"Ingrese numero de camiseta: \n","Error, numero no disponible\n",1,99,5) &&
						!utn_getNumeroConDecimales(&jugador.salario,"Ingrese salario de jugador:\n", "Error en el ingreso:\n", 100.0,1000000.0,5 &&
						!utn_getNumeroShort(&jugador.aniosContrato, "Ingrese la cantidad de años de contrato que tiene\n", "Error en el ingreso\n", 1, 6, 3))
					  )

						{
							switch(numeroPosicion)
							{
								case 1:
									strncpy(jugador.posicion,"Arquero",LARGE);
									break;
								case 2:
									strncpy(jugador.posicion,"Defensor",LARGE);
									break;
								case 3:
									strncpy(jugador.posicion,"Mediocampo",LARGE);
									break;
								case 4:
									strncpy(jugador.posicion,"Delantero",LARGE);
									break;
							}
							do{
								imprimeConfederaciones(confederaciones, tamConfe);
								utn_getNumero(&jugador.idCondeferecion,"Ingrese una confederacion\n","Error en el ingreso: \n",100,105,5);

								}while(buscaId(confederaciones,tamConfe,jugador.idCondeferecion));

							jugador.id = *idIncremental;
							jugador.isEmpty=0;
							array[indice]=jugador;
							(*idIncremental)++;
							retorno=0;
						}
				}

			return retorno;
}
/**
 * @brief modifica un jugador en el indice que se pidio
 *
 * @param array
 * @param tam
 * @param confederaciones
 * @param tamConfe
 * @param indice
 * @return retorna 0 en caso de EXITO y 1 en caso de FRACASO
 */
int modificaJugador(eJugador array[], int tam, eConfederaciones confederaciones[], int tamConfe, int indice)
{
	eJugador jugador;
		int retorno=1;
		int respuestaAuxiliar;

					if( array != NULL && tam>0 && confederaciones != NULL && tamConfe >0 && indice>=0 && array[indice].isEmpty==0)
					{

						do{
								utn_getNumero(&respuestaAuxiliar,"Ingrese campo a modificar\n 1-Nombre\n 2-Posicion\n 3-Numero camiseta\n 4-Salario\n 5-Confederacion\n 6- Salir\n","Error en el ingreso\n",1,6,3);
								switch(respuestaAuxiliar)
								{
									case 1 :
										utn_getNombre(jugador.nombre,"Ingrese nombre:\n","Error, ingrese otra vez\n",LARGE,5);
										strncpy(array[indice].nombre,jugador.nombre,LARGE);
										break;
									case 2 :
										utn_getNombre(jugador.posicion,"Ingrese posicion:\n","Error, ingrese otra vez\n",LARGE,5);
										strncpy(array[indice].posicion,jugador.posicion,LARGE);

										break;
									case 3 :
										utn_getNumeroShort(&jugador.numeroCamiseta,"Ingrese numero de camiseta: \n","Error, numero no disponible\n",1,99,5);
										array[indice].numeroCamiseta = jugador.numeroCamiseta;

										break;
									case 4 :
										utn_getNumeroConDecimales(&jugador.salario,"Ingrese salario de jugador:\n", "Error en el ingreso:\n", 100.0,1000000.0,5);
										array[indice].salario = jugador.salario;

										break;
									case 5 :
											do{
												imprimeConfederaciones(confederaciones, tamConfe);
												utn_getNumero(&jugador.idCondeferecion,"Ingrese una confederacion\n","Error en el ingreso: \n",100,105,5);

												}while(buscaId(confederaciones,tamConfe,jugador.idCondeferecion));
											array[indice].idCondeferecion = jugador.idCondeferecion;
										break;
									case 6 :
										break;
								}
						}while(respuestaAuxiliar!=6);

						//jugador.isEmpty=0;

						retorno=0;
					}
				return retorno;
}
/**
 * @brief da de baja un jugador en el indice asignado
 *
 * @param array
 * @param tam
 * @param indice
 * @return 0 en caso de EXITO Y 1 en fracaso
 */
int bajaJugador(eJugador array[], int tam,int indice)
{
	int retorno=1;
	if( array != NULL && tam>0 && indice>=0 && array[indice].isEmpty==0)
	{
		array[indice].isEmpty=1;
		retorno=0;
	}
	return retorno;

}
/**
 * @brief  Busca el id de un jugadar ya cargado
 *
 * @param jugador
 * @param tam
 * @param idBuscado
 * @return -1 en ccaso de fracaso 0 en caso que no lo enceuntre y el indice en caso de encontrarlo
 */
int buscaIdJugador(eJugador jugador[], int tam, int idBuscado)
{
	int retorno=-1;
	int i;

	if( jugador != NULL && tam>0 && idBuscado >= 0)
	{

		for(i=0; i<tam; i++)
		{

			if(jugador[i].id == idBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
return retorno;
}
/**
 * @brief  imprime jugador con todos sus campos
 *
 * @param jugador
 * @param confederacion
 */
void imprime(eJugador jugador[],int tam,eConfederaciones confederacion[], int size)
{
	char nombreConfederacion[30];
	int id;
	int i;
	for(i=0; i<tam; i++)
	{
		for(int j=0; j<size; j++)
				{
					if(jugador[i].idCondeferecion == confederacion[j].id)
					{
						printf("%-4d  %-20s  %-15s     %2d     %15s    %6.2f    %d \n",jugador[i].id,jugador[i].nombre,jugador[i].posicion,jugador[i].numeroCamiseta,
								confederacion[j].nombre,jugador[i].salario,jugador[i].aniosContrato);

					}
				}
	}

}
void imprimeJugadoresDeUnaConfederacion(eJugador jugador[], int tam, int id,eConfederaciones confederacion[], int size)
{
	char nombreConfederacion[30];

		for(int i=0; i<tam; i++)
		{
			if(jugador[i].idCondeferecion == id)
				{

					retornaNombreConfeById(confederacion, size, jugador[i].idCondeferecion, nombreConfederacion);
					printf("%-4d  %-20s  %-15s     %2d     %15s    %6.2f    %d   \n",jugador[i].id,jugador[i].nombre,jugador[i].posicion,jugador[i].numeroCamiseta,
																			nombreConfederacion,jugador[i].salario,jugador[i].aniosContrato);


				}
		}
}

/**
 * @brief ORDENA JUGADORES ALGABETICAMENTE
 *
 * @param jugador
 * @param tam
 */
void ordenaJugadoresAlfabetico(eJugador jugador[],int tam)
{
	eJugador jugadorAux;
			for(int j=0; j<tam; j++)
			{
				if(strncmp(jugador[j].nombre, jugador[j+1].nombre,LARGO)>0)
					{

						jugadorAux = jugador[j];
						jugador[j] = jugador[j+1];
						jugador[j+1] = jugadorAux;

					}
			}
}
void imprimeJugadorYId(eJugador jugador[], int tam)
{
	printf("ID		NOMBRE\n");
	for(int i=0; i<tam; i++)
	{
		if(!jugador[i].isEmpty)
		{
			printf("%d  		 %s\n",jugador[i].id,jugador[i].nombre);


		}
	}
}

int verificaQueHayaJugadoresCargados(eJugador jugador[], int tam)
{
	int retorno=1;
	if(jugador != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			jugador[i].isEmpty = 0;
			retorno=0;
			break;
		}
	}
return retorno;
}
int ordenaPorConfederacion(eJugador jugador[], int tam)
{
	eJugador jugadorAux;
	int retorno=1;

	for(int i=0; i<tam; i++)
	{

		if(jugador[i].idCondeferecion > jugador[i+1].idCondeferecion)
		{
			jugadorAux = jugador[i];
			jugador[i] = jugador[i+1];
			jugador[i+1] = jugadorAux;
			retorno=0;
		}
	}
	return retorno;
}

void acumulaJugadoresYAniosSueldosPorConferencia(eJugador jugador[], int tam, int *acumuladorCONMEBOL, int *acumuladorUEFA, int *acumuladorAFC, int *acumuladorCAF, int *acumuladorCONCACAF, int *acumuladorOFC,
int *aniosCONMEBOL, int *aniosUEFA,  int *aniosAFC, int *aniosCAF, int *aniosCONCACAF,int *aniosOFC)
{
	for(int i=0; i<tam; i++)
	{
		//if(!jugador[i].isEmpty)
		{
			switch(jugador[i].idCondeferecion)
			{
				case 100:
					*acumuladorCONMEBOL = (*acumuladorCONMEBOL)+1;
					*aniosCONMEBOL = (*aniosCONMEBOL) + jugador[i].aniosContrato;

					break;
				case 101:
					*acumuladorUEFA = (*acumuladorUEFA)+1;
					*aniosUEFA= (*aniosUEFA) + jugador[i].aniosContrato;

					break;
				case 102:
					*acumuladorAFC = (*acumuladorAFC)+1;
					*aniosAFC = (*aniosAFC) + jugador[i].aniosContrato;

					break;
				case 103:
					*acumuladorCAF = (*acumuladorCAF)+1;
					*aniosCAF = (*aniosCAF) + jugador[i].aniosContrato;

					break;
				case 104:
					*acumuladorCONCACAF = (*acumuladorCONCACAF)+1;
					*aniosCONCACAF = (*aniosCONCACAF) + jugador[i].aniosContrato;
					break;
				case 105:
					*acumuladorOFC = (*acumuladorOFC)+1;
					*aniosOFC = (*aniosOFC) + jugador[i].aniosContrato;
					break;
			}

		}

	}
}





