/*
 * ordenamientos.c
 *
 *  Created on: 10-11-2022
 *      Author: Ignacio Pereyra
 */
#include "ordenamientos.h"


int ordenaPorNombreJugadores(void* unJugador , void*  otroJugador)
{
	int retorno = 1;
	char nombrePrimerJugador[NOMBRE_LEN];
	char nombreSegundoJugador[NOMBRE_LEN];





	if(unJugador != NULL && otroJugador !=NULL)
	{
		jug_getNombreCompleto((Jugador*)unJugador, nombrePrimerJugador);
			jug_getNombreCompleto((Jugador*)otroJugador, nombreSegundoJugador);
			retorno = strncmp(nombrePrimerJugador,nombreSegundoJugador,NOMBRE_LEN);
			if(retorno<0)
			{
				retorno=0;
			}
			else if(retorno>0)
			{
				retorno=1;
			}


	}
	return retorno;
}


int ordenaPorNacionalidadJugadores(void* unJugador, void* otroJugador)
{
	int retorno=0;
	int valorDevuelto;
	char nacionalidadPrimerJugador[LARGO_CHAR];
	char nacionalidadSegundoJugador[LARGO_CHAR];


		if(unJugador != NULL && otroJugador !=NULL)
		{
				jug_getNacionalidad((Jugador*)unJugador, nacionalidadPrimerJugador);
				jug_getNacionalidad((Jugador*)otroJugador, nacionalidadSegundoJugador);
				valorDevuelto = strncmp(nacionalidadPrimerJugador,nacionalidadSegundoJugador,LARGO_CHAR);
				if(valorDevuelto<0)
				{
					retorno=-1;
				}
				else if(valorDevuelto>0)
				{
					retorno=1;
				}
		}


	return retorno;
}


int ordenaPorEdadJugadores(void* unJugador, void* otroJugador)
{
	int retorno;
	int edadPrimerJugador;
	int edadSegundoJugador;

	if(unJugador != NULL && otroJugador !=NULL)
	{
		jug_getEdad((Jugador*)unJugador, &edadPrimerJugador);
		jug_getEdad((Jugador*)otroJugador, &edadSegundoJugador);
		if(edadPrimerJugador > edadSegundoJugador)
		{
			retorno = 1;
		}
		else if(edadPrimerJugador < edadSegundoJugador)
		{
			retorno = -1;
		}
		else
		{
			retorno=0;
		}
	}
	return retorno;
}
int ordenaPorConfederacionSelecciones(void* unaSeleccion, void* otraSeleccion)
{
	int retorno;

	char nacionalidadPrimerJugador[LARGO_CHAR];
		char nacionalidadSegundoJugador[LARGO_CHAR];

			if(unaSeleccion != NULL && otraSeleccion !=NULL)
			{
					selec_getConfederacion((Seleccion*)unaSeleccion, nacionalidadPrimerJugador);
					selec_getConfederacion((Seleccion*)otraSeleccion, nacionalidadSegundoJugador);
					retorno = strncmp(nacionalidadPrimerJugador,nacionalidadSegundoJugador,LARGO_CHAR);
					if(retorno<0)
					{
						retorno=-1;
					}
					else if(retorno>0)
					{
						retorno=1;
					}
					else
					{
						retorno=0;
					}
			}
return retorno;
}
