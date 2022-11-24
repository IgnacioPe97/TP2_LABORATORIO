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
void calculaPromedioSalarios(eJugador jugador[], int tam,eConfederaciones confederaciones[],int size);
void calculaMayorCantidadDeAniosEnContratos(int acumuladorCONMEBOL, int acumuladorUEFA, int acumuladorAFC, int acumuladorCAF, int acumuladorCONCACAF, int acumuladorOFC);
int acumulaJugadoresXConfederacion(eJugador jugador[],int tam, eConfederaciones confederacion[], int tamConfe,int *acumuladorUno,int *acumuladorDos,int *acumuladorTres,int *acumuladorCuatro,int *acumuladorCinco,int *acumuladorSeis,int *contador);
float calculaPromedio(int acumulador,int cantJugadores);
void informaRegionConMasJugadores(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);
void informaPorcentajeConfederaciones(int acumuladorJugadoresUEFA,int acumuladorJugadoresCONMEBOL, int acumuladorJugadoresCONCACAF, int acumuladorJugadoresAFC, int acumuladorJugadoresCAF,
int acumuladorJugadoresOFC);
int mayorNumeroJugadoresPorRegion(eJugador jugadores[], int tam,int acumuladorJugadoresUEFA,int acumuladorJugadoresCONMEBOL, int acumuladorJugadoresCONCACAF, int acumuladorJugadoresAFC,
		int acumuladorJugadoresCAF,int acumuladorJugadoresOFC, eConfederaciones confederacion[],int size);
void imprimeConfederacionYJugadoresDeLaMisma(eJugador jugador[], int tam, eConfederaciones confederacion[], int tamConfe);













#endif /* INFORMES_H_ */
