
#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
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
#define LARGE_SELEC 30

typedef struct
{
	int id;
	char pais[LARGE_SELEC];
	char confederacion[LARGE_SELEC];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);
int retornaIndiceListaSeleccion(LinkedList* pArrayListSeleccion,int id);
int muestraListados(int opcion,LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);




#endif // selec_H_INCLUDED
