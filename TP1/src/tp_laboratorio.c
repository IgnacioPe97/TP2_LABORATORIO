/*
 ============================================================================
 Name        : tp_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "funcionesTP.h"
#include "validacion.h"
#include <stdio.h>
#include <stdlib.h>



int main(void) {
	setbuf(stdout,NULL);
	//COSTOS
	float acumuladorCostoHospedaje;
	acumuladorCostoHospedaje=0;
	float acumuladorCostoComida;
	acumuladorCostoComida=0;
	float acumuladorCostoTransporte;
	acumuladorCostoTransporte=0;
	int mantenimiento=0;
	int mantenimientoConEuropeos;
	int respuestaMenu;
	int respuestaCostos;
	int respuesta;
	//JUGADORES
	int contadorArqueros=0;
	int contadorDefensores=0;
	int contadorVolantes=0;
	int contadorDelanteros=0;
	int acumuladorJugadores;


	//CONFEDERACIONES
	int contadorAsia=0;
	int contadorAfrica=0;
	int contadorConcacaf=0;
	int contadorConmebol=0;
	int contadorUefa=0;
	int contadorOceania=0;
	float promedioAsia;
	float promedioAfrica;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOceania;

	int banderaTres=0;
	int banderaEuropeos=0;

	int respuestaSeguir;
	int respuestaPosicion;
	int respuestaInformes;

	do
	{
		respuestaMenu=MuestraMenuInicioJugadores();
		switch(respuestaMenu)
		{
			case 1:
					do
					{
						utn_getNumero(&respuestaCostos,"Seleccione opcion que quiere ingresar: 1-Hospedaje, 2- Comida, 3- Transporte\n","Error en el ingreso\n",1,3,2);
						switch(respuestaCostos)
						{
							case 1:
								utn_getNumeroConDecimales(&acumuladorCostoHospedaje,"Ingrese el costo de hospedaje\n","Error, vuelva a ingresar:\n", 1,100000,2);
								break;
							case 2:
								utn_getNumeroConDecimales(&acumuladorCostoComida,"Ingrese el costo de Comida\n","Error, vuelva a ingresar\n", 1.0,100000.0,2);
								break;
							case 3:
								utn_getNumeroConDecimales(&acumuladorCostoTransporte,"Ingrese el costo de Transporte\n","Error, vuelva a ingresar\n", 1.0,100000.0,2);
								break;
						}
							printf("1-Costo de Hospedaje -> $ %.2f\n", acumuladorCostoHospedaje);
							printf("2-Costo de Comida -> $ %.2f\n", acumuladorCostoComida);
							printf("3-Costo de Transporte-> $ %.2f\n", acumuladorCostoTransporte);
							mantenimiento=(acumuladorCostoTransporte+acumuladorCostoHospedaje+acumuladorCostoComida);
							utn_getNumero(&respuesta,"Quiere seguir ingresando algun costo? 1-Si 2-No \n","Error, ingrese opcion correcta\n",1,2,2);
					}while(respuesta==1);
				break;
			case 2:
			do{

					utn_getNumero(&respuestaPosicion,"Que posicion quiere ingresar? 1-Arqueros 2-Defensores 3-Volantes 4-Delanteros: \n", "Error, numero incorrecto",1,4,3);
						switch(respuestaPosicion)
								{
									case 1:
											if(contadorArqueros<2)
											{
												contadorArqueros++;
												CargaConferencia(&contadorAsia,&contadorAfrica,&contadorConcacaf,&contadorConmebol,&contadorUefa,&contadorOceania);
											}
											else
											{
												printf("Ya estan completos los arqueros\n");
											}
									break;
									case 2:
											if(contadorDefensores<8)
											{
												contadorDefensores++;
												CargaConferencia(&contadorAsia,&contadorAfrica,&contadorConcacaf,&contadorConmebol,&contadorUefa,&contadorOceania);
											}
											else
											{
												printf("Ya estan completos los Defensores\n");
											}
									break;
									case 3:
											if(contadorVolantes<8)
											{
												contadorVolantes++;
												CargaConferencia(&contadorAsia,&contadorAfrica,&contadorConcacaf,&contadorConmebol,&contadorUefa,&contadorOceania);
											}
											else
											{
												printf("Ya estan completos los volantes\n");
											}
									break;
									case 4:
											if(contadorDelanteros<4)
											{
												contadorDelanteros++;
												CargaConferencia(&contadorAsia,&contadorAfrica,&contadorConcacaf,&contadorConmebol,&contadorUefa,&contadorOceania);
											}
											else
											{
												printf("Ya estan completos los Delanteros\n");
											}
									break;
								}
						printf("1-Cantidad de Arqueros ->  %d\n", contadorArqueros);
						printf("1-Cantidad de Defensores ->  %d\n", contadorDefensores);
						printf("1-Cantidad de Volantes ->  %d\n", contadorVolantes);
						printf("1-Cantidad de Delanteros ->  %d\n", contadorDelanteros);
						acumuladorJugadores=contadorArqueros+contadorDefensores+contadorVolantes+contadorDelanteros;
						utn_getNumero(&respuestaSeguir,"Quiere seguir ingresando jugadores? 1-SI 2-NO","Error, respuesta invalida\n",1,2,3);
					}while(respuestaSeguir==1);
					break;
			case 3:
					if(acumuladorJugadores>0 && mantenimiento>0)
					{
						if(acumuladorJugadores==22)
						{
							promedioAsia=CalculaPromedioConferencia(&contadorAsia,acumuladorJugadores);
							promedioAfrica = CalculaPromedioConferencia(&contadorAfrica,acumuladorJugadores);
							promedioConcacaf = CalculaPromedioConferencia(&contadorConcacaf,acumuladorJugadores);
							promedioConmebol = CalculaPromedioConferencia(&contadorConmebol,acumuladorJugadores);
							promedioUefa = CalculaPromedioConferencia(&contadorUefa,acumuladorJugadores);
							promedioOceania = CalculaPromedioConferencia(&contadorOceania,acumuladorJugadores);
							banderaTres=1;
						}
						else
						{
							printf("te faltan ingresar jugadores, ingresaste %d \n", acumuladorJugadores);

						}
						if(contadorUefa>contadorConcacaf && contadorUefa>contadorConmebol && contadorUefa>contadorAfrica && contadorUefa>contadorAsia && contadorUefa>contadorOceania)
						{
							mantenimientoConEuropeos=(mantenimiento)*1.35;
							banderaEuropeos=1;
						}
					}
					else
					{
						printf("Te faltan ingresar datos\n");
					}
				break;
			case 4:
				if(banderaTres==1)
				{
					printf("Promedio Asia  \n");
					ImprimePromediosConferencia(promedioAsia);
					printf("Promedio Africa  \n");
					ImprimePromediosConferencia(promedioAfrica);
					printf("Promedio Concacaf \n");
					ImprimePromediosConferencia(promedioConcacaf);
					printf("Promedio Conmebol  \n");
					ImprimePromediosConferencia(promedioConmebol);
					printf("Promedio Uefa  \n");
					ImprimePromediosConferencia(promedioUefa);
					printf("Promedio Oceania  \n");
					ImprimePromediosConferencia(promedioOceania);
					printf("\n\n");
					printf("Costo de mantenimiento es %d \n",mantenimiento);
					if(banderaEuropeos==1)
					{
						printf("Costo de mantenimiento con aumento por mayoria Europeos es %d\n",mantenimientoConEuropeos);
						mantenimientoConEuropeos=mantenimientoConEuropeos-mantenimiento;
						printf("Recibio un aumento de %d \n",mantenimientoConEuropeos);
					}
				}
				else
				{
					printf("Te faltan ingresar calcular los datos\n");
				}
				break;
			case 5:
				utn_getNumero(&respuestaInformes,"Quieres Salir? 1-Si 2-No\n","Opcion Invalida \n",1,2,3);
				break;
		}
	}while(respuestaMenu!=5);

	return EXIT_SUCCESS;
}
