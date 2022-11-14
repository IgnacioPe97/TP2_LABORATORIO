/*
 * menus.c
 *
 *  Created on: 06-11-2022
 *      Author: Ignacio Pereyra
 */
#include "menus.h"



int MuestraMenuInicio(void)
{
	int numeroIngresado;

				utn_getNumero(&numeroIngresado,"1-Carga de archivos  2-Alta de Jugador \n""3- Modificacion de Jugador\n""4- Baja de Jugador \n""5-  Listados \n""6- Convocar Jugadores\n"
						"7- Ordenar y Listar\n""8- Generar archivo Binario\n""9-Cargar archivo binario\n""10- Guardar archivos CSV\n""11- Salir \n"	"\n","Opcion Incorrecta\n", 1,11,3);
return numeroIngresado;
}

int muestraMenuModificarJugador(void)
{
	int numeroIngresado;

					utn_getNumero(&numeroIngresado,"1-Nombre\n  2-Edad\n""3- Posicion\n""4- Nacionalidad\n""5-Salir\n","Opcion Incorrecta\n", 1,5,3);
	return numeroIngresado;
}

int muestraMenuConvocados(void)
{
	int numeroIngresado;

	utn_getNumero(&numeroIngresado, "1-Convocar\n 2- Quitar de Seleccion\n 3-Salir\n", "Error en el ingreso\n",1, 3, 3);

return numeroIngresado;
}

int muestraMenuListados(void)
{

	int numeroIngresado;

		utn_getNumero(&numeroIngresado, "1-Listar Jugadores\n 2- Listar Selecciones\n 3-Listar Jugadores convocados\n 4-Salir\n", "Error en el ingreso\n",1, 4, 3);

	return numeroIngresado;
}
int muestraMenuOrdenarYListar(void)
{
	int numeroIngresado;

			utn_getNumero(&numeroIngresado,
					"1-Ordenar por jugador\n 2- Ordenar por seleccion\n 3- Salir\n", "Error en el ingreso\n",1, 3, 3);

		return numeroIngresado;
}

int muestraMenuOrdenamientoJugadores(void)
{
	int numeroIngresado;
				utn_getNumero(&numeroIngresado,"1-Listar Jugadores x Nacionalidad\n 2- Listar Jugadores por Edad\n 3-Listar jugadores por nombre\n 4-Salir\n", "Error en el ingreso\n",1, 4, 3);

			return numeroIngresado;
}


