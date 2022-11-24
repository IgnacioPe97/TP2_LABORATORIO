/*
 * funcionesTP.c
 *
 *  Created on: 19-09-2022
 *      Author: Ignacio Pereyra
 */

#include "funcionesTP.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Muestra menu inicio
 *
 * @return retorna opcion ingresada
 */
int MuestraMenuInicioJugadores(void)
{
	int numeroIngresado;
				printf("1- Ingreso de los costos de Mantenimiento \n");
				printf("2- Carga de jugadores \n");
				printf("3- Realizar todos los calculos \n");
				printf("4-  Informar todos los resultados \n");
				printf("5- Salir \n");
					scanf("%d",&numeroIngresado);
		return numeroIngresado;
}


/**
 * @brief carga las conferencias del que piden
 *
 * @param confederacion
 * @param confederacion2
 * @param confederacion3
 * @param confederacion4
 * @param confederacion5
 * @param confederacion6
 * @return retorna si sle bien 1 y si sale mal -1
 */
int CargaConferencia(int *confederacion, int *confederacion2,int *confederacion3,int *confederacion4,int *confederacion5,int *confederacion6)
{
	int retorno=-1;
	int numero;
	int respuesta1;
	int confe;

	do{


		utn_getNumero(&numero,"Ingrese numero de camiseta: ","Error, numero invalido",1,99,5);
		respuesta1=utn_getNumero(&confe,"Ingrese Confederacion 1- AFC 2- CAF 3- CONCACAF 4- CONMEBOL 5- UEFA 6- OFC \n","Error, numero invalido",1,6,5);
	}while(respuesta1!=0);

	if(confe>0 && confe<7)
	{
	switch(confe)
		{
		case 1:
			(*confederacion)++;
			break;
		case 2:
			(*confederacion2)++;
			break;
		case 3:
			(*confederacion3)++;
			break;
		case 4:
			(*confederacion4)++;
			break;
		case 5:
			(*confederacion5)++;
			break;
		case 6:
			(*confederacion6)++;;
			break;
		}
	}
	return retorno;
}
float CalculaPromedioConferencia (int *confederacion, int sizeJugadores)
{
	float promedioConferencia;

	if(*confederacion > 0 && sizeJugadores>0)
		{
		promedioConferencia= (*confederacion *100)/sizeJugadores;
		}
		else
		{
			promedioConferencia=-1;
		}
	return promedioConferencia;
}
void ImprimePromediosConferencia(float promedio)
{
	if(promedio>0)
	{
		printf("Promedio de Conferencia %2.f\n", promedio);
	}
	else
	{
		printf("No hay jugadores de esta conferencia\n");
	}
}
