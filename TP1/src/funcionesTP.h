/*
 * funcionesTP.h
 *
 *  Created on: 19-09-2022
 *      Author: Ignacio Pereyra
 */

#ifndef FUNCIONESTP_H_
#define FUNCIONESTP_H_
#include "funcionesTP.h"
#include "validacion.h"
#include <stdio.h>
#include <stdlib.h>


int MuestraMenuInicioJugadores(void);
int CargaConferencia(int *confederacion, int *confederacion2,int *confederacion3,int *confederacion4,int *confederacion5,int *confederacion6);
void cargaJugadores(int *contadorArqueros,int *contadorDefensores,int *contadorVolantes,int *contadorDelanteros);
void CalculaPromedioJugadoresConferencias(int cantidadJugadores, int *confederacion, int *confederacion2,int *confederacion3,int *confederacion4,int *confederacion5,int *confederacion6);
float CalculaPromedioConferencia(int *confederacion, int sizeJugadores);
void ImprimePromediosConferencia(float promedio);


#endif /* FUNCIONESTP_H_ */
