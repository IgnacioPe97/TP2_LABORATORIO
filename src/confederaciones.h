/*
 * confederaciones.h
 *
 *  Created on: 23-10-2022
 *      Author: Ignacio Pereyra
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_


#define LARGO 50
#define CANTIDAD_CONFE 6
typedef struct
{
	int id;
	char nombre[LARGO];
	char region[LARGO];
	int anioCreacion;

}eConfederaciones;

int buscaId(eConfederaciones confederaciones[],int tamConfe,int id);
void imprimeConfederaciones(eConfederaciones conferederaciones[], int tamConfe);
int devuelveIdConfederacion(eConfederaciones confederaciones[],int tamConfe,int id);
void ordenaConferenciasAlfabetico(eConfederaciones confederacion[],int tamConfe);
int MuestraMenuInicio(void);
int MuestraMenuInformes(void);






#endif /* CONFEDERACIONES_H_ */
