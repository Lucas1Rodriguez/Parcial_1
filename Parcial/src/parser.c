#include <stdio.h>
#include <stdlib.h>

#include "Arcade.h"
#include "LinkedList.h"

int parser_ArcadeFromTextLec(FILE* pFile , LinkedList* pArraylistArcades)
{
	int retorno=-1;
	int cantidad;
	char bufferId[1024];
	char bufferNacionalidad[1024];
	char bufferTipoSonido[1024];
	char bufferCantJug[1024];
	char bufferFichasMax[1024];
	char bufferSalon[1024];
	char bufferJuego[1024];

	Arcade* newArcade;

	if(pFile !=NULL && pArraylistArcades != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNacionalidad,bufferTipoSonido,bufferCantJug,bufferFichasMax,bufferSalon,bufferJuego);

		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNacionalidad,bufferTipoSonido,bufferCantJug,bufferFichasMax,bufferSalon,bufferJuego);
			if(cantidad < 7)
			{
				break;
			}

			newArcade = arcade_newParametros(bufferId,bufferNacionalidad,bufferTipoSonido,bufferCantJug,bufferFichasMax,bufferSalon,bufferJuego);
			ll_add(pArraylistArcades,newArcade);

			retorno=0;
		}
	}
    return retorno;
}

int parser_ArcadeFromTextEsc(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Arcade* auxArcade = NULL;
	int retorno=-1;
	int id;
	char nacionalidad[128];
	char tipoSonido[128];
	int cantJug;
	int fichasMax;
	char salon[128];
	char juego[63];

	if(pFile!=NULL && pArrayListEmployee !=NULL)
	{
		fprintf(pFile, "id,nacionalidad,tipoSonido,cantJug,fichasMax,salon,juego\n");

		for(int i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxArcade = (Arcade*)ll_get(pArrayListEmployee, i);
			if(auxArcade!=NULL)
			{
				if(arcade_getId(auxArcade, &id)==0 &&
				arcade_getNacionalidad(auxArcade, nacionalidad)==0 &&
				arcade_getTipoSonido(auxArcade, tipoSonido)==0 &&
				arcade_getCantJug(auxArcade, &cantJug)==0 &&
				arcade_getFichasMax(auxArcade, &fichasMax)==0 &&
				arcade_getSalon(auxArcade, salon)==0 &&
				arcade_getJuego(auxArcade, juego)==0)
				{
				fprintf(pFile,"%d,%s,%s,%d,%d,%s,%s\n", id, nacionalidad, tipoSonido, cantJug, fichasMax, salon, juego);
				retorno=0;
				}
			}
		}
	}

	return retorno;
}
