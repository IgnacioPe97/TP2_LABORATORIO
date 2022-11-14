#include "parser.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	char id[15];
	char nombreCompleto[50];
	char edad[10];
	char posicion[50];
	char nacionalidad[50];
	char idSeleccion[20];
	int cantidadLeida;
	Jugador *jugadorAux;
	if(pFile != NULL && pArrayListJugador != NULL)
	{
		cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);


		while(!feof(pFile))
			{
				cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
					if(cantidadLeida==6)
					{
						jugadorAux = jug_newParametros(id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
						if(jugadorAux != NULL)
						{
							ll_add(pArrayListJugador,jugadorAux);

							if(feof(pFile))
							{
								retorno=0;
								break;
							}
						}
					}
			}
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int cantidad;
	int retorno=1;
	Jugador  unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!feof(pFile))
		{
			cantidad = fread(&unJugador,sizeof(Jugador),1,pFile);
			if(cantidad!=6)
			{
				if(feof(pFile))
				{
					retorno=0;
					break;
				}
			}
		}
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{

	int cantidadLeida;
	int retorno=-1;
	char idSeleccion[15];
	char pais[30];
	char confederacion[30];
	char convocados[10];
	Seleccion *unaSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		cantidadLeida = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n",idSeleccion,pais,confederacion,convocados);

		while(!feof(pFile))
		{
			cantidadLeida = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n",idSeleccion,pais,confederacion,convocados);
			if(cantidadLeida==4)
			{
				unaSeleccion = selec_newParametros(idSeleccion,pais,confederacion,convocados);
				retorno=1;
				if(unaSeleccion != NULL)
				{
					ll_add(pArrayListSeleccion,unaSeleccion);
					if(feof(pFile))
					{
						retorno=0;
						break;
					}
				}
			}
		}
	}
    return retorno;
}

