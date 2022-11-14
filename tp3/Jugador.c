#include "Jugador.h"


static int isValidNombre(char *cadena, int limite);

//static int isValidNumber(char *cadena, int limite);

/**
 * @brief crea espacio en memoria para la estrucura Jugador
 *
 * @return
 */
Jugador* jug_new()
{
	Jugador *unJugador = NULL;
	unJugador = (Jugador*)calloc(sizeof(Jugador),1);
//	char aux[20];
//	unJugador->edad = 0;
//	unJugador->id=0;
//	strncpy(unJugador->nombreCompleto,aux, NOMBRE_LEN);
//	strncpy(unJugador->nacionalidad,aux, LARGO_CHAR);
//	strncpy(unJugador->posicion,aux, LARGO_CHAR);
//	unJugador->idSeleccion=0;


	return unJugador;
}

/**
 * @brief CREA UN JUGADOR CON PARAMETROS
 *
 * @param idStr
 * @param nombreCompletoStr
 * @param edadStr
 * @param posicionStr
 * @param nacionalidadStr
 * @param idSelccionStr
 * @return retorna jugador cargado
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador *unJugador;
	unJugador = jug_new();



	if(unJugador!=NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{



		if(
			!jug_setNombreCompleto(unJugador,nombreCompletoStr)&&
			!jug_setPosicion(unJugador,posicionStr) &&
			!jug_setNacionalidad(unJugador,nacionalidadStr)&&
			!jug_setEdadTxt(unJugador,edadStr)&&
			!jug_setIdTxt(unJugador,idStr) &&
			!jug_setIdSeleccionTxt(unJugador,idSelccionStr))
		{

		}

	}
	return unJugador;
}


/**
 * @brief Setea el id
 *
 * @param this
 * @param id
 * @return
 */
int jug_setId(Jugador* this,int id)
{
	int retorno = 1;
		if(this != NULL && id >= 0)
		{
				this->id = id;
				retorno=0;

		}
	return retorno;
}
/**
 * @brief transforma el id qeu viene como txto a un numero
 *
 * @param this
 * @param id
 * @return
 */
int jug_setIdTxt(Jugador* this,char* id)
{
	int retorno = 1;
	int bufferId;
		if(this != NULL && id != NULL)
		{
				bufferId = atoi(id);
				this->id = bufferId;
				retorno=0;

		}
	return retorno;
}
/**
 * @brief setea la edad que viene en formato texto a numero
 *
 * @param this
 * @param edad
 * @return
 */
int jug_setEdadTxt(Jugador* this,char* edad)
{
	int retorno = 1;
	int bufferEdad;
		if(this != NULL && edad != NULL)
		{
				bufferEdad = atoi(edad);
				this->edad = bufferEdad;
				retorno=0;

		}
	return retorno;
}
/**
 * @brief transforma el idSeleccion que viene ne formato char a numero y lo setea
 *
 * @param this
 * @param idSeleccion
 * @return
 */
int jug_setIdSeleccionTxt(Jugador* this,char* idSeleccion)
{
	int retorno = 1;
	int bufferIdSeleccion;
		if(this != NULL && idSeleccion != NULL)
		{
			bufferIdSeleccion = atoi(idSeleccion);
				this->idSeleccion = bufferIdSeleccion;
				retorno=0;
		}
	return retorno;
}
/**
 * @brief obtiene el id del jkugador
 *
 * @param this
 * @param id
 * @return
 */
int jug_getId(Jugador* this,int* id)
{
	int retorno=1;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno=0;
	}
return retorno;
}
/**
 * @brief obtiene la edad del jugador
 *
 * @param this
 * @param edad
 * @return
 */
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=1;

	if(this != NULL && edad != NULL)
	{
		*edad=this->edad;
		retorno=0;
	}
return retorno;
}



int cambiaNumeroPorTexto(int numero, char* cadena)
{
	int retorno=1;

	if(cadena != NULL)
	{
		sprintf(cadena,"%d",numero);
		retorno=0;
	}
return retorno;
}
/**
 * @brief  setea la edad del jugador
 *
 * @param this
 * @param edad
 * @return
 */

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 1;
			if(this != NULL && edad > 17 && edad < 50)
			{
				this->edad = edad;
				retorno=0;

			}
return retorno;
}

/**
 * @brief obtiene el indice del jugador por medio del ID
 *
 * @param pArrayListJugador
 * @param id
 * @return
 */
int retornaIndiceLista(LinkedList* pArrayListJugador,int id)
{
	int maximoLista;
	int bufferid;
	int retorno=1;
	Jugador *unJugador;

	maximoLista=ll_len(pArrayListJugador);
	if(pArrayListJugador != NULL && id>0)
	{

		for(int i=0; i<maximoLista; i++)
		{
			unJugador = ll_get(pArrayListJugador, i); // aux buffer	Unjugador le cargo un jugador a un jugador en el indice I
			jug_getId(unJugador, &bufferid); // no hace falta el indice en UNJUGADOR porque ya sabe de que jugudaro estamos tomando
			if(id==bufferid)
			{
				retorno=i;
				break;
			}
		}
	}
return retorno;
}


/**
 * @brief setea el nombre el jjugador y valida que sea un nombre
 *
 * @param this
 * @param nombreCompleto
 * @return
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 1;
	char auxNombre[100];
		if(this != NULL && nombreCompleto != NULL)
		{
			if(!isValidNombre(nombreCompleto,NOMBRE_LEN))
			{

				strncpy(auxNombre,nombreCompleto,NOMBRE_LEN);
				if(!cambaInicialNombreMayuscula(auxNombre))
				{
					strncpy(this->nombreCompleto,auxNombre,NOMBRE_LEN);
					retorno=0;
				}
			}
		}
return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=1;
				if(this != NULL)
				{
					this->idSeleccion = idSeleccion;
					retorno=0;

				}
	return retorno;




}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=1;

		if(this != NULL && idSeleccion != NULL)
		{
			*idSeleccion=this->idSeleccion;
			retorno=0;
		}
	return retorno;
}


/**
 * @brief transforma a mayuscula la primera letra del nombre y tambien del apellido
 *
 * @param cadena
 * @return
 */
int cambaInicialNombreMayuscula(char*cadena)
{
int retorno=1;
char auxCad[100];
	if(cadena != NULL)
	{
		strncpy(auxCad,cadena,100);
		for(int i=0; auxCad[i] != '\0'; i++)
		{
			auxCad[0] = toupper(auxCad[0]);
			if((auxCad[i] == ' ') && (auxCad[i-1] >= 'a' || auxCad[i-1] <= 'z') && (auxCad[i+1] >= 'a' || auxCad[i+1] <= 'z' ))
			{
				auxCad[i+1] = toupper(auxCad[i+1]);
			}
		}
		strncpy(cadena,auxCad,100);
		retorno = 0;
	}
return retorno;
}

/**
 * @brief obtiene el nombre del jugador
 *
 * @param this
 * @param nombreCompleto
 * @return
 */

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 1;
		if(this != NULL && nombreCompleto != NULL)
		{

				strncpy(nombreCompleto,this->nombreCompleto,NOMBRE_LEN);
				retorno=0;

		}
return retorno;
}


/**
 * @brief lista un jugador
 *
 * @param pArrayListJugador
 * @param id
 * @return
 */
int listaUnJugador(LinkedList* pArrayListJugador, int id)
{
	int retorno = 1;
	int indice;
	int idJugador;
	int edadJugador;
	char nombreCompleto[100];
	char posicionJugador[30];
	char nacionalidad[30];
	Jugador * unJugador;
	if(pArrayListJugador != NULL && id>=0)
	{
		indice = retornaIndiceLista(pArrayListJugador, id);

		unJugador = ll_get(pArrayListJugador, indice);
		if(unJugador != NULL)
		{
			jug_getId(unJugador, &idJugador);
			jug_getEdad(unJugador, &edadJugador);
			jug_getNombreCompleto(unJugador, nombreCompleto);
			jug_getPosicion(unJugador, posicionJugador);
			jug_getNacionalidad(unJugador, nacionalidad);
			printf("%d  %s  %d  %s  %s\n",idJugador,nombreCompleto,edadJugador,posicionJugador,nacionalidad);
			retorno=0;
		}
		else
		{
			printf("NO HAY JUGADOR\n");
		}
	}
	return retorno;
}


/**
 * @brief valida que sea una cadena
 *
 * @param cadena
 * @param limite
 * @return
 */

static int isValidNombre(char *cadena, int limite)
{
	int i;
	int retorno = 1;
	if (cadena != NULL && limite > 0)
	{
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{

			if((cadena[i]>='a'|| cadena[i]<='z') && (cadena [i]>='A' || cadena[i]<='Z') && cadena[i] != ' ')
			{
				retorno=0;
				break;
			}

		}
	}
	return retorno;
}

/**
 * @brief setea la posicion del jugador
 *
 * @param this
 * @param posicion
 * @return
 */


int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 1;
			if(this != NULL && posicion != NULL)
			{
				if(!isValidNombre(posicion,LARGO_CHAR))
				{
					strncpy(this->posicion,posicion,LARGO_CHAR);
					retorno=0;

				}
			}
	return retorno;
}


/**
 * @brief obtiene la posicion del jugador
 *
 * @param this
 * @param posicion
 * @return
 */

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 1;
		if(this != NULL && posicion != NULL)
		{
			strncpy(posicion,this->posicion,LARGO_CHAR);
			retorno=0;

		}
return retorno;
}


/**
 * @brief setea la nacionalidad del jugador
 *
 * @param this
 * @param nacionalidad
 * @return
 */

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 1;
			if(this != NULL && nacionalidad != NULL)
			{
				if(!isValidNombre(nacionalidad,LARGO_CHAR))
				{
					strncpy(this->nacionalidad,nacionalidad,LARGO_CHAR);
					retorno=0;

				}
			}
	return retorno;
}


/**
 * @brief obtiene nacionalidad de jugador
 *
 * @param this
 * @param nacionalidad
 * @return
 */

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 1;
		if(this != NULL && nacionalidad != NULL)
		{
			strncpy(nacionalidad,this->nacionalidad,LARGO_CHAR);
			retorno=0;

		}
return retorno;
}


/**
 * @brief elimita un jugador
 *
 * @param jugador
 */

void jug_delete(Jugador* jugador)
{
	if(jugador != NULL)
	{
		free(jugador);
	}
}


/**
 * @brief modifica un jugador y cambia sus campos a traves de los getters y setters
 *
 * @param this
 * @return
 */

int modificaJugador(Jugador *this)
{
	int retorno=1;
	int option;
	char nombreCompleto[100];
	char auxNombreCompleto[100];
	int edad;
	int edadAux;
	char posicion[30];
	char auxPosicion[30];
	char nacionalidad[30];
	char auxNacionalidad[30];
	if(this != NULL)
	{
		do{
				option = muestraMenuModificarJugador();

						switch(option)
						{
							case 1:
								jug_getNombreCompleto(this,nombreCompleto);
								printf("El nombre que cambiara es %s\n",nombreCompleto);
								utn_getNombre(auxNombreCompleto,"Ingrese Nombre completo\n","Error en el ingreso", sizeof(auxNombreCompleto), 5);
								jug_setNombreCompleto(this, auxNombreCompleto);
								retorno=0;

								break;
							case 2:
								jug_getEdad(this, &edad);
								printf("edad a modificar es %d\n",edad);
								utn_getNumero(&edadAux, "Ingrese nueva edad\n", "Error en el ingreso\n", 16, 50, 2);
								jug_setEdad(this, edadAux);
								retorno=0;

									break;
							case 3:
								jug_getPosicion(this, posicion);
								printf("posicion a modificar %s\n", posicion);
								utn_getNombre(auxPosicion, "Ingrese nueva posicion\n", "Error en el ingreso\n", sizeof(auxPosicion), 3);
								jug_setPosicion(this, auxPosicion);
								retorno=0;

									break;
							case 4:
								jug_getNacionalidad(this, nacionalidad);
								printf("Nacionalidad a modificar es %s\n",nacionalidad);
								utn_getNombre(auxNacionalidad, "Ingrese nueva nacionalidad\n", "Error en el ingreso", sizeof(auxNacionalidad), 3);
								jug_setNacionalidad(this, auxNacionalidad);
								retorno=0;

									break;
						}
				}while(option!=5);
	}
	return retorno;
}

/**
 * @brief asigna id de selecciones a jugadores y los convoca
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return 0 exito 1 un fracaso
 */
int convocaYSacaJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int opcion;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		do{
				opcion = muestraMenuConvocados();
				switch(opcion)
				{
					case 1:
						if(!convocacionJugadores(pArrayListJugador,pArrayListSeleccion))
						{
							printf("La convocacion fue un exito\n");
							retorno = 0;

						}
						else
						{
							printf("La convocacion fue FRACASO\n");
							retorno = 1;

						}
						break;
					case 2:
						quitaJugadoresDeSeleccion(pArrayListJugador,pArrayListSeleccion);
						break;
				}

		}while(opcion !=3);
	}

return retorno;
}
/**
 * @brief quita jugadores de seleccion asignada, les devuelve el valor de 0 en el idSeleccion
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return 0 si funciono y 1 si fracaso
 */
int quitaJugadoresDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int idAux;
	int maximo;
	int indice;
	int idSelec;
	int indiceSeleccion;
	int convocados;
	int idCero;
	idCero=0;

	Jugador * unJugador;
	Seleccion * unaSeleccion;
	maximo = ll_len(pArrayListJugador);

	listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
	utn_getNumero(&idAux, "Ingrese el ID de jugador a quitar\n", "Error en el ingreso\n", 1, maximo, 3);
	indice = retornaIndiceLista(pArrayListJugador, idAux);

	unJugador = ll_get(pArrayListJugador, indice);
	jug_getSIdSeleccion(unJugador, &idSelec);

	if(unJugador != NULL)
	{
		indiceSeleccion = retornaIndiceListaSeleccion(pArrayListSeleccion, idSelec);
		unaSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);
		selec_getConvocados(unaSeleccion, &convocados);
		if(unaSeleccion != NULL && convocados > 0)
		{
			convocados--;
			selec_setConvocados(unaSeleccion, convocados);
			jug_setIdSeleccion(unJugador,0);
			retorno=0;
		}
		else if(unaSeleccion != NULL && convocados == 0)
		{
			jug_setIdSeleccion(unJugador,idCero);
		}

	}

return retorno;
}

/**
 * @brief obtiene el jugador a convocar y la seleccion a  asignar
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int convocacionJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int idAux;
	int idAuxSelec;
	int indice;
	int indiceSelec;
	 int idJugadorSeleccion;
	 int maximo;
	 int idSelecJugador;
	 int convocados;

	 int maximoSelec;
	 int retorno =-1;

	Jugador *unJugador;
	Seleccion *UnaSeleccion;

		controller_listarJugadores(pArrayListJugador);
		maximo = ll_len(pArrayListJugador);
		maximoSelec = ll_len(pArrayListSeleccion);

					utn_getNumero(&idAux, "Ingrese ID de jugador a convocar\n", "Error en el ingreso\n", 1, maximo, 3);
					indice=retornaIndiceLista(pArrayListJugador,idAux);
					if(indice >= 0)
					{
						unJugador = ll_get(pArrayListJugador,indice);
						jug_getSIdSeleccion(unJugador, &idSelecJugador);
						printf("Id selec %d\n", idSelecJugador);

						if(idSelecJugador==0)
						{
								controller_listarSelecciones(pArrayListSeleccion);
								utn_getNumero(&idAuxSelec, "Ingrese ID de Seleccion a convocar\n", "Error en el ingreso\n", 1, maximoSelec, 3);
								indiceSelec=retornaIndiceListaSeleccion(pArrayListSeleccion,idAuxSelec);
								if(indiceSelec >= 0)
								{
									UnaSeleccion = ll_get(pArrayListSeleccion, indiceSelec);
									selec_getConvocados(UnaSeleccion, &convocados);
								}
								if(UnaSeleccion != NULL && unJugador != NULL && convocados <23 && convocados>=0)
								{
									convocados++;
									selec_getId(UnaSeleccion, &idJugadorSeleccion);
									selec_setConvocados(UnaSeleccion, convocados);

									if(idJugadorSeleccion > 0)
									{
										jug_setIdSeleccion(unJugador, idJugadorSeleccion);
										retorno=0;
									}
								}
								else
								{
									printf("Seleccion con total de jugadores convocados\n");
								}

						}
						else
						{
							printf("Jugador ya convocado\n");
						}

					}

return retorno;
}
/**
 * @brief lista los jugadores convocados
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int listarJugadoresConvocados(LinkedList * pArrayListJugador,LinkedList * pArrayListSeleccion)
{

	int size;
	int sizeSelec;
	int retorno=-1;
	int idSeleccion;
	char nombreCargado[100];
	char posicionCargada[30];
	char nacionalidadCargada[30];
	int edadCargada;
	int idCargado;
	char nombrePais[30];
	int idSele;
	int convocados;
	Jugador *jugadorAux;
	Seleccion * unaSeleccion;


	size =  ll_len(pArrayListJugador);
	sizeSelec =  ll_len(pArrayListSeleccion);
if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
{
	for(int j=0; j<sizeSelec; j++)
	{
		unaSeleccion = ll_get(pArrayListSeleccion,j);
		selec_getPais(unaSeleccion, nombrePais);
		selec_getId(unaSeleccion, &idSele);
		selec_getConvocados(unaSeleccion, &convocados);

		if(unaSeleccion != NULL && convocados > 0)
		{
			for(int i=0; i<size; i++)
			{
				jugadorAux =  ll_get(pArrayListJugador,i);
				jug_getSIdSeleccion(jugadorAux,&idSeleccion);
				if(jugadorAux != NULL && idSeleccion == idSele)
				{
					jug_getNacionalidad(jugadorAux, nacionalidadCargada);
					jug_getNombreCompleto(jugadorAux, nombreCargado);
					jug_getPosicion(jugadorAux, posicionCargada);
					jug_getId(jugadorAux, &idCargado);
					jug_getEdad(jugadorAux, &edadCargada);
					printf("%4d  %30s  %3d  %20s  %30s  %30s\n", idCargado,nombreCargado,edadCargada,posicionCargada,nacionalidadCargada,nombrePais);
					retorno = 0;
				}
			}
		}
	}
}

return retorno;
}
/**
 * @brief asigna a la lista pConvocados los jugadores convocados y los devuelve
 *
 * @param pListaConvocados
 * @param pArrayListJugador
 * @return 0 si fue un exito 1 si fracaso
 */
int listaConvocadosBinario(LinkedList * pListaConvocados, LinkedList* pArrayListJugador)
{
	int size;
	int idSeleccion;
	int retorno=1;
	Jugador * unJugador;

	if(pArrayListJugador != NULL)
	{
		  size = ll_len(pArrayListJugador);
		   for(int i=0; i<size; i++)
		   {
			   unJugador = ll_get(pArrayListJugador, i);
			   jug_getSIdSeleccion(unJugador, &idSeleccion);

			   if(unJugador != NULL && idSeleccion >0 )
			   {
				   ll_add(pListaConvocados, unJugador);
				   retorno = 0;
			   }
		   }
	}
return retorno;
}









