

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#define NOMBRE_LEN 100
#define LARGO_CHAR 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "menus.h"
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "ctype.h"
#include "ValidacionUTN.h"


typedef struct
{
	int id;
	char nombreCompleto[NOMBRE_LEN];
	int edad;
	char posicion[LARGO_CHAR];
	char nacionalidad[LARGO_CHAR];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* jugador);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);
int jug_setIdTxt(Jugador* this,char* id);


int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);
int jug_setEdadTxt(Jugador* this,char* edad);


int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);
int jug_setIdSeleccionTxt(Jugador* this,char* idSeleccion);


int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);

int retornaIndiceLista(LinkedList* pArrayListJugador,int id);
int cambaInicialNombreMayuscula(char*cadena);
int modificaJugador(Jugador *this);
int convocaYSacaJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int convocacionJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int listarJugadoresConvocados(LinkedList * pArrayListJugador,LinkedList * pArrayListSeleccion);
int ordenAlfabeticoJugadores(LinkedList * pArrayListJugador);
int quitaJugadoresDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int listaConvocadosBinario(LinkedList * pListaConvocados, LinkedList* pArrayListJugador);
int listaUnJugador(LinkedList* pArrayListJugador, int id);











#endif // jug_H_INCLUDED
