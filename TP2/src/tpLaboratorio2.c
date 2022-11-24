 /*
 ============================================================================
 Name        : tpLaboratorio2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnValidaciones.h"
#include "jugador.h"
#include "informes.h"
#include "confederaciones.h"



#define TAM 12



int main(void) {
	setbuf(stdout,NULL);

int respuestaMenuInicio;
int respuestaMenuInformes;
int confirmaSalida;
int banderaInformes=1;
int indice;
int acumuladorJugadoresUEFA;
int acumuladorJugadoresCONMEBOL;
int acumuladorJugadoresCONCACAF;
int acumuladorJugadoresAFC;
int acumuladorJugadoresCAF;
int acumuladorJugadoresOFC;

int acumuladorAniosUEFA;
int acumuladorAniosCONMEBOL;
int acumuladorAniosCONCACAF;
int acumuladorAniosAFC;
int acumuladorAniosCAF;
int acumuladorAniosOFC;

 acumuladorAniosUEFA=0;
 acumuladorAniosCONMEBOL=0;
 acumuladorAniosCONCACAF=0;
 acumuladorAniosAFC=0;
 acumuladorAniosCAF=0;
 acumuladorAniosOFC=0;

 acumuladorJugadoresUEFA=0;
 acumuladorJugadoresCONMEBOL=0;
 acumuladorJugadoresCONCACAF=0;
 acumuladorJugadoresAFC=0;
 acumuladorJugadoresCAF=0;
 acumuladorJugadoresOFC=0;

	int idIncremental=0;

	eJugador jugadores[TAM]={
								{1,"Lionel Messi", "Extremo",10,101,10000.20,2,0},
								{2,"Sergio Ramos", "Defensor",4,101,9990.20,2,0},
								{3,"Ariel Ortega", "Delantero",7,100,1940.20,5,0},
								{4,"Angel Comizzo", "Arquero",1,104,1230.66,1,0},
								{5,"Marcelo Diaz", "Mediocampista",16,102,1055.50,3,0},
								{6,"Juan Roman Riquelme", "Enganche",10,100,15190.66,2,0},
								{7,"Juan Jose Serrizuela", "Defensor",4,100,2300.66,3,0},
								{8,"Sebastian Veron", "Mediocamista",11,100,1730.66,5,0},
								{9,"Ronaldinho", "Enganche",80,104,9985.66,1,0},
								{10,"Victor Valdes", "Arquero",12,101,13030.66,1,0},
								{11,"Carlos Vela", "Delantero",18,105,10230.66,2,0},
								{12,"Marquinhos", "Defensa",16,100,8963.66,6,0}
							};


	eConfederaciones confederacion[CANTIDAD_CONFE]={
													{100,"CONMEBOL","SUDAMERICA",1916},
													{101,"UEFA","EUROPA",1954},
													{102,"AFC","ASIA",1954},
													{103,"CAF","AFRICA",1957},
													{104,"CONCACAF","NORTE Y CENTRO AMERICA", 1961},
													{105,"OFC","OCEANIA",1966}
												};

	//inicializaJugador(jugadores, TAM);
	imprime(jugadores, TAM, confederacion, CANTIDAD_CONFE);

	do{
		respuestaMenuInicio=MuestraMenuInicio();

		switch(respuestaMenuInicio)
		{
			case 1:
				if(!altaJugador(jugadores, TAM, &idIncremental, confederacion, CANTIDAD_CONFE, buscaLugarLibre(jugadores,TAM)))
				{
					banderaInformes=0;
				}
				break;

			case 2:
					if(!verificaQueHayaJugadoresCargados(jugadores,TAM))
					{
						imprimeJugadorYId(jugadores, TAM);
						utn_getNumero(&indice, "Ingrese el id \n", "Error en el ingreso\n",0, 3000, 2);
						if(buscaIdJugador(jugadores,TAM,indice)==-1)
						{
							printf("Id no cargado\n");
						}
						else
						{
								bajaJugador(jugadores, TAM, indice);
						}
					}
					else
						{
							printf("No hay jugadores ingresados\n");

						}
				break;
			case 3:
				if(!verificaQueHayaJugadoresCargados(jugadores,TAM))
				{
					imprimeJugadorYId(jugadores, TAM);
					utn_getNumero(&indice, "Ingrese el id \n", "Error en el ingreso\n",0, 3000, 2);
					if(buscaIdJugador(jugadores,TAM,indice)==-1)
					{
						printf("Id no cargado\n");
					}
					else
					{
							modificaJugador(jugadores, TAM, confederacion, CANTIDAD_CONFE, indice);
					}
				}
				else
				{
					printf("No hay jugadores ingresados\n");

				}
				break;
			case 4:
				if(!verificaQueHayaJugadoresCargados(jugadores,TAM))
				{
					acumulaJugadoresYAniosSueldosPorConferencia(jugadores,TAM,&acumuladorJugadoresCONMEBOL,&acumuladorJugadoresUEFA,&acumuladorJugadoresAFC,&acumuladorJugadoresCAF,
							&acumuladorJugadoresCONCACAF,&acumuladorJugadoresOFC,&acumuladorAniosCONMEBOL,&acumuladorAniosUEFA,&acumuladorAniosAFC,&acumuladorAniosCAF,
							&acumuladorAniosCONCACAF,&acumuladorAniosOFC);
					do{
							respuestaMenuInformes=MuestraMenuInformes();
							switch(respuestaMenuInformes)
							{
								case 1:
									ordenaPorDosCriteriosAlfabeticos(jugadores,TAM,confederacion, CANTIDAD_CONFE);
									//
									break;
								case 2:
									imprimeConfederacionYJugadoresDeLaMisma(jugadores,TAM,confederacion, CANTIDAD_CONFE);
									break;
								case 3:
									calculaPromedioSalarios(jugadores, TAM,confederacion,CANTIDAD_CONFE);
									break;
								case 4:
									calculaMayorCantidadDeAniosEnContratos(acumuladorAniosCONMEBOL,acumuladorAniosUEFA,acumuladorAniosAFC,acumuladorAniosCAF,
											acumuladorAniosCONCACAF,acumuladorAniosOFC);
									break;
								case 5:
									informaPorcentajeConfederaciones(acumuladorJugadoresUEFA,acumuladorJugadoresCONMEBOL,acumuladorJugadoresAFC,acumuladorJugadoresCAF,
											acumuladorJugadoresCONCACAF,acumuladorJugadoresOFC);
									break;
								case 6:
									mayorNumeroJugadoresPorRegion(jugadores,TAM,acumuladorJugadoresUEFA,acumuladorJugadoresCONMEBOL,acumuladorJugadoresAFC,acumuladorJugadoresCAF,
											acumuladorJugadoresCONCACAF,acumuladorJugadoresOFC,confederacion,CANTIDAD_CONFE);
									break;
							}
						}while(respuestaMenuInformes !=7);
				}
				else
				{
					printf("No se ingresaron jugadores\n");
				}
				break;
			case 5:
				printf("Confirma salida? 1-Si  2-No\n");
				if(!utn_getNumero(&confirmaSalida, "Confirma Salida? 1-Si, 2-No\n", "Error en la opcion", 1, 2, 3) && confirmaSalida==1)
				{
					respuestaMenuInicio=6;
				}
			break;
		}
		}while(respuestaMenuInicio!=6);
	return EXIT_SUCCESS;
}
