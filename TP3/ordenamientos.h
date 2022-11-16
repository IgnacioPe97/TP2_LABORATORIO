/*
 * ordenamientos.h
 *
 *  Created on: 10-11-2022
 *      Author: Ignacio Pereyra
 */

#ifndef ORDENAMIENTOS_H_
#define ORDENAMIENTOS_H_
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

int ordenaPorNombreJugadores(void* , void*);
int ordenaPorNacionalidadJugadores(void* unJugador, void* otroJugador);
int ordenaPorEdadJugadores(void* unJugador, void* otroJugador);
int ordenaPorConfederacionSelecciones(void* unaSeleccion, void* otraSeleccion);





#endif /* ORDENAMIENTOS_H_ */
