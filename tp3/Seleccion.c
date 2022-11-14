#include "Seleccion.h"

Seleccion* selec_new()
{

	Seleccion *unaSeleccion= NULL;
	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
	return unaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion *unaSeleccion = NULL;
	unaSeleccion = selec_new();
	int bufferId;

		if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
		{
			bufferId = atoi(idStr);
			unaSeleccion->id = bufferId;
			strncpy(unaSeleccion->pais,paisStr,LARGE_SELEC);
			strncpy(unaSeleccion->confederacion,confederacionStr,LARGE_SELEC);
			unaSeleccion->convocados = atoi (convocadosStr);

		}
			else
			{
				free(unaSeleccion);
				unaSeleccion = NULL;
			}

return unaSeleccion;
}





int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

return retorno;
}





int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;
	if(this != NULL && pais != NULL)
	{
		strncpy(pais,this->pais,LARGE_SELEC);
		retorno = 0;
	}

return retorno;
}




int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;
	if(this != NULL && confederacion != NULL)
	{

		strncpy(confederacion,this->confederacion,LARGE_SELEC);
		retorno=0;
	}
return retorno;
}



int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados > 0)
	{

		this->convocados = convocados;
		retorno = 0;
	}

return retorno;
}


int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;
	if(this != NULL && convocados != NULL)
	{

		*convocados = this->convocados;
		retorno=0;
	}
return retorno;
}


int retornaIndiceListaSeleccion(LinkedList* pArrayListSeleccion,int id)
{
	int maximoLista;
	int bufferid;
	int retorno=-1;
	Seleccion *unaSeleccion;

	maximoLista=ll_len(pArrayListSeleccion);
	if(pArrayListSeleccion != NULL && id>0)
	{

		for(int i=0; i<maximoLista; i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion,i); // aux buffer	Unjugador le cargo un jugador a un jugador en el indice I
			selec_getId(unaSeleccion, &bufferid); // no hace falta el indice en UNJUGADOR porque ya sabe de que jugudaro estamos tomando
			if(id==bufferid)
			{
				retorno=i;
				break;
			}
		}
	}
return retorno;
}

int muestraListados(int opcion,LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	int retorno=1;
	if(opcion > 0)
	{

		switch(opcion)
		{
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 3:
				listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
				break;
				retorno=0;
		}
	}
return retorno;
}
int ordenamientoYListado(int opcion,LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{

	int retorno=1;
	if(opcion > 0)
	{
		//do{
			switch(opcion)
			{
				case 1:
					controller_listarJugadores(pArrayListJugador);
					break;
				case 2:
					controller_listarSelecciones(pArrayListSeleccion);
					break;
				case 3:
					listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion);
					break;
				case 4:
//						listarJugadoresConvocados(pArrayListJugador);
					break;
					retorno=0;
			}
		//}while(opcion != 5);
	}
return retorno;
}

