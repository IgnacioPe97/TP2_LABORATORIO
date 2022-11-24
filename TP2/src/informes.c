/*
 * informes.c
 *
 *  Created on: 23-10-2022
 *      Author: Ignacio Pereyra
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "informes.h"
#include "confederaciones.h"
#include "utnValidaciones.h"

/**
 * @brief Ordena por dos criterios, alfabeticos, primero por nombre de conferencias y en caso de igualdad ordena alfabeticamente por nombre de
 * 			jugador y los imprime
 * m
 * @param jugador array de jugador
 * @param tam tamanio de jugador
 * @param confederacion array de confederacion
 * @param tamConfe tamanio de confederacion
 * @return retorna -1 si no se pudo ejecutar, y en caso qeu salga bien retorna 0
 */
int ordenaPorDosCriteriosAlfabeticos(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe)
{
	int retorno=-1;
	eJugador jugadorAux;


	if(jugador != NULL && tam>0 && confederacion != NULL && tamConfe>0)
	{

		for(int i=0; i<tam; i++)
		{
			if(jugador[i].idCondeferecion < jugador[i+1].idCondeferecion)
			{
				jugadorAux = jugador[i];
				jugador[i] = jugador[i+1];
				jugador[i+1] = jugadorAux;
			}
			else
			{
				if(jugador[i].idCondeferecion == jugador[i+1].idCondeferecion && strncmp(jugador[i].nombre,jugador[i+1].nombre,LARGE)<0)
				{
					jugadorAux = jugador[i];
					jugador[i] = jugador[i+1];
					jugador[i+1] = jugadorAux;
				}
			}
		}
		retorno=0;
	}
	imprime(jugador, tam, confederacion, tamConfe);
	return retorno;
}


void imprimeConfederacionYJugadoresDeLaMisma(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe)
{

			for(int i=0; i<tamConfe; i++)
			{
		printf("Confederacion %s \n",confederacion[i].nombre);
				for(int j=0; j<tam; j++)
					{
						if(jugador[j].idCondeferecion==confederacion[i].id )//&& !jugador[j].isEmpty)
						{
							printf("%-4d  %-20s  %-15s     %2d     %15s    %6.2f    %d   \n",jugador[j].id,jugador[j].nombre,jugador[j].posicion,jugador[j].numeroCamiseta,
													confederacion[i].nombre,jugador[j].salario,jugador[j].aniosContrato);
						}
					}
			}
}
/**
 * @brief calcula promedio de salarios de jugador
 *
 * @param jugador
 * @param tam
 */
void calculaPromedioSalarios(eJugador jugador[], int tam,eConfederaciones confederaciones[],int size)
{
	float totalSalarios=0;
	int contadorJugadores=0;
	float promedioSalarios;
	char nombreConfe[30];

	if(jugador != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
			{
				if(jugador[i].isEmpty==0 && jugador[i].id>0)
				{
					totalSalarios=totalSalarios + jugador[i].salario;
					contadorJugadores++;
				}

			}
			if(totalSalarios>0 && contadorJugadores>0)
			{
				promedioSalarios = totalSalarios/contadorJugadores;
				printf("Salario total de jugadores es %.2f  y el promedio es %.2f\n", totalSalarios, promedioSalarios);


				for(int i=0; i<contadorJugadores; i++)
				{
					if(jugador[i].salario > promedioSalarios && jugador[i].isEmpty==0 && jugador[i].id>0)
					{
						printf("contarodJugadores %d \n",contadorJugadores);
						retornaNombreConfeById(confederaciones, size, jugador[i].idCondeferecion, nombreConfe);
						//imprime(jugador, tam, confederaciones, size);
						printf("%-4d  %-20s  %-15s     %2d     %15s    %6.2f    %d\n",jugador[i].id,jugador[i].nombre,jugador[i].posicion,jugador[i].numeroCamiseta,
												nombreConfe,jugador[i].salario,jugador[i].aniosContrato);
					}
				}
			}
	}
}
/**
 * @brief muestra promedios del salario y total de salarios. tambien jugadores que pasan este promedio de salario
 *
 * @param jugador
 * @param tam
 * @param pSalarioTotal puntero de salarios totales
 * @param pPromedioSalario puntero de promedios salarios
 */

void muestraPromedioSalarioYSalarioTotal(eJugador jugador[], int tam, float*pSalarioTotal, float *pPromedioSalario)
{
	if(jugador != NULL && tam>0)
	{

		printf("El salario total de los jugadores es %.2f\n",*(pSalarioTotal));
	}


}

/**
 * @brief  muestra la region con mayor cantidad de jgadoreos
 *
 * @param jugador
 * @param tam
 * @param confederacion
 * @param tamConfe
 * @return retorna 0 em casp de exotp
 */
int mayorNumeroJugadoresPorRegion(eJugador jugadores[], int tam,int acumuladorJugadoresUEFA,int acumuladorJugadoresCONMEBOL, int acumuladorJugadoresCONCACAF, int acumuladorJugadoresAFC,
		int acumuladorJugadoresCAF,int acumuladorJugadoresOFC, eConfederaciones confederacion[],int size)
{
	int id;
	int retorno=1;
	if(acumuladorJugadoresUEFA > acumuladorJugadoresCONMEBOL && acumuladorJugadoresUEFA > acumuladorJugadoresCONCACAF && acumuladorJugadoresUEFA > acumuladorJugadoresAFC &&
			acumuladorJugadoresUEFA > acumuladorJugadoresCAF && acumuladorJugadoresUEFA > acumuladorJugadoresOFC)
	{
		printf("Mayor numero de jugadores en Region Europea %d\n", acumuladorJugadoresUEFA);
		id = 101;
	}
	else
	{
		if(acumuladorJugadoresCONMEBOL > acumuladorJugadoresCONCACAF && acumuladorJugadoresCONMEBOL > acumuladorJugadoresAFC &&
				acumuladorJugadoresCONMEBOL > acumuladorJugadoresCAF && acumuladorJugadoresCONMEBOL > acumuladorJugadoresOFC)
		{
			printf("Mayor numero de jugadores en Region Sudamericana %d\n", acumuladorJugadoresCONMEBOL);
			id = 100;
		}
		else
		{
			if(acumuladorJugadoresCONCACAF > acumuladorJugadoresAFC && acumuladorJugadoresCONCACAF > acumuladorJugadoresCAF && acumuladorJugadoresCONCACAF > acumuladorJugadoresOFC)
			{

				printf("Mayor numero de jugadores en  Norte y Centro America %d\n", acumuladorJugadoresCONCACAF);
				id = 104;

			}
			else
			{
				if( acumuladorJugadoresAFC > acumuladorJugadoresCAF && acumuladorJugadoresAFC > acumuladorJugadoresOFC)
				{
					printf("Mayor numero de jugadores en Asia %d\n", acumuladorJugadoresAFC);
					id = 102;


				}
				else
				{
					if( acumuladorJugadoresCAF > acumuladorJugadoresOFC)
					{
						printf("Mayor numero de jugadores en Africa %d\n", acumuladorJugadoresCAF);
						id = 103;


					}
					else
					{
						printf("Mayor numero de jugadores en Oceania %d\n", acumuladorJugadoresOFC);
						id = 105;
					}
				}
			}
		}
	}
	imprimeJugadoresDeUnaConfederacion(jugadores, tam, id,confederacion,size);
	return retorno;
}
/**
 * @brief informa el porcentaje de confederaciones segun su cantidad de jugadores
 *
 * @param jugador
 * @param tam
 * @param confederacion
 * @param tamConfe
 */
void informaPorcentajeConfederaciones(int acumuladorJugadoresUEFA,int acumuladorJugadoresCONMEBOL, int acumuladorJugadoresCONCACAF, int acumuladorJugadoresAFC, int acumuladorJugadoresCAF,
		int acumuladorJugadoresOFC)
{

	int contadorJugadores;
	float porcentajeUEFA;
	float porcentajeCONMEBOL;
	float porcentajeCONCACAF;
	float porcentajeAFC;
	float porcentajeCAF;
	float porcentajeOFC;
	contadorJugadores = acumuladorJugadoresUEFA + acumuladorJugadoresCONMEBOL + acumuladorJugadoresCONCACAF + acumuladorJugadoresAFC + acumuladorJugadoresCAF + acumuladorJugadoresOFC;


				porcentajeUEFA=calculaPromedio(acumuladorJugadoresUEFA,contadorJugadores);
				printf("UEFA %.2f\n",porcentajeUEFA);
				porcentajeCONMEBOL=calculaPromedio(acumuladorJugadoresCONMEBOL,contadorJugadores);
				printf("CONMEBOL %.2f\n",porcentajeCONMEBOL);
				porcentajeCONCACAF=calculaPromedio(acumuladorJugadoresCONCACAF,contadorJugadores);
				printf("CONCACAF %.2f\n",porcentajeCONCACAF);
				porcentajeAFC=calculaPromedio(acumuladorJugadoresAFC,contadorJugadores);
				printf("AFC %.2f\n",porcentajeAFC);
				porcentajeCAF=calculaPromedio(acumuladorJugadoresCAF,contadorJugadores);
				printf("CAF %.2f\n",porcentajeCAF);
				porcentajeOFC=calculaPromedio(acumuladorJugadoresOFC,contadorJugadores);
				printf("OFC %.2f\n",porcentajeOFC);

}
/**
 * @brief  calcula el promedio de juugadores por conferencia
 *
 * @param acumulador
 * @param cantJugadores
 * @return devuelve el porcentaje
 */
float calculaPromedio(int acumulador,int cantJugadores)
{
	float porcentaje=0;
	if(acumulador>0 && cantJugadores>0)
	{
			porcentaje = (acumulador*100)/cantJugadores;

	}
	return porcentaje;
}
/**
 * @brief calcula la confederacion con mayor anios de contrato y la imprime
 *
 * @param jugador
 * @param tam
 * @param confederacion
 * @param tamConfe
 */
void calculaMayorCantidadDeAniosEnContratos(int acumuladorCONMEBOL, int acumuladorUEFA, int acumuladorAFC, int acumuladorCAF, int acumuladorCONCACAF, int acumuladorOFC)
{


		if(acumuladorCONMEBOL > acumuladorUEFA && acumuladorCONMEBOL > acumuladorAFC && acumuladorCONMEBOL > acumuladorCAF && acumuladorCONMEBOL > acumuladorCONCACAF && acumuladorCONMEBOL> acumuladorOFC)
		{
			printf("Mayor cantidad de años es CONMEBOL %d \n", acumuladorCONMEBOL);
		}
		else
		{
			if( acumuladorUEFA > acumuladorAFC && acumuladorUEFA > acumuladorCAF && acumuladorUEFA > acumuladorCONCACAF && acumuladorUEFA> acumuladorOFC)
			{
				printf("Mayor cantidad de años es UEFA %d \n", acumuladorUEFA);
			}
			else
			{
				if( acumuladorAFC > acumuladorCAF && acumuladorAFC > acumuladorCONCACAF && acumuladorAFC> acumuladorOFC)
				{

					printf("Mayor cantidad de años es AFC %d \n", acumuladorAFC);

				}
				else
				{
					if(acumuladorCAF > acumuladorCONCACAF && acumuladorCAF> acumuladorOFC)
					{
						printf("Mayor cantidad de años es CAF %d \n", acumuladorCAF);

					}
					else
					{
						if(acumuladorCONCACAF> acumuladorOFC)
						{
							printf("Mayor cantidad de años es CONCACAF %d \n", acumuladorCONCACAF);

						}
						else
						{
							printf("Mayor cantidad de años es OFC %d \n", acumuladorOFC);

						}
					}
				}
			}
		}
}






