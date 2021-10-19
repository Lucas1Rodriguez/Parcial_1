/*
 * Juegos.h
 *
 *  Created on: 17 oct. 2021
 *      Author: USURIO
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nacionalidad[63];
	char nombreJuego [63];
	int tipoDeSonido;
	int cantidadJugadores;
	int capacidadMaxFichas;
	int idSalon;
	int idArcade;
	int flagEmpty;
}Arcade;

int initArcades(Arcade arcadeList[],int len);
int addArcade(Arcade* list, int len, int id, char nombreJuego[],char nacionalidad[],int tipoDeSonido,int cantidadJugadores,int cantidadFichas, int idSalon);
int printArcades(Arcade* pArcade);
int printArcadesArray(Arcade* pArcade, int len);
int findArcadeById(Arcade* pArcade, int len, int idBuscado);
int findEmptyPositionArcade(Arcade* pArcade, int len);
int removeArcade(Arcade arcadeList[], int len, int idBuscado);
int modifyArcade(Arcade* pArcade, int len, int idAModificar);
int printJuegos(Arcade* arcadesList, int len);

#endif /* ARCADE_H_ */
