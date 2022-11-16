#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "menus.h"
#include "ordenamientos.h"



/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	   FILE * pFile;
	   int retorno=-1;
	   if(path != NULL && pArrayListJugador != NULL)
	   {
		   pFile= fopen(path,"r");
		  if(!parser_JugadorFromText(pFile,pArrayListJugador))
		  {
			  retorno=0;
		  }
	   }
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE * pFile;
	int retorno = 1;
	if(path != NULL && pArrayListJugador != NULL)
	{

		pFile = fopen(path, "rb");
		if(!parser_JugadorFromBinary(pFile,pArrayListJugador))
		{
			retorno=0;
		}
		else
		{
			printf("No se pudo abrir el archivo binario\n");
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador * auxJugador = NULL;
	int retorno=-1;
	char bufferNombreCompleto[NOMBRE_LEN];
	int bufferEdad;
	char bufferPosicion[LARGO_CHAR];
	char bufferNacionalidad[LARGO_CHAR];
	int bufferIdSeleccion=0;
	char idSeleccionAux[20];
	char auxId[30];
	int idIncremental;
	char auxEdad[30];

	idIncremental=371;
	sprintf(idSeleccionAux,"%d",bufferIdSeleccion);
	sprintf(auxId,"%d",idIncremental);

	if(pArrayListJugador != NULL)

	{
		if(!utn_getNombre(bufferNombreCompleto, "Ingrese Nombre completo de Jugador\n", "Error en el ingreso \n", NOMBRE_LEN, 3) &&
			!utn_getNumero(&bufferEdad,"Ingrese Edad de Jugador:\n","Error en el Ingreso\n",15,50,3)&&
			!utn_getNombre(bufferPosicion,"Ingrese posicion del jugador:\n", "Error en el ingreso\n",LARGO_CHAR,3)&&
			!utn_getNombre(bufferNacionalidad,"Ingrese nacionalidad del jugador:\n", "Error en el ingreso\n",LARGO_CHAR,3))
			{
				sprintf(auxEdad,"%d",bufferEdad);

				auxJugador = jug_newParametros(auxId,bufferNombreCompleto,auxEdad,bufferPosicion,bufferNacionalidad,idSeleccionAux);
				if(auxJugador != NULL)
				{

					idIncremental++;
					ll_add(pArrayListJugador,auxJugador);
					retorno=0;
				}
				else
				{
					free(auxJugador);
					retorno=1;
				}
			}
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{

	int idBuscado;
	int retorno=1;
	int maximo;
	int indice;
	maximo = ll_len(pArrayListJugador);
	Jugador *unJugador;
	controller_listarJugadores(pArrayListJugador);
	if(!utn_getNumero(&idBuscado, "Ingrese ID de jugador a modificar\n", "Error en el ingreso\n", 1, maximo, 3))
	{
		indice=retornaIndiceLista(pArrayListJugador,idBuscado);
		if(indice >= 0)
		{
			unJugador = ll_get(pArrayListJugador,indice);
			if(unJugador != NULL)
				{

					if(!modificaJugador(unJugador))
					{
						retorno=0;
					}
					else
					{
						printf("No se pudo modificar jugador\n");
					}
				}
		}
	}
    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int idBuscado;
	int retorno=1;
	int indice;
	Jugador *unJugador;
	controller_listarJugadores(pArrayListJugador);
	if(!utn_getNumero(&idBuscado, "Ingrese ID de jugador a modificar\n","Error en el ingreso\n", 1, 1000, 3))
	{
		indice=retornaIndiceLista(pArrayListJugador,idBuscado);
		if(indice >= 0)
		{
			unJugador = ll_get(pArrayListJugador,indice);
			if(unJugador != NULL)
			{
				ll_remove(pArrayListJugador, indice);
				retorno=0;
			}
		}
	}
  return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int size;
	int retorno=-1;
	char nombreCargado[100];
	char posicionCargada[30];
	char nacionalidadCargada[30];
	int edadCargada;
	int idCargado;

	Jugador *jugadorAux = NULL;
	size =  ll_len(pArrayListJugador);
	for(int i=0; i<size; i++)
	{
		jugadorAux =  ll_get(pArrayListJugador,i);
		if(jugadorAux != NULL)
		{
			jug_getNacionalidad(jugadorAux, nacionalidadCargada);
			jug_getNombreCompleto(jugadorAux, nombreCargado);
			jug_getPosicion(jugadorAux, posicionCargada);
			jug_getId(jugadorAux, &idCargado);
			jug_getEdad(jugadorAux, &edadCargada);


			printf("%4d  %30s  %3d  %20s  %30s\n", idCargado,nombreCargado,edadCargada,posicionCargada,nacionalidadCargada);
			retorno=0;

		}
	}
    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int opcion;
	int order;
	int retorno=1;
	if(pArrayListJugador != NULL)
	{
		LinkedList* listaAux = ll_newLinkedList();
		listaAux  = ll_clone(pArrayListJugador);

			opcion = muestraMenuOrdenamientoJugadores();
			switch(opcion)
			{
				case 1:
					if(!utn_getNumero(&order, "1-Ascendente\n 2-Descendente\n", "Error en el ingreso\n",1, 2, 3))
					{
						if(order==2)
						{
							order=0;
						}

							ll_sort(listaAux,ordenaPorNacionalidadJugadores,order);
							controller_listarJugadores(listaAux);
					}
					break;
				case 2:
					if(!utn_getNumero(&order, "1-Ascendente\n 2-Descendente\n", "Error en el ingreso\n",1, 2, 3))
							{
								if(order==2)
								{
									order=0;
								}
									ll_sort(listaAux, ordenaPorEdadJugadores,order);
									controller_listarJugadores(listaAux);

							}
					break;
				case 3:
					if(!utn_getNumero(&order, "1-Ascendente\n 2-Descendente\n", "Error en el ingreso\n",1, 2, 3))
							{
								if(order==2)
								{
									order=0;
								}
									ll_sort(listaAux, ordenaPorNombreJugadores,order);
									controller_listarJugadores(listaAux);

							}
					break;
					retorno=0;
					ll_clear(listaAux);
					ll_deleteLinkedList(listaAux);

			}
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=1;
	int size;
	int bufferId;
	char bufferNombreCompleto[NOMBRE_LEN];
	int bufferEdad;
	char bufferPosicion[LARGO_CHAR];
	char bufferNacionalidad[LARGO_CHAR];
	int bufferIdSeleccion;
	FILE *pFile;
	Jugador * unJugador;
	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno=0;
			size = ll_len(pArrayListJugador);
			for(int i=0; i<size; i++)
			{
				unJugador =  ll_get(pArrayListJugador, i);
				if(!jug_getId(unJugador, &bufferId) && !jug_getNombreCompleto(unJugador, bufferNombreCompleto) && !jug_getEdad(unJugador, &bufferEdad)
						&& !jug_getPosicion(unJugador, bufferPosicion) && !jug_getNacionalidad(unJugador, bufferNacionalidad) && !jug_getSIdSeleccion(unJugador, &bufferIdSeleccion))
				{
					fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",bufferId,bufferNombreCompleto,bufferEdad,bufferPosicion,bufferNacionalidad,bufferIdSeleccion);
				}
			}
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	   FILE * pFile;
	   int retorno;
	   int sizeConvocados;
	   Jugador * unJugador;
	   LinkedList * listaConvocados = ll_newLinkedList();

	   if(path != NULL && pArrayListJugador != NULL)
	   {
		   listaConvocadosBinario(listaConvocados,pArrayListJugador);

		   if(listaConvocados != NULL)
		   {
			   pFile = fopen(path, "wb");
			   if(pFile != NULL)
			   {
				   sizeConvocados = ll_len(listaConvocados);

				   for(int j=0; j<sizeConvocados; j++)
					   {
					   	   unJugador = ll_get(listaConvocados, j);
					   	   if(unJugador != NULL)
					   	   {
							   fwrite(unJugador,sizeof(Jugador),1,pFile);
							   retorno=0;
					   	   }
					   }
			   }
			   else
			   {
				   printf("No se pudo escribir el archivo \n");
			   }
			   fclose(pFile);
		   }
	   }
    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE *pArchivo;
	int retorno=-1;

	   if(path != NULL && pArrayListSeleccion != NULL)
	   {
		   pArchivo= fopen(path,"r");
		  if(!parser_SeleccionFromText(pArchivo,pArrayListSeleccion))
		  {
			  retorno=0;
		  }
	   }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int size;
	int retorno=1;

		Seleccion * unaSeleccion;
		size =  ll_len(pArrayListSeleccion);
		if(pArrayListSeleccion != NULL)
		{
			for(int i=0; i<size; i++)
					{
						unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion,i);
						if(unaSeleccion != NULL)
						{
							printf("%4d  %30s  %20s  %3d\n", unaSeleccion->id,unaSeleccion->pais,unaSeleccion->confederacion,unaSeleccion->convocados);
							retorno=0;
						}
					}
		}
	    return retorno;
}



/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno;
	int order;
	if(pArrayListSeleccion != NULL)

	{
		LinkedList * listaAux = ll_clone(pArrayListSeleccion);

		if(!utn_getNumero(&order, "1-Descendente\n 2-Ascendente\n", "Error en el ingreso\n",1, 2, 3))
		{
			if(order==2)
			{
				order=0;
			}
			ll_sort(pArrayListSeleccion, ordenaPorConfederacionSelecciones, order);
			controller_listarSelecciones(listaAux);
			ll_clear(listaAux);
			ll_deleteLinkedList(listaAux);
			retorno=0;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


