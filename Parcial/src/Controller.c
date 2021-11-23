#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "Controller.h"
#include "Arcade.h"
#define NOMBRE_LEN 128

int controller_loadFromText(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE* auxA;
	auxA =fopen(path,"r");
	if(auxA!=NULL)
	{
		if(parser_ArcadeFromTextLec(auxA, pArrayListArcade)==0)
		{
			retorno=0;
		}
	}
	fclose(auxA);
    return retorno;
}

int controller_addArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int auxFichasMax;
	int auxCantJug;
	int auxTipoSonido;
	char auxNacionalidad[63];
	char auxSalon[63];
	char auxJuego[63];
	int id;
	char tipo1[63] = "MONO";
	char tipo2[63] = "ESTEREO";
	char tipoFinal[63];
	Arcade* NewArcade;
	Arcade* auxId;

	if(utn_getText(auxNacionalidad, 63 , "Ingrese nacionalidad del arcade:\n", "Error\n",3)==0 &&
	utn_getNumeroInt(&auxTipoSonido, "Ingrese el tipo de sonido del arcade: \n1) MONO \n2) ESTEREO\n  ", "Error\n",1, 2, 3)==0 &&
	utn_getNumeroInt(&auxCantJug, "Ingrese la cantidad de jugadores:\n", "Error\n",1, 1000, 3)==0 &&
	utn_getNumeroInt(&auxFichasMax, "Ingrese el num de fichas max:\n  ", "Error\n",1, 100000, 3)==0 &&
	utn_getText(auxSalon, 63 , "Ingrese el nombre del salon:\n", "Error\n",3)==0 &&
	utn_getText(auxJuego, 63 , "Ingrese el nombre del juego:\n", "Error\n",3)==0)
	{
		auxId= ll_get(pArrayListArcade, ll_len(pArrayListArcade)-1);

		arcade_getId(auxId, &id);

		id++;
		switch(auxTipoSonido)
		{
			case 1:
				strncpy(tipoFinal,tipo1,63);
				break;
			case 2:
				strncpy(tipoFinal,tipo2,63);
				break;
		}
		NewArcade = arcade_newParametrosAdd(id,auxNacionalidad,tipoFinal,auxCantJug,auxFichasMax,auxSalon,auxJuego);
		retorno=0;
	}

	if(NewArcade!=NULL)
	{
		ll_add(pArrayListArcade, NewArcade);
		retorno=0;
	}

	return retorno;
}

int controller_editArcade(LinkedList* pArrayListArcade)
{
	Arcade* aux;
	int retorno=-1;
	int len;
	int idBuscado;
	int id;
	int auxCantJug;
	char auxJuego[63];
	int opcion;

	if(pArrayListArcade!=NULL)
	{
		len = ll_len(pArrayListArcade);
		if(len>=0)
		{
			controller_ListArcade(pArrayListArcade);

			utn_getNumeroInt(&id,"Ingrese id del arcade a modificar\n" , "Error\n", 1, 2000, 3);

			idBuscado = Controller_buscarPorId(pArrayListArcade, len, id);

			if(idBuscado!=-1)
			{
				aux = (Arcade*)ll_get(pArrayListArcade, idBuscado);

				arcade_imprimir(aux, idBuscado);

				utn_getNumeroInt(&opcion, "Ingrese opcion a modificar\n 1)Modificar nombre del juego\n 2)Modificar cantidad de jugadores\n", "Error, ingrese opcion a modificar", 1, 2, 3);
				retorno = 0;
				switch(opcion)
				{
					case 1:
						utn_getText(auxJuego, 128, "Ingrese nuevo nombre:\n", "Error, Ingrese nuevo nombre\n", 3);

						arcade_setJuego(aux,auxJuego);

						break;
					case 2:
						utn_getNumeroInt(&auxCantJug, "Ingrese cantidad de jugadores \n", "Error, ingrese cantidad de jugadores", 1, 1000, 3);

						arcade_setCantJug(aux, auxCantJug);

						break;
				}
			}
			else
			{
				printf("No se encontro el id.");
			}
		}
		else
		{
			printf("No hay nada cargado.");
		}
	}

    return retorno;
}

int controller_removeArcade(LinkedList* pArrayListArcade)
{
	int auxId;
	int idBuscado;
	int retorno = -1;
	int opcion;
	for(int i = 0; i<ll_len(pArrayListArcade);i++)
	{
		controller_ListArcade(pArrayListArcade);

		if(utn_getNumeroInt(&idBuscado,"Ingrese un id a eliminar","Error. No se encontro el id",1,ll_len(pArrayListArcade),3) == 0)
		{
			auxId = Controller_buscarPorId(pArrayListArcade, ll_len(pArrayListArcade), idBuscado);
			if(utn_getNumeroInt(&opcion,"Seguro quiere eliminar? \n1)Si \n2)No\n","Error.",1,2,3) == 0)
			{
				switch(opcion)
				{
					case 1:
						ll_remove(pArrayListArcade,auxId);
						retorno = 0;
						break;
					case 2:
						printf("No se elimino el arcade");
						break;
				}

			}
			break;
		}
	}
    return retorno;
}

int controller_ListArcade(LinkedList* pArrayListArcade)
{
	int retorno = -1;
	int i;
	Arcade* aux;
	if(pArrayListArcade != NULL && ll_len(pArrayListArcade) > 0)
	{
		for(i =0;i< ll_len(pArrayListArcade); i++)
		{
			aux = (Arcade*)ll_get(pArrayListArcade,i);
			arcade_imprimir(aux,i);
			retorno = 0;
		}
	}
    return retorno;
}

int controller_sortArcade(LinkedList* pArrayListArcade)
{
	int retorno=-1;
	if(pArrayListArcade!=NULL)
	{
		if(ll_len(pArrayListArcade)>=0)
		{
			if(ll_sort(pArrayListArcade, OrdenamientoPorNombre, 1)==0)
			{
				controller_ListArcade(pArrayListArcade);
				retorno=0;
			}
		}
	}
    return retorno;
}

int OrdenamientoPorNombre(void* juegoZ, void* juegoX)
{
	int retorno=0;
	Arcade* auxZ=juegoZ;
	Arcade* auxX=juegoX;
	char aux1[63];
	char aux2[63];

	arcade_getJuego(auxZ, aux1);
	arcade_getJuego(auxX, aux2);

	retorno = stricmp(aux1,aux2);

	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListArcade)
{
	int retorno=-1;
	FILE* aux;
	if(pArrayListArcade!=NULL)
	{
		aux = fopen(path,"w");

		if(aux!=NULL)
		{
			parser_ArcadeFromTextEsc(aux, pArrayListArcade);
			retorno=0;
		}
	}
	fclose(aux);
    return retorno;
}

int Controller_buscarPorId(LinkedList* pArrayListArcade,int len, int IdBuscado)
{
	int status=-1;
	int index;
	int idAux;
	Arcade* aux;

	if(pArrayListArcade!=NULL && len>0 && IdBuscado>=0 && IdBuscado<=len)
	{

		for(index=0; index<len ; index++)
		{
			aux = (Arcade*)ll_get(pArrayListArcade, index);

			arcade_getId(aux, &idAux);

			if(idAux==IdBuscado)
			{
				status = index;
				break;
			}
		}
	}
	return status;
}

int controller_ArchivoJuegos(char* path, LinkedList* pArrayListArcade)
{
	int retorno=-1;
	int flagArcade;
	int i;
	int j;
	Arcade* arcadeI;
	Arcade* arcadeJ;
	char auxjuego1[63];
	char auxjuego2[63];

	FILE *auxP;
	auxP = fopen(path,"w"); //abro y leo el archivo

	if(auxP!=NULL)
	{
		if(pArrayListArcade != NULL)
		{
			retorno=0;
			for(i= 0; i < ll_len(pArrayListArcade); i++)
			{
				arcadeI = ll_get(pArrayListArcade, i);
				arcade_getJuego(arcadeI, auxjuego1);
				flagArcade=0;
				for(j = i+1; j < ll_len(pArrayListArcade); j++)
				{
					arcadeJ = ll_get(pArrayListArcade, j);
					arcade_getJuego(arcadeJ, auxjuego2);

					if(strcmp(auxjuego1,auxjuego2)== 0)
					{
						flagArcade = 1;
					}
				}
				if(flagArcade == 0)
				{
					fprintf(auxP,"%s\n", auxjuego1);
				}
			}
		}
	}
	fclose(auxP);
	return retorno;

}
int controller_FilterMulti(LinkedList* pArrayalistArcade)
{
	int retorno=-1;
	LinkedList* aux;

	if(pArrayalistArcade!=NULL)
	{
		aux = ll_filter(pArrayalistArcade, archivoMultijugador);

		if(aux!=NULL)
		{
			if(controller_saveAsText("multijugador.csv",aux)==0)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

int archivoMultijugador(void* pArrayalistArcade)
{
	int retorno=1;
	Arcade* aux;
	int  cantidad;

	aux = (Arcade*)pArrayalistArcade;
	if(aux!=NULL)
	{
		arcade_getCantJug(aux, &cantidad);
		if(cantidad>1)
		{
			retorno=0;
		}
	}
	return retorno;
}

int actualizarCantFichas(LinkedList* pArraylistaArcade)
{
	int retorno=1;
	if(pArraylistaArcade!=NULL)
	{
		ll_map(pArraylistaArcade, DuplicarFichas);
		retorno=0;
	}
	return retorno;
}

void DuplicarFichas(void* pArrayalistArcade)
{
	Arcade* aux;
	int auxFichas;
	int auxFinal;
	aux = (Arcade*)pArrayalistArcade;
	if(pArrayalistArcade!=NULL && aux!=NULL)
	{
		arcade_getFichasMax(aux, &auxFichas);

		auxFinal = auxFichas*2;

		arcade_setFichasMax(aux, auxFinal);
	}
}

