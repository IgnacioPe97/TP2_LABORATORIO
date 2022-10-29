/*
 * informes.h
 *
 *  Created on: 23-10-2022
 *      Author: Ignacio Pereyra
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"
#include "confederaciones.h"
#include "utnValidaciones.h"


int ordenaPorDosCriteriosAlfabeticos(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);
void imprimeConfederacionesConSusJugadores(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);
void ordenaConferenciasAlfabetico(eConfederaciones confederacion[],int tamConfe);
void listaConfederacionConJugadores(eConfederaciones confederacion[], eJugador jugador[],int tam,int idConfe);
void muestraPromedioSalarioYSalarioTotal(eJugador jugador[], int tam, float*pSalarioTotal, float *pPromedioSalario);
void calculaPromedioSalarios(eJugador jugador[], int tam);
void calculaMayorCantidadDeAniosEnContratos(eJugador jugador[],int tam,eConfederaciones confederacion[], int tamConfe);
int buscaNumeroMayor(int acumuladorConfe1,int acumuladorConfe2,int acumuladorConfe3,int acumuladorConfe4,int acumuladorConfe5,int acumuladorConfe6, int *id);
int acumulaJugadoresXConfederacion(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe,int *acumuladorUno,int *acumuladorDos,int *acumuladorTres,int *acumuladorCuatro,int *acumuladorCinco,int *acumuladorSeis,int *contador);
float calculaPromedio(int acumulador,int cantJugadores);
void informaRegionConMasJugadores(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);
void informaPorcentajeConfederaciones(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe);
int mayorNumeroJugadoresPorRegion(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe);
void imprimeConfederacionYJugadoresDeLaMisma(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);













#endif /* INFORMES_H_ */
