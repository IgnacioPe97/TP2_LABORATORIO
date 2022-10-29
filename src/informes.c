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
 *
 * @param jugador array de jugador
 * @param tam tamanio de jugador
 * @param confederacion array de confederacion
 * @param tamConfe tamanio de confederacion
 * @return retorna -1 si no se pudo ejecutar, y en caso qeu salga bien retorna 0
 */
int ordenaPorDosCriteriosAlfabeticos(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe)
{
	int retorno=-1;
	int flagSwap;
	int bandera=0;


	if(jugador != NULL && tam>0 && confederacion != NULL && tamConfe>0)
	{
		ordenaConferenciasAlfabetico(confederacion, tamConfe);
		ordenaJugadoresAlfabetico(jugador,tam);
		do{
			flagSwap = 0;
			for(int j=0; j<tamConfe;j++)
			{
				for(int i=0; i<tam; i++)
				{
						if(confederacion[j].id==jugador[i].idCondeferecion && !jugador[i].isEmpty)
						{
 							if(!bandera)
 							{
 								printf("ID   | NOMBRE    	   |     POSICION    |N° CAMISETA| CONFEDERACION |SUELDO    || AÑOS DE CONTRATO\n");
 								imprime(&jugador[i],&confederacion[j]);

 								bandera=1;
 							}
 							else
 							{
 								imprime(&jugador[i],&confederacion[j]);

 							}
						}
				}
			}

		}while(flagSwap);
	}
	return retorno;
}


void imprimeConfederacionYJugadoresDeLaMisma(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe)
{

	for(int i=0; i<tamConfe; i++)
			{
				for(int j=0; j<tam; j++)
					{
						if(jugador[j].idCondeferecion==confederacion[i].id && !jugador[j].isEmpty)
						{
								imprime(&jugador[j],&confederacion[i]);
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
void calculaPromedioSalarios(eJugador jugador[], int tam)
{
	float totalSalarios=0;
	int contadorJugadores=0;
	float promedioSalarios;
	int bandera=1;

	if(jugador != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
			{
				if(!jugador[i].isEmpty)
				{
					totalSalarios=totalSalarios + jugador[i].salario;
					contadorJugadores++;
					bandera=0;
				}
			}
			if(totalSalarios>0 && contadorJugadores>0 && !bandera)
			{
				promedioSalarios = totalSalarios/contadorJugadores;
				muestraPromedioSalarioYSalarioTotal(jugador,tam,&totalSalarios,&promedioSalarios);

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
		for(int j=0; j<tam; j++)
		{
			if(jugador[j].salario > *(pPromedioSalario) && !jugador[j].isEmpty)
			{
				printf("El jugador %s  tiene un salario de %.2f  y supera el promedioSalario de %.2f\n",jugador[j].nombre,jugador[j].salario,*(pPromedioSalario));
			}
		}
		printf("El salario total de los jugadores es %.2f\n",*(pSalarioTotal));
	}


}
/**
 * @brief acumula jugadores de una misma confederacion
 *
 * @param jugador
 * @param tam
 * @param confederacion
 * @param tamConfe
 * @param acumuladorUno
 * @param acumuladorDos
 * @param acumuladorTres
 * @param acumuladorCuatro
 * @param acumuladorCinco
 * @param acumuladorSeis
 * @param contador
 * @return retorna 0 encaso de exito y 1 en caso fracaso fracaso
 */
int acumulaJugadoresXConfederacion(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe,int *acumuladorUno,int *acumuladorDos,int *acumuladorTres,int *acumuladorCuatro,int *acumuladorCinco,int *acumuladorSeis,int *contador)
{

	int retorno=1;

	if(jugador != NULL && tam > 0 && confederacion != NULL && tamConfe > 0)
	{
		for(int i=0; i<tamConfe; i++)
					{
						for(int j=0; j<tam; j++)
							{
								if(jugador[j].idCondeferecion==confederacion[i].id && !jugador[j].isEmpty)
								{
									(*contador)++;
									retorno=0;
									switch(jugador[j].idCondeferecion)
									{
										case 100:
											(*acumuladorUno)++;
											break;
										case 101:
											(*acumuladorDos)++;
											break;
										case 102:
											(*acumuladorTres)++;
											break;
										case 103:
											(*acumuladorCuatro)++;
											break;
										case 104:
											(*acumuladorCinco)++;
											break;
										case 105:
											(*acumuladorSeis)++;
											break;
									}
								}
							}
					}

	}
return retorno;
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
int mayorNumeroJugadoresPorRegion(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe)
{
	int id;
	int retorno=1;
	int acumuladorJugadoresUEFA=0;
	int acumuladorJugadoresCONMEBOL=0;
	int acumuladorJugadoresCONCACAF=0;
	int acumuladorJugadoresAFC=0;
	int acumuladorJugadoresCAF=0;
	int acumuladorJugadoresOFC=0;
	int contadorJugadores;
	int bandera=1;
	if(jugador != NULL && tam > 0 && confederacion != NULL && tamConfe > 0)
	{
		if(!acumulaJugadoresXConfederacion(jugador,tam,confederacion,tamConfe,
				&acumuladorJugadoresCONMEBOL,&acumuladorJugadoresUEFA,&acumuladorJugadoresAFC,&acumuladorJugadoresCAF,&acumuladorJugadoresCONCACAF,&acumuladorJugadoresOFC,&contadorJugadores))
		{
			buscaNumeroMayor(acumuladorJugadoresCONMEBOL,acumuladorJugadoresUEFA,acumuladorJugadoresAFC,acumuladorJugadoresCAF,acumuladorJugadoresCONCACAF,acumuladorJugadoresOFC,&id);

					for(int i=0; i<tamConfe; i++)
					{
						for(int j=0; j<tam;j++)
						{
							if(jugador[j].idCondeferecion==confederacion[i].id && jugador[j].idCondeferecion==id && confederacion[i].id==id && !jugador[j].isEmpty)
							{
								if(bandera)
								{
									printf("Region con mas jugadores %s\n" ,confederacion[i].region);
									printf("%s\n",jugador[j].nombre);
									bandera=0;
									retorno=0;
								}
								else
								{
									printf("%s\n",jugador[j].nombre);
								}

							}

						}
					}
		}
	}
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
void informaPorcentajeConfederaciones(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe)
{
	int acumuladorJugadoresUEFA=0;
	int acumuladorJugadoresCONMEBOL=0;
	int acumuladorJugadoresCONCACAF=0;
	int acumuladorJugadoresAFC=0;
	int acumuladorJugadoresCAF=0;
	int acumuladorJugadoresOFC=0;
	int contadorJugadores=0;
	float porcentajeUEFA;
	float porcentajeCONMEBOL;
	float porcentajeCONCACAF;
	float porcentajeAFC;
	float porcentajeCAF;
	float porcentajeOFC;
		if(jugador != NULL && tam > 0 && confederacion != NULL && tamConfe > 0)
		{
			if(!acumulaJugadoresXConfederacion(jugador,tam,confederacion,tamConfe,
			&acumuladorJugadoresCONMEBOL,&acumuladorJugadoresUEFA,&acumuladorJugadoresAFC,&acumuladorJugadoresCAF,&acumuladorJugadoresCONCACAF,&acumuladorJugadoresOFC,&contadorJugadores))
			{
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
		}
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
void calculaMayorCantidadDeAniosEnContratos(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe)
{
	int id;
	int idAux;
	int mayor;
	int acumuladorConferenciaUEFA=0;
	int acumuladorConferenciaCONMEBOL=0;
	int acumuladorConferenciaCONCACAF=0;
	int acumuladorConferenciaAFC=0;
	int acumuladorConferenciaCAF=0;
	int acumuladorConferenciaOFC=0;



	for(int i=0; i<tam; i++)
	{
		if(!jugador[i].isEmpty)
		{
			switch(jugador[i].idCondeferecion)
			{
				case 100:
					acumuladorConferenciaCONMEBOL=acumuladorConferenciaCONMEBOL+jugador[i].aniosContrato;
					break;
				case 101:
					acumuladorConferenciaUEFA=acumuladorConferenciaUEFA+jugador[i].aniosContrato;
					break;
				case 102:
					acumuladorConferenciaAFC=acumuladorConferenciaAFC+jugador[i].aniosContrato;
					break;
				case 103:
					acumuladorConferenciaCAF=acumuladorConferenciaCAF+jugador[i].aniosContrato;
					break;
				case 104:
					acumuladorConferenciaCONCACAF=acumuladorConferenciaCONCACAF+jugador[i].aniosContrato;
					break;
				case 105:
					acumuladorConferenciaOFC=acumuladorConferenciaOFC+jugador[i].aniosContrato;
					break;
			}

		}

	}
	mayor=buscaNumeroMayor(acumuladorConferenciaCONMEBOL,acumuladorConferenciaUEFA,acumuladorConferenciaAFC,acumuladorConferenciaCAF,acumuladorConferenciaCONCACAF,acumuladorConferenciaOFC,&id);
	idAux=devuelveIdConfederacion(confederacion,tamConfe,id);
	printf("Confederacion %s  es la que tiene mayor años de contrato %d",confederacion[idAux].nombre,mayor);
}
/**
 * @brief busca el numero mayor de acumuladores de confederacion
 *
 * @param acumuladorConfe1
 * @param acumuladorConfe2
 * @param acumuladorConfe3
 * @param acumuladorConfe4
 * @param acumuladorConfe5
 * @param acumuladorConfe6
 * @param id puntero a id que retorna en caso que ese acumulador sea el mas grande
 * @return retorna el mayor y su id
 */
int buscaNumeroMayor(int acumuladorConfe1,int acumuladorConfe2,int acumuladorConfe3,int acumuladorConfe4,int acumuladorConfe5,int acumuladorConfe6, int *id)
{
	int mayor;

	if(acumuladorConfe1 >acumuladorConfe2 && acumuladorConfe1 > acumuladorConfe3 && acumuladorConfe1 > acumuladorConfe4 && acumuladorConfe1 > acumuladorConfe5  && acumuladorConfe1 > acumuladorConfe6)
	{
		mayor=acumuladorConfe1;
		*id=100;
	}
	else
	{
		if(acumuladorConfe2 > acumuladorConfe3 &&acumuladorConfe2 > acumuladorConfe4 && acumuladorConfe2 > acumuladorConfe5 && acumuladorConfe2 > acumuladorConfe6)
		{
			mayor=acumuladorConfe2;
			*id=101;
		}
		else
		{
			if(acumuladorConfe3 > acumuladorConfe4 && acumuladorConfe3 > acumuladorConfe5 && acumuladorConfe3 > acumuladorConfe6)
			{
				mayor=acumuladorConfe3;
				*id=102;
			}
			else
			{

				if(acumuladorConfe4 > acumuladorConfe5 && acumuladorConfe4 > acumuladorConfe6)
				{
					mayor=acumuladorConfe4;
					*id=103;

				}
				else
				{
					if(acumuladorConfe5 > acumuladorConfe6)
					{
						mayor=acumuladorConfe5;
						*id=104;

					}
					else
					{
						mayor=acumuladorConfe6;
						*id=105;

					}
				}
			}
		}
	}
	return mayor;
}





