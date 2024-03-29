/*
 * jugador.h
 *
 *  Created on: 22-10-2022
 *      Author: Ignacio Pereyra
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "confederaciones.h"


#define LARGE 50
typedef struct
{
	int id;
	char nombre[LARGE];
	char posicion [LARGE];
	short int numeroCamiseta;
	int idCondeferecion;
	float salario;
	short int aniosContrato;
	short int isEmpty;
}eJugador;

int altaJugador(eJugador array[], int tam, int *idIncremental, eConfederaciones confederaciones[],int tamConfe, int indice);
int inicializaJugador(eJugador jugador[], int tam);
int buscaLugarLibre(eJugador jugador[], int tam);
int buscaIndice(eJugador jugador[], int tam);
int cuentaCantidadJugadoresIngresados(eJugador jugador[], int tam,int *contadorJugadores);
int modificaJugador(eJugador array[], int tam, eConfederaciones confederaciones[], int tamConfe, int indice);
int bajaJugador(eJugador array[], int tam,int indice);
int buscaIdJugador(eJugador jugador[], int tam, int idBuscado);
void imprimeJugadorYConferencia(eJugador array[], int tam, eConfederaciones confederaciones[], int tamConfe);
void ordenaJugadoresAlfabetico(eJugador jugador[],int tam);
void imprime(eJugador jugador[],int tam,eConfederaciones confederacion[], int size);
void imprimeJugadorYId(eJugador jugador[], int tam);
int verificaQueHayaJugadoresCargados(eJugador jugador[], int tam);
int ordenaPorConfederacion(eJugador jugador[], int tam);
void acumulaJugadoresYAniosSueldosPorConferencia(eJugador jugador[], int tam, int *acumuladorCONMEBOL, int *acumuladorUEFA, int *acumuladorAFC, int *acumuladorCAF, int *acumuladorCONCACAF, int *acumuladorOFC,
int *aniosCONMEBOL, int *aniosUEFA,  int *aniosAFC, int *aniosCAF, int *aniosCONCACAF,int *aniosOFC);
void imprimeJugadoresDeUnaConfederacion(eJugador jugador[], int tam, int id,eConfederaciones confederacion[], int size);







#endif /* JUGADOR_H_ */
