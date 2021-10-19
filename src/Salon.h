/*
 * Salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: USURIO
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char nombreSalon[128];
	char direccion[128];
	int tipo;
	int id;
	int flagEmpty;
}Salon;
int initSalones(Salon salonesList[],int len);
int addSalon(Salon* list, int len, int id, char name[],char direccion[],int tipo);
int printSalones(Salon* psalon);
int printSalonesArray(Salon* psalon, int len);
int findSalonById(Salon* psalon, int len, int idBuscado);
int findEmptyPosition(Salon* psalon, int len);
int removeSalon(Salon salonesList[], int len, int idBuscado);

#endif /* SALON_H_ */
