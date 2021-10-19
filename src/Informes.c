/*
 * informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: USURIO
 */
#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
#include "Salon.h"
#include "Arcade.h"
#include "utn_biblioteca.h"

int inf_CuatroArcades(Salon* salonList, int salonLen, Arcade* arcadeList, int arcadeLen)
{
	int status = -1;
	int i;
	int j;
	int cont = 0;

	if(salonList != NULL && salonList > 0 && arcadeList != NULL && arcadeLen > 0)
	{

		for(i = 0; i < salonLen; i++)
		{
			if(salonList[i].flagEmpty == 0)
			{
				cont = 0;

				for(j = 0; j < arcadeLen; j++)
				{
					if(arcadeList[j].flagEmpty == 0 && arcadeList[j].idSalon == salonList[i].id)
					{
						cont++;
					}
				}

				if(cont > 4)
				{
					status = 0;
					switch(salonList[i].tipo)
					{
					case 1:
						printf("Id salon: %d, nombre del salon: %s, Direccion del salon: %s, Tipo: Local\n", salonList[i].id, salonList[i].nombreSalon, salonList[i].direccion);
						break;
					case 2:
						printf("Id salon: %d, Nombre del salon: %s, Direccion del salon: %s, Tipo: Shopping\n", salonList[i].id, salonList[i].nombreSalon, salonList[i].direccion);
						break;
					}
				}

			}
		}
	}
	return status;
}

int inf_ArcadeDosJugadores(Arcade* arcadeList, int arcadeLen, Salon* salonList, int salonLen)
{
	int status = -1;
	int i;
	int position;


	if(arcadeList != NULL && arcadeLen > 0 && salonList != NULL && salonLen > 0)
	{
		status = 0;
		for(i = 0; i < arcadeLen; i++)
		{
			if(arcadeList[i].flagEmpty == 1 && arcadeList[i].cantidadJugadores > 2)
			{
				position = findSalonById(salonList, salonList, arcadeList[i].idSalon);
				printf("Id arcade: %d, Cantidad de jugadores: %d, Nombre del juego: %s, Nombre del salón: %s\n", arcadeList[i].idArcade, arcadeList[i].cantidadJugadores, arcadeList[i].nombreJuego, salonList[position].nombreSalon);
			}
		}
	}
	return status;
}

int inf_SalonDetallado(Salon* salonList, int salonLen, Arcade* arcadeList, int arcadeLen, int id)
{
	int status = -1;
	int i;
	int contador = 0;

	if(salonList != NULL && salonLen > 0 && arcadeList != NULL && arcadeLen > 0 && id != 0)
	{
		status = 0;
		printf("Id salon: %d\n", salonList[id].id);
		printf("Nombre del salon: %s\n", salonList[id].nombreSalon);
		switch(salonList[id].tipo)
		{
		case 1:
			printf("Tipo: Local\n");
			break;
		case 2:
			printf("Tipo: Shopping\n");
			break;
		}
		printf("Dirección del salon: %s\n", salonList[id].direccion);
		for(i = 0; i < arcadeLen; i++)
		{
			if(arcadeList[i].flagEmpty == 0 && arcadeList[i].idSalon == id)
			{
				contador++;
			}
		}
		printf("Arcades dentro del salon: %d\n", contador);
	}

	return status;
}

int inf_ListarArcades(Arcade* arcadeList, int arcadeLen, Salon* listSalon, int lenSalon, int id)
{
	int status = -1;
	int i;

	if(arcadeList != NULL && arcadeLen > 0 && listSalon != NULL && lenSalon > 0 && id != -1)
	{
		status = 0;
		printf("Salon #%d\n", listSalon[id].id);
		switch(listSalon[id].tipo)
		{
		case 0:
			printf("Nombre del salon: %s, Tipo: LOCAL\n\n", listSalon[id].nombreSalon);
			break;
		case 1:
			printf("Nombre del salon: %s, Tipo: SHOPPING\n\n", listSalon[id].nombreSalon);
			break;
		}

		printf("Juegos");
		for(i = 0; i < arcadeLen; i++)
		{
			if(arcadeList[i].flagEmpty == 0 && arcadeList[i].idSalon == id)
			{
				switch(arcadeList[i].tipoDeSonido)
				{
				case 1:
					printf("Id arcade: %d, Nacionalidad: %s, Tipo de sonido: Mono, Cantidad de jugadores: %d, Capacidad de fichas máxima: %d, Nombre del juego: %s\n", arcadeList[i].idArcade, arcadeList[i].nacionalidad, arcadeList[i].cantidadJugadores, arcadeList[i].capacidadMaxFichas, arcadeList[i].nombreJuego);
					break;
				case 2:
					printf("Id arcade: %d, Nacionalidad: %s, Tipo de sonido: Estereo,  Cantidad de jugadores: %d, Capacidad de fichas máxima: %d, Nombre del juego: %s\n", arcadeList[i].idArcade, arcadeList[i].nacionalidad, arcadeList[i].cantidadJugadores, arcadeList[i].capacidadMaxFichas, arcadeList[i].nombreJuego);
					break;
				}
			}
		}
	}

	return status;
}

int inf_ListarMayorCantidad(Arcade* arcadeList, int arcadeLen, Salon* salonList, int salonLen)
{
	int status = -1;
	int i;
	int j;
	int cont;
	int idMax;
	int contadorMax;
	int flag = 0;

	if(arcadeList != NULL && arcadeLen > 0 && salonList != NULL && salonLen > 0)
	{
		status = 0;
		for(i = 0; i < salonLen; i++)
		{
			if(salonList[i].flagEmpty == 0)
			{
				cont = 0;
				for(j = 0; j < arcadeLen; j++)
				{
					if(arcadeList[j].flagEmpty == 0 && arcadeList[j].idSalon == salonList[i].id)
					{
						cont++;
					}
				}
				if(flag == 0 || cont > contadorMax)
				{
					idMax = i;
					contadorMax = cont;
					flag = 1;
				}
			}
		}
		printf("Id salon: %d\n", salonList[idMax].id);
		printf("Nombre del salon: %s\n", salonList[idMax].nombreSalon);
		printf("Dirección del salon: %s\n", salonList[idMax].direccion);
		switch(salonList[idMax].tipo)
		{
		case 1:
			printf("Tipo: Local\n");
			break;
		case 2:
			printf("Tipo: Shopping\n");
			break;
		}
		printf("Arcades que tiene el salon: %d\n", contadorMax);
	}

	return status;
}

int inf_CalcularValorMax(Arcade* arcadelist, int len, int id, int valor)
{
	int status = -1;
	int i;
	int cont = 0;
	int valorMax;

	if(arcadelist != NULL && len > 0 && id != 0)
	{
		status = 0;
		for(i = 0; i < len; i++)
		{
			if(arcadelist[i].flagEmpty == 0 && arcadelist[i].idSalon == id)
			{
				cont += arcadelist[i].capacidadMaxFichas;
			}
		}

		valorMax = cont * valor;
		printf("El salon con id %d acumularía $%d\n", id, valorMax);
	}
	return status;
}

int inf_ContJuegos(Arcade* arcadeList, int arcadeLen, char ingreso[])
{
	int status = -1;
	int i;
	int contador = 0;
	char aux[63];

	if(arcadeList != NULL && arcadeLen > 0 && strlen(ingreso) > 0)
	{
		status = 0;
		strlwr(ingreso);
		for(i = 0; i < arcadeLen; i++)
		{
			strcpy(aux, arcadeList[i].nombreJuego);
			strlwr(aux);

			if(arcadeList[i].flagEmpty && strcmp(ingreso, aux) == 0)
			{
				contador++;
			}
		}
		printf("Cantidad de arcades que contienen el juego: %d\n", contador);
	}

	return status;
}

