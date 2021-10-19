 /*
 * informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: USURIO
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include "Salon.h"
#include "Arcade.h"


int inf_CuatroArcades(Salon* salonList, int salonLen, Arcade* arcadeList, int arcadeLen);
int inf_ArcadeDosJugadores(Arcade* arcadeList, int arcadeLen, Salon* salonList, int salonLen);
int inf_SalonDetallado(Salon* salonList, int salonLen, Arcade* arcadeList, int arcadeLen, int id);
int inf_ListarArcades(Arcade* arcadeList, int arcadeLen, Salon* listSalon, int lenSalon, int id);
int inf_ListarMayorCantidad(Arcade* arcadeList, int arcadeLen, Salon* salonList, int salonLen);
int inf_CalcularValorMax(Arcade* arcadelist, int len, int id, int valor);
int inf_ContJuegos(Arcade* list, int len, char ingreso[]);


#endif /* INFORMES_H_ */
