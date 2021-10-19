/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Arcade.h"
#define SALONES_LEN 100
#define ARCADES_LEN 1000
int main(void) {
	setbuf(stdout,NULL);

	Salon salonesList[SALONES_LEN];
	Arcade arcadeList[ARCADES_LEN];


	if(initSalones(salonesList,SALONES_LEN)!=NULL && initArcades(arcadeList,ARCADES_LEN)!=NULL)
	{
		menu(salonesList,SALONES_LEN,arcadeList,ARCADES_LEN);
	}


	return EXIT_SUCCESS;
}
