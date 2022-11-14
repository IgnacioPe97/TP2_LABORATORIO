/*
 * ValidacionUTN.h
 *
 *  Created on: 05-11-2022
 *      Author: Ignacio Pereyra
 */

#ifndef VALIDACIONUTN_H_
#define VALIDACIONUTN_H_


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroConDecimales(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);
int myGets(char *cadena, int longitud);
int utn_getNombre(char *pResultado, char *mensaje, char *mensajeError,int longitud, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, int reintentos);



#endif /* VALIDACIONUTN_H_ */
