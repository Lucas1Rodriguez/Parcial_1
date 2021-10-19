/*
 * menu.c
 *
 *  Created on: 18 oct. 2021
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "Salon.h"
#include "utn_biblioteca.h"

void menu (Salon salonList[], int lenSalon, Arcade arcadeList[], int lenArcade)
	{
		int opcion;
		int lugarLibre;
		int flag;
		int lugarLibreArcade;
		int flagArcade;
		int respuesta;
		int idIngresado;
		int indexAModif;
		int auxid;
		int auxValor;
		do{
			if (utn_getNumeroInt(&opcion, "\nBienvenido \n1)Altas salones:\n2)Bajas salones:\n3)Imprimir salones:\n4)Altas arcades:\n5)Modificar arcades:\n6)Bajas arcades:\n7)Imprimir arcades:\n8)Imprimir juegos:\n9)Informes: \n", "\nError opcion Invalida",  1, 9, 5)==0)
				{
				switch (opcion)
					{
						case 1:
							//Busco lugar libre
							lugarLibre = findEmptyPosition(salonList, lenSalon);
							//Pido y cargo los datos ingresados
							addSalon(&salonList[lugarLibre], lenSalon, salonList[lugarLibre].id, salonList[lugarLibre].nombreSalon, salonList[lugarLibre].direccion, salonList[lugarLibre].tipo);
							flag=1;
							if(flag ==1)
							{
								for(int i = 0; i< lenSalon; i++)
								{
										printSalones(&salonList[i]);
								}
							}
							else
							{
								printf("Error, no hay salones cargados\n");
							}
							break;
						case 2:
							//Verifico que la opcion 1 se haya ingresado
							if(flag ==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenSalon ;i++)
								{
									printSalones(&salonList[i]);
								}
									int idingresado;
									int idDarBaja;
									//Pido que ingrese un numero a buscar
									//Verifico que exista
									//Llamo a la funcion eliminar y imprimo
									if (utn_getNumeroInt(&idingresado, "\nIngrese ID a eliminar\n", "Error, el id no es valido", 0, 9999, 5) ==0)
									{
										idDarBaja = findSalonById(salonList,lenSalon,idingresado);
										if(idDarBaja>=0)
										{
											removeSalon(salonList,lenSalon,idDarBaja);
											printf("Salon eliminado\n");
										}
									}
							}
							else
							{
								printf("Error, no hay salones cargados\n");
							}
							break;
						case 3:
							if(flag ==1)
							{
								printSalonesArray(salonList, lenSalon);
							}
							else
							{
								printf("Error, no hay salones cargados\n");
							}
							break;
						case 4:
							//Busco lugar libre
							lugarLibreArcade = findEmptyPositionArcade(arcadeList, lenArcade);
							//Pido y cargo los datos ingresados
							addArcade(&arcadeList[lugarLibreArcade], lenArcade, arcadeList[lugarLibreArcade].idArcade, arcadeList[lugarLibreArcade].nombreJuego, arcadeList[lugarLibreArcade].nacionalidad, arcadeList[lugarLibreArcade].tipoDeSonido, arcadeList[lugarLibreArcade].cantidadJugadores, arcadeList[lugarLibreArcade].capacidadMaxFichas, arcadeList[lugarLibreArcade].idSalon);
							flagArcade=1;
							break;
						case 5:
							//verifico que se haya cumplido la opcion 1
							if(flagArcade==1)
							{
								//recorro el array para imprimir los datos cargados
								printArcadesArray(arcadeList,lenArcade);

								//pido que ingrese un numero a buscar
								//verifico que exista
								//llamo a la funcion modificar y imprimo
								if (utn_getNumeroInt(&idIngresado, "\nIngrese ID\n", "Error", 0, 9999, 5) ==0)
								{
									indexAModif = findArcadeById(arcadeList,lenArcade,idIngresado);
									if(indexAModif >=0)
									{
										modifyArcade(arcadeList,lenArcade,indexAModif);
									}
								}
							}
							else{
								printf("Error, no hay arcades cargados\n");
							}
							break;
						case 6:
							if(flagArcade ==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenArcade ;i++)
								{
									printArcades(&arcadeList[i]);
								}
								int idingresado;
								int idDarBaja;
								//Pido que ingrese un numero a buscar
								//Verifico que exista
								//Llamo a la funcion eliminar y imprimo
								if (utn_getNumeroInt(&idingresado, "\nIngrese ID a eliminar\n", "Error", 0, 9999, 5) ==0)
								{
									idDarBaja = findArcadeById(arcadeList,lenArcade,idingresado);
									if(idDarBaja>=0)
									{
										printArcades(&arcadeList[idDarBaja]);
										if(utn_getNumeroInt(&respuesta, "Seguro quiere dar de baja el arcade \n1)Si\n2)No","Error", 1, 2, 5) ==0)
										{
											if(respuesta == 1){
												removeArcade(arcadeList,lenArcade,idDarBaja);
												printf("Arcade eliminado\n");
											}
											else
											{
												printf("No se elimino el arcade\n");
											}
										}
									}
								}
							}
							break;
						case 7:
							if(flagArcade ==1)
							{
								//Recorro el array para imprimir los datos cargados
								for(int i=0;i< lenArcade ;i++)
								{
									printArcades(&arcadeList[i]);
								}
							}
							else
							{
								printf("\nError, No hay arcades cargados\n");
							}

							break;
						case 8:
							if(flagArcade==1)
							{
							 printf("Los juegos son: \n");
							 printJuegos(arcadeList,lenArcade);
							}
							else
							{
								printf("No hay juegos cargados");
							}
							break;
						case 9:
							if(flag == 1 && flagArcade == 1)
							{
								do{
								int opcion;
								int auxPrecioFichas;
								if (utn_getNumeroInt(&opcion, "\n1)Imprimir salones con mas de 4 arcades:\n2)Imprimir arcades con mas de 2 jugadores:\n3)Imprimir salon en especifico:\n4)Imprimir arcades de un salon especifico:\n5)Imprimir salón con más cantidad de arcades:\n6)Imprimir monto max:\n7)Imprimir juego en mas de un arcade:\n", "\nError opcion Invalida",  1, 7, 5)==0)
									switch(opcion){
									case 1:
										inf_CuatroArcades(salonList,lenSalon,arcadeList,lenArcade);
										break;
									case 2:
										inf_ArcadeDosJugadores(arcadeList,lenArcade,salonList,lenSalon);
										break;
									case 3:
										inf_SalonDetallado(salonList,lenSalon,arcadeList,lenArcade,&salonList[auxid].id);
										break;
									case 4:
										inf_ListarArcades(arcadeList,lenArcade,salonList,lenSalon,&salonList[auxid].id);
										break;
									case 5:
										inf_ListarMayorCantidad(arcadeList,lenArcade,salonList,lenSalon);
										break;
									case 6:
										inf_CalcularValorMax(arcadeList,lenArcade,&salonList[auxid].id,&auxValor);
										break;
									case 7:
										inf_ContJuegos(arcadeList,lenArcade,utn_getNumeroInt(&auxPrecioFichas, "Elija la cantidad que desea que valgan las fichas\n", "\nError cantidad Invalida",  1, 10000, 5)==0);
										break;
									}
								}while(opcion <=7);
								break;
							}
							else
							{
								printf("No se pueden crear los informes ya que no hay salones o arcades creados");
							}
					}
				}
			}while (opcion <=9);
	}
