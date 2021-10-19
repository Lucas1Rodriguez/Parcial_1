/*
 * Salon.c
 *
 *  Created on: 17 oct. 2021
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "utn_biblioteca.h"
static int getId(void);

#define NOMBRE_Y_DIRECCION_LEN 128


//Se inicializa la bandera flagEmpty
int initSalones(Salon salonesList[],int len)
{
	int index;
	int retorno = -1;

	if(salonesList != NULL && len > 0)
	{
		for(index=0; index < len; index++)
		{
			salonesList[index].flagEmpty = 1;
		}
		retorno=1;
	}
	return retorno;
}

//cargo los empleados
//llamo a la funcion pedir,numero,texto y float
//devuelvo el resultado por puntero
//cambio el valor de la bandera a 0
int addSalon(Salon* list, int len, int id, char nombreSalon[],char direccion[],int tipo)
{
	int retorno=-1;
	int auxTipo;
	char auxNombre[NOMBRE_Y_DIRECCION_LEN];
	char auxDireccion[NOMBRE_Y_DIRECCION_LEN];

	if(list!=NULL)
	{
		if(utn_getText(auxNombre, NOMBRE_Y_DIRECCION_LEN , "Ingrese el nombre del salon: ", "Error\n",3)==0)
		{
			if(utn_getText(auxDireccion, NOMBRE_Y_DIRECCION_LEN , "\nIngrese la direccion del salon: ", "Error\n",3)==0)
			{
				if(utn_getNumeroInt(&auxTipo, "\nIngrese el tipo de salon \n1)Shopping\n2)Local\n", "Error\n",1, 2, 3)==0)
				{
						list-> tipo= auxTipo;
						list->id = getId();
						strncpy(list->nombreSalon,auxNombre,sizeof(list->nombreSalon));
						strncpy(list->direccion,auxDireccion,sizeof(list->direccion));
						list->flagEmpty = 0;
						retorno=0;

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
//Imprimo las posiciones que tengan la bandera flagEmpty iniciada
int printSalones(Salon* psalon)
{
	int retorno = -1;
	if(psalon != NULL && psalon->flagEmpty ==0)
	{
		if(psalon->flagEmpty ==0){
		printf("id: %d nombre: %s, direccion: %s, tipo: %d\n",psalon -> id, psalon->nombreSalon, psalon->direccion, psalon->tipo);
		retorno = 0;
		}
	}
	return retorno;
}
int printSalonesArray(Salon* psalon, int len)
{
	int retorno = -1;
	int i;
	if(psalon != NULL && len > 0)
	{
		for(i =0;i< len; i++)
		{
			printSalones(&psalon[i]);
			retorno = 0;
		}
	}
	return retorno;
}
//recorro el array
//verifico que exista el id
//retorno la posicion
int findSalonById(Salon* psalon, int len, int idBuscado)
{
	int status=-1;
	int i;

	if(psalon!=NULL && len>0 && idBuscado>=0)
	{
		for(i=0; i<len ; i++)
		{
			if( psalon[i].id==idBuscado && psalon[i].flagEmpty == 0)
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
int findEmptyPosition(Salon* psalon, int len)
{
	int retorno=-1;
	int i;

	if(psalon!=NULL && len>0)
	{
		for(i=0; i<len ;i++)
		{
			if(psalon[i].flagEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//Para eliminar los salones
//Cambio el flagEmpty del id recibido a 1
int removeSalon(Salon salonesList[], int len, int idBuscado)
{
	int status = -1;
	if(salonesList != NULL)
	{
		status = 1;
		salonesList[idBuscado].flagEmpty=1;
	}
	return status;
}
