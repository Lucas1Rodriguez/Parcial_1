/*
 * Arcade.c
 *
 *  Created on: 17 oct. 2021
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "Salon.h"
#include "utn_biblioteca.h"

//prototipos globales
static int getId(void);
static int getFieldToModify(int*selectedField);
static int getNombreJuego (char arcadeNombreJuego[]);
static int getCantidadJugadores(int *arcadeCantidadJugadores);

#define NOMBRE_JUEGO_Y_NACIONALIDAD_LEN 63


//Se inicializa la bandera isEmpty
int initArcades(Arcade arcadeList[],int len)
{
	int index;
	int retorno = -1;

	if(arcadeList != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			arcadeList[index].flagEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//cargo los empleados
//llamo a la funcion pedir,numero,texto y float
//devuelvo el resultado por puntero
//cambio el valor de la bandera a 0
int addArcade(Arcade* list, int len, int id, char nombreJuego[],char nacionalidad[],int tipoDeSonido,int cantidadJugadores,int cantidadFichas, int idSalon)
{
	int retorno=-1;
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCapacidadfichas;
	int auxIdSalon;
	char auxNombreJuego[NOMBRE_JUEGO_Y_NACIONALIDAD_LEN];
	char auxNacionalidad[NOMBRE_JUEGO_Y_NACIONALIDAD_LEN];

	if(list!=NULL)
	{
		if(utn_getText(auxNombreJuego, NOMBRE_JUEGO_Y_NACIONALIDAD_LEN , "Ingrese el nombre del juego que contiene el arcade: ", "Error\n",3)==0)
		{
			if(utn_getText(auxNacionalidad, NOMBRE_JUEGO_Y_NACIONALIDAD_LEN, "\nIngrese la nacionalidad del arcade: ", "Error\n",3)==0)
			{
				if(utn_getNumeroInt(&auxTipoSonido, "\nIngrese el tipo de sonido del arcade \n1)Mono\n2)Estereo ", "Error\n",1, 2, 3)==0)
				{
					if(utn_getNumeroInt(&auxCantidadJugadores, "\nIngrese la cantidad de jugadores del arcade: ", "Error\n",1, 1000, 3)==0)
					{
						if(utn_getNumeroInt(&auxCapacidadfichas, "\nIngrese la capacidad de fichas maxima del arcade: ", "Error\n",1, 10000, 3)==0)
						{
							if(utn_getNumeroInt(&auxIdSalon, "\nIngrese el ID del salon al que pertenece el arcade: ", "Error, ingrese un id valido\n",1, 10000, 3)==0)
							{
								list->tipoDeSonido= auxTipoSonido;
								list->cantidadJugadores= auxCantidadJugadores;
								list->capacidadMaxFichas = auxCapacidadfichas;
								list->idSalon = auxIdSalon;
								list->idArcade = getId();
								strncpy(list->nombreJuego,auxNombreJuego,sizeof(list->nombreJuego));
								strncpy(list->nacionalidad,auxNacionalidad,sizeof(list->nacionalidad));
								list->flagEmpty = 0;
								retorno=0;
							}


						}
					}
				}
			}
		}
	}
	return retorno;
}

//Funcion privada del archivo
//Genero un id y lo retorno
static int getId(void)
{
	static int contador=0;
	contador++;//es global : mantiene su valor
	return contador;
}
//Imprimo las posiciones que tengan la bandera isEmpty iniciada
int printArcades(Arcade* pArcade)
{
	if(pArcade->flagEmpty ==0)
	{
		printf("id: %d, Nombre del juego: %s, Nacionalidad: %s, Tipo de sonido: %d, Cantidad de jugadores: %d, Capacidad maxima de fichas: %d, ID salon: %d\n",pArcade->idArcade, pArcade->nombreJuego, pArcade->nacionalidad, pArcade->tipoDeSonido, pArcade->cantidadJugadores, pArcade->capacidadMaxFichas, pArcade->idSalon);
	}
	return 1;
}
int printArcadesArray(Arcade* pArcade, int len)
{
	int retorno = -1;
	int i;
	if(pArcade != NULL && len > 0)
	{
		for(i =0;i< len; i++)
		{
			printArcades(&pArcade[i]);
			retorno = 0;
		}
	}
	return retorno;
}
//recorro el array
//verifico que exista el id
//retorno la posicion
int findArcadeById(Arcade* pArcade, int len, int idBuscado)
{
	int status=-1;
	int i;

	if(pArcade!=NULL && len>0 && idBuscado>=0)
	{
		for(i=0; i<len ; i++)
		{
			if( pArcade[i].idArcade==idBuscado && pArcade[i].flagEmpty == 0)
			{
				status = i;
				break;
			}
		}
	}
	return status;
}
//recorro el array
//verifico que haya espacio
//retorno la posicion
int findEmptyPositionArcade(Arcade* pArcade, int len)
{
	int retorno=-1;
	int i;

	if(pArcade!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(pArcade[i].flagEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//Para eliminar los empleados
//Cambio el isEmpty del id recibido a 1
int removeArcade(Arcade arcadeList[], int len, int idBuscado)
{
	int status = -1;
	if(arcadeList != NULL)
	{
		status = 1;
		arcadeList[idBuscado].flagEmpty=1;
	}
	return status;
}
//Modifico posicion
//Llamo a funcion para seleccionar opcion
//Modifico la opcion elegida
int modifyArcade(Arcade* pArcade, int len, int idAModificar)
{
	int status=-1;
	int auxCantidadJugadores;
	char auxNombreJuego[NOMBRE_JUEGO_Y_NACIONALIDAD_LEN];
	int opcion;
	if(pArcade !=NULL)
	{
		if(getFieldToModify(&opcion)==1)
		{
			status=1;
			switch (opcion)
			{
			case 1:
				if(getCantidadJugadores(&auxCantidadJugadores)==1)
				{
					pArcade->cantidadJugadores = auxCantidadJugadores;
				}
				break;
			case 2:
				if(getNombreJuego(auxNombreJuego)==1)
				{
					strncpy(pArcade[idAModificar].nombreJuego, auxNombreJuego, NOMBRE_JUEGO_Y_NACIONALIDAD_LEN);
				}
				break;
			}
		}
	}
	return status;
}
//Funcion privada del archivo
//Llamo a la funcion pedir int
//Retorno por puntero el valor ingresado para la funcion modificar
static int getFieldToModify(int*selectedField)
{
	int status=-1;
	int auxSelectItem;

	if(utn_getNumeroInt(&auxSelectItem, "\nElegi la opcion:\n 1-Cantidad de jugadores\n 2-Nombre del juego", "Error",1 , 2, 2)==0)
	{
		status =1;
		*selectedField= auxSelectItem;
	}
	return status;
}

//Funcion privada del archivo
//Llamo a funcion pedir char
//Retorno por puntero el valor ingresado para la funcion modificar
static int getNombreJuego (char arcadeNombreJuego[])
{
	int status =-1;
	char mensaje[180];
	char auxNombreJuego[NOMBRE_JUEGO_Y_NACIONALIDAD_LEN];
	strncpy(mensaje, "\nIngrese el nombre del juego: ",sizeof(mensaje));
	if(utn_getText(auxNombreJuego, NOMBRE_JUEGO_Y_NACIONALIDAD_LEN , mensaje, "Error",1)==0)
	{
		status =1;
		strncpy(arcadeNombreJuego, auxNombreJuego, NOMBRE_JUEGO_Y_NACIONALIDAD_LEN);
	}
	return status;
}

//Funcion privada del archivo
//Llamo a funcion pedir float
//Retorno por puntero el valor ingresado para la funcion modificar
static int getCantidadJugadores(int *arcadeCantidadJugadores)
{
	int status =-1;
	char mensaje[180];
	int auxCantidadJugadores;

	strncpy(mensaje,"\nIngrese cantidad de jugadores: ", sizeof(mensaje));
	if(utn_getNumeroInt(&auxCantidadJugadores, mensaje, "Error",1, 1000, 3)==0)
	{
		status=1;
		*arcadeCantidadJugadores=auxCantidadJugadores;
	}
	return status;
}

int printJuegos(Arcade* arcadesList, int len)
{
    int status = 0;
    int i;
    int j;
    int flag;

    if(arcadesList != NULL && len > 0)
    {
    	status = 1;
        for(i = 0; i < len; i++)
        {
            if(arcadesList[i].flagEmpty == 0)
            {
                flag = 0;
                for(j = i+1; j < len; j++)
                {
                    if(strcmp(arcadesList[i].nombreJuego, arcadesList[j].nombreJuego) == 0)
                    {
                        flag = 1;
                    }
                }
                if(flag == 0)
                {
                    printf("%s\n", arcadesList[i].nombreJuego);
                }
            }
        }
    }
    return status;
}
