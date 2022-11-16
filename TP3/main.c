#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "menus.h"
#include "ordenamientos.h"



int main()
{
	setbuf(stdout,NULL);
    int option;
    int optionListados;
    int optionOrdenarYListar;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaConvocados = ll_newLinkedList();




    do{
        option=MuestraMenuInicio();

        switch(option)
        {
        case 1:
					if(!controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) &&
						   ! controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones))
					{
						printf("Carga de datos Exitosa\n");
					}


        	break;

            case 2:
							if(!controller_agregarJugador(listaJugadores))
							{
								printf("Se cargo correctamente al jugador\n");
							}
							else
							{
								printf("No se puido cargar al jugador\n");
							}
                break;
            case 3:
            	if(!ll_isEmpty(listaJugadores))
            	{
        			controller_editarJugador(listaJugadores);
            	}
            	else
            	{
            		printf("No hay jugadores en la lista\n");
            	}

            	break;
            case 4:
            	if(!ll_isEmpty(listaJugadores))
            	            	{
            			controller_removerJugador(listaJugadores);
            	    }
            	else
            	{
            		printf("No hay jugadores en la lista\n");

            	}
            	break;
            case 5:
            	if(!ll_isEmpty(listaJugadores))
            	{
					optionListados=muestraMenuListados();
						if(optionListados>0)
						{
							muestraListados(optionListados,listaSelecciones,listaJugadores);
						}
            	}
				else
				{
					printf("No hay jugadores en la lista\n");

				}
            	break;
            case 6:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		convocaYSacaJugadores(listaJugadores,listaSelecciones);

            	}
            	else
            	{
            		printf("No hay jugadores en la lista\n");
            	}

                break;
            case 7:
            	if(!ll_isEmpty(listaJugadores))
            	{
						optionOrdenarYListar=muestraMenuOrdenarYListar();
						if(optionOrdenarYListar ==1)
						{
							controller_ordenarJugadores(listaJugadores);
						}
						else if(optionOrdenarYListar==2)
						{
							controller_ordenarSelecciones(listaSelecciones);
						}
            	}
            	else
				{
					printf("No hay jugadores en la lista\n");
				}

                 break;
            case 8:
            	if(!ll_isEmpty(listaJugadores))
				{
						controller_guardarJugadoresModoBinario("jugadoresConvocados.bin",listaJugadores);
				}
             	else
				{
					printf("No hay jugadores en la lista\n");
				}
            	break;
            case 9:
            	if(!ll_isEmpty(listaJugadores))
				{
					controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin",listaConvocados);
				}
				else
				{
					printf("No hay jugadores en la lista\n");
				}
            	break;
            case 10:
            	if(!ll_isEmpty(listaJugadores))
				{
                	controller_guardarJugadoresModoTexto("jugadoresNacho.csv",listaJugadores);
				}
				else
				{
					printf("No hay jugadores en la lista\n");
				}
            	break;
        }
    }while(option != 11);

    return 0;
}

