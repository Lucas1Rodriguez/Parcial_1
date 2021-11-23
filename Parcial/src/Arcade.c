#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "Arcade.h"
#include "Validacion.h"
#define NOMBRE_LEN 63

static int getFieldToModify(int* selectedField);


Arcade* arcade_new()
{
	Arcade* pArcadeAux = NULL;

	pArcadeAux = (Arcade*) malloc(sizeof(Arcade));

	return pArcadeAux;
}

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* tipoSonidoStr, char* cantJugStr, char* fichasMaxStr, char* salonStr, char* juegoStr)
{
	Arcade* pArcadeAux = NULL;

	pArcadeAux = arcade_new();
	if(pArcadeAux != NULL && idStr != NULL && nacionalidadStr != NULL && tipoSonidoStr != NULL && cantJugStr != NULL && fichasMaxStr != NULL && salonStr != NULL && juegoStr != NULL)
	{
		if(arcade_setNacionalidad(pArcadeAux,nacionalidadStr) == -1 ||
		arcade_setId(pArcadeAux,atoi(idStr)) == -1 ||
		arcade_setTipoSonido(pArcadeAux,tipoSonidoStr) == -1 ||
		arcade_setCantJug(pArcadeAux,atoi(cantJugStr)) == -1 ||
		arcade_setFichasMax(pArcadeAux,atoi(fichasMaxStr)) == -1 ||
		arcade_setSalon(pArcadeAux,salonStr) == -1 ||
		arcade_setJuego(pArcadeAux,juegoStr) == -1)
		{
			printf("Algo salio mal \n");
			free(pArcadeAux);
		}
	}
	return pArcadeAux;
}

int arcade_setId(Arcade* this, int id)
{
    int retorno=1;
    if(this!=NULL && id>=0 )
    {

        this->id=id;
        retorno=0;
    }

    return retorno;
}

int arcade_getId(Arcade* this, int* id)
{
    int retorno=1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }

    return retorno;
}

int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
    int retorno=1;
    if(this!=NULL &&  nacionalidad!=NULL)
    {
        strncpy(this->nacionalidad,nacionalidad,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
    int retorno=1;
    if(this!=NULL)
    {
        strncpy(nacionalidad,this->nacionalidad,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}

int arcade_setTipoSonido(Arcade* this,char* tipo)
{
	 int retorno=1;
	if(this!=NULL && tipo!=NULL)
	{
		strncpy(this->tipoSonido,tipo,NOMBRE_LEN);

		retorno=0;
	}
	return retorno;

}

int arcade_getTipoSonido(Arcade* this,char* tipo)
{
	int retorno=1;
	if(this!=NULL && tipo!=NULL)
	{
		strncpy(tipo,this->tipoSonido,NOMBRE_LEN);
		retorno=0;
	}
	return retorno;
}

int arcade_setFichasMax(Arcade* this,int fichas)
{
    int retorno=1;
    if(this!=NULL && fichas>=0)
    {
        this->fichasMax=fichas;
        retorno=0;
    }
    return retorno;
}

int arcade_getFichasMax(Arcade* this,int* fichas)
{
    int retorno=1;
    if(this!=NULL && fichas>=0)
    {
        *fichas=this->fichasMax;
        retorno=0;
    }
    return retorno;
}

int arcade_setCantJug(Arcade* this,int jugadores)
{
	int retorno=1;
	if(this!=NULL && jugadores >=0)
	{
		this->cantJug=jugadores;
		retorno=0;
	}
    return retorno;
}

int arcade_getCantJug(Arcade* this,int* jugadores)
{
	int retorno=1;
	if(this!=NULL && jugadores >=0)
	{
		*jugadores=this->cantJug;
		retorno=0;
	}
	return retorno;
}

int arcade_setSalon(Arcade* this,char* salon)
{
    int retorno=1;
    if(this!=NULL && salon!=NULL)
    {
        strncpy(this->salon,salon,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getSalon(Arcade* this,char* salon)
{
    int retorno=1;
    if(this!=NULL && salon!=NULL)
    {
        strncpy(salon,this->salon,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}


int arcade_setJuego(Arcade* this,char* juego)
{
    int retorno=1;
    if(this!=NULL && juego!=NULL)
    {
    	strMinuscula(juego);
        strncpy(this->juego,juego,NOMBRE_LEN);

        retorno=0;
    }
    return retorno;
}

int arcade_getJuego(Arcade* this,char* juego)
{
    int retorno=1;
    if(this!=NULL && juego!=NULL)
    {
        strncpy(juego,this->juego,NOMBRE_LEN);
        retorno=0;
    }
    return retorno;
}


int arcade_funcionSort(void* pJuego1, void* pJuego2)
{
	Arcade* juego1 = (Arcade*) pJuego1;
	Arcade* juego2 = (Arcade*) pJuego2;
	char auxJuego1[128];
	char auxJuego2[128];
	int aux;
	int retorno;
		arcade_getJuego(juego1,auxJuego1);
		arcade_getJuego(juego2,auxJuego2);
		aux = strcmp(auxJuego1,auxJuego2);
		if(aux>0)
		{
			retorno = 1;
		}
		else if(aux==0)
		{
			retorno = 0;
		}
		else
		{
			retorno = -1;
		}
	return retorno;
}

int arcade_modificar(Arcade* this, int indice)
{
	int retorno=-1;
	int auxCantJug;
	int auxFichasMax;
	char auxTipoSonido[NOMBRE_LEN];
	char auxNacionalidad[NOMBRE_LEN];
	char auxSalon[NOMBRE_LEN];
	char auxJuego[NOMBRE_LEN];
	int opcion;
	if(this !=NULL)
	{
		if(getFieldToModify(&opcion)==1)
		{
			retorno=1;
			switch (opcion)
			{
			case 1:
				if(arcade_getNacionalidad(this,auxNacionalidad)==1)
				{
					arcade_setNacionalidad(this,auxNacionalidad);
				}
				break;
			case 2:
				if(arcade_getCantJug(this,&auxCantJug)==1)
				{
					arcade_setCantJug(this,auxCantJug);
				}
				break;
			case 3:
				if(arcade_getFichasMax(this,&auxFichasMax)== 1)
				{
					arcade_setFichasMax(this,auxFichasMax);
				}
				break;
			case 4:
				if(arcade_getTipoSonido(this,auxTipoSonido)== 1)
				{
					arcade_setTipoSonido(this,auxTipoSonido);
				}
				break;
			case 5:
				if(arcade_getSalon(this,auxSalon)== 1)
				{
					arcade_setSalon(this,auxSalon);
				}
				break;
			case 6:
				if(arcade_getJuego(this,auxJuego)== 1)
				{
					arcade_setJuego(this,auxJuego);
				}
				break;
			}
		}
	}
	return retorno;
}

static int getFieldToModify(int* selectedField)
{
	int retorno=-1;
	int auxSelectItem;

	if(utn_getNumeroInt(&auxSelectItem, "\nElegi la opcion:\n 1-Nacionalidad del arcade\n 2-Cantidad de jugadores del arcade\n 3- Cantidad de fichas maximas\n 4-Tipo de sonido\n 5-Salon\n 6-Juego\n", "Error",1 , 6, 3)==0)
	{
		retorno = 1;
		*selectedField= auxSelectItem;
	}
	return retorno;
}

int arcade_List(Arcade* this)
{
	int retorno = -1;
	int auxCantJug;
	int auxFichasMax;
	char auxTipoSonido[NOMBRE_LEN];
	char auxNacionalidad[NOMBRE_LEN];
	char auxSalon[NOMBRE_LEN];
	char auxJuego[NOMBRE_LEN];
	int auxid;
		if(arcade_getNacionalidad(this,auxNacionalidad)!=-1)
		{

			if(arcade_getCantJug(this,&auxCantJug)!=-1)
			{

				if(arcade_getFichasMax(this,&auxFichasMax)!=-1)
				{

					if(arcade_getTipoSonido(this,auxTipoSonido)!=-1)
					{

						if(arcade_getSalon(this,auxSalon)!=-1)
						{

							if(arcade_getJuego(this,auxJuego)!=-1)
							{

								if(arcade_getId(this,&auxid)!=-1)
								{
									retorno = 1;
									printf("Id: %d Nacionalidad: %s Tipo de sonido: %s Cantidad de jugadores : %d Fichas maximas: %d Salon: %s Juego: %s",auxid,auxNacionalidad,auxTipoSonido,auxCantJug,auxFichasMax,auxSalon,auxJuego);
								}
							}
						}
					}

				}
			}
		}
	return retorno;
}
int arcade_imprimir(Arcade* auxArcade, int indice)
{
	int retorno=-1;
	int auxId;
	int auxCantJug;
	int auxFichasMax;
	char auxTipoSonido[NOMBRE_LEN];
	char auxNacionalidad[NOMBRE_LEN];
	char auxSalon[NOMBRE_LEN];
	char auxJuego[NOMBRE_LEN];

	arcade_getId(auxArcade,&auxId);
	arcade_getNacionalidad(auxArcade,auxNacionalidad);
	arcade_getCantJug(auxArcade,&auxCantJug);
	arcade_getFichasMax(auxArcade,&auxFichasMax);
	arcade_getTipoSonido(auxArcade,auxTipoSonido);
	arcade_getSalon(auxArcade,auxSalon);
	arcade_getJuego(auxArcade,auxJuego);

	if(auxArcade!=NULL && indice>=0)
	{
		printf("Id: %d Nacionalidad: %s Tipo de sonido: %s Cantidad de jugadores : %d Fichas maximas: %d Salon: %s Juego: %s \n",auxId,auxNacionalidad,auxTipoSonido,auxCantJug,auxFichasMax,auxSalon,auxJuego);
		retorno=0;
	}
	return retorno;
}
Arcade* arcade_newParametrosAdd(int idStr,char* nacionalidadStr,char* tipoSonidoStr, int cantJugStr, int fichasMaxStr, char* salonStr, char* juegoStr)
{
	Arcade* aux = arcade_new();
	if(idStr>=0 && nacionalidadStr != NULL && tipoSonidoStr!=NULL && cantJugStr >=0 && fichasMaxStr>=0 && salonStr != NULL && juegoStr != NULL)
	{
		if(aux != NULL)
		{
			if(arcade_setId(aux, idStr)==1 ||
			arcade_setNacionalidad(aux, nacionalidadStr)==1 ||
			arcade_setTipoSonido(aux, tipoSonidoStr)==1 ||
			arcade_setCantJug(aux, cantJugStr)==1 ||
			arcade_setFichasMax(aux, fichasMaxStr)==1 ||
			arcade_setSalon(aux, salonStr)==1 ||
			arcade_setJuego(aux, juegoStr)==1)
			{
				printf("Algo salio mal\n");
			}
		}
    }
    return aux;
}
