/*
 * confederaciones.c
 *
 *  Created on: 23-10-2022
 *      Author: Ignacio Pereyra
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederaciones.h"
#include "jugador.h"
#include "informes.h"
#include "utnValidaciones.h"

int MuestraMenuInicio(void)
{
	int numeroIngresado;

				utn_getNumero(&numeroIngresado,"1- Alta de Jugador \n""2- Baja de Jugador \n""3- Modificacion de Jugador\n""4-  Informes \n""5- Salir \n","Opcion Incorrecta\n", 1,5,3);
return numeroIngresado;
}
int MuestraMenuInformes(void)
{
	int numeroIngresado;

				utn_getNumero(&numeroIngresado,"1- Listado Jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador\n"
						"2- Listado de confederaciones con sus jugadores\n""3- Total y promedio de salarios y jugadores que mas cobran del salario promedio\n"
						"4-  Confederacion con mayor cantidad de años de contrato \n""5- Porcentaje de confederaciones por cada jugador\n""6- Region con mas jugadores y listado de ellos\n"
						"7- Salir\n","Opcion Incorrecta\n", 1,7,3);
return numeroIngresado;
}
int buscaId(eConfederaciones confederaciones[],int tamConfe,int id)
{

		int retorno=1;

		for (int i=0; i<tamConfe; i++)
		{
			if(confederaciones[i].id==id)
			{
				retorno=0;
				break;
			}
		}
		return retorno;
}
int devuelveIdConfederacion(eConfederaciones confederaciones[],int tamConfe,int id)
{

		int retorno=1;

		for (int i=0; i<tamConfe; i++)
		{
			if(confederaciones[i].id==id)
			{
				retorno=i;
				break;
			}
		}
		return retorno;
}
void imprimeConfederaciones(eConfederaciones conferederaciones[], int tamConfe)
{
	printf("ID CONFERENCIA   |  NOMBRE    |   REGION		  |	 AÑO CREACION \n");
	for(int i=0; i<tamConfe; i++)
	{

		printf("  %3d     	   %-10s    %-22s   	%4d\n",conferederaciones[i].id,conferederaciones[i].nombre,conferederaciones[i].region,conferederaciones[i].anioCreacion);

	}
}
void ordenaConferenciasAlfabetico(eConfederaciones confederacion[],int tamConfe)
{
	int flagSwapDos;
	eConfederaciones confeAux;
	do{
		flagSwapDos=0;
			for(int j=0; j<tamConfe-1; j++)
			{
				if(strncmp(confederacion[j].nombre, confederacion[j+1].nombre,LARGO)>0)
					{

						flagSwapDos=1;
						confeAux = confederacion[j];
				//	printf("%s\n",confeAux.nombre);
						confederacion[j] = confederacion[j+1];
					//	printf("%s\n",confederacion[j].nombre);

						confederacion[j+1] = confeAux;

						//printf("%s\n",confederacion[j+1].nombre);


					}
			}
			tamConfe--;
		}while(flagSwapDos);
}


