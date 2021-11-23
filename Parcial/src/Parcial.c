#include <stdio.h>
#include <stdlib.h>
#include "Arcade.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn_biblioteca.h"
#include "parser.h"

/****************************************************
Estamos en el año 1990!
Una cadena de videojuegos necesita gestionar sus salones ubicados en los distintos shoppings del país, para ello es
necesario desarrollar un software que contará con el siguiente menú:
1)
Se lee de archivo arcades.csv provisto, la lista de arcades del sistema, y se cargan en una LinkedLIst.
2)
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, Nombre del salón al que pertenece y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE. Actualizar el archivo CSV con el arcade agregado
3) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego. Actualizar el archivo CSV con
el arcade modificado.
4)
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
confirmando si está seguro dar de baja esté mismo. Actualizar el archivo CSV con el arcade aeliminado.
5) IMPRIMIR ARCADES ordenados por nombre de juego
Se imprime la lista de arcades con ID, y sus datos.
6) Generar archivo con JUEGOS
Se generará un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.
7) Generar un archivo con arcades “Multijugador” (mas de 1 jugador)
Se generará un archivo “multijugador.csv” con el mismo formato que arcades.csv (incluida la cabecera), que
contenga solo los arcades que tengan mas de 1 jugador.
8) Actualizar cantidad de fichas
La empresa compró una actualizacion para que los arcades soporten el doble de fichas, por lo que debe
actualizarse el valor de fichas en el archivo. Al elegir esta opcion, se duplicará el valor de cantidad de fichas de todos
los arcades.~
DATOS
TIPOS DE SONIDO PARA ARCADE
MONO
ESTÉREO
Un arcade solo pertenece a un solo salón.
Un arcade solo contiene un juego.
Utilizar LinkedList para la lista de arcades.
Implementar y utilizar la funcion ll_filter para el punto 7.
Implementar y utilizar la funcion ll_sort para el punto 5.
Implementar y utilizar la funcion ll_map para el punto 8.
Generar un ID auto incrementable para cada entidad.
Tratar a el “tipo” sonido como valor numéricos relacionado con DEFINE.
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.).
Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaArcades = ll_newLinkedList();
    int option;
    do{
    	if (utn_getNumeroInt(&option, "\nBienvenido \n1)Leer arcades desde el archivo \n2)Incorporar arcade \n3)Modificar arcade \n4)Eliminar arcade \n5)Imprimir arcades ordenados por nombre de juego \n6)Generar archivo con juegos \n7)Generar archivo con arcades 'Multijugador' \n8)Actualizar cantidad de fichas \n9)Salir \n", "\nError opcion Invalida",  1, 9, 5)==0)
    	{
			switch(option)
			{
				case 1:
					// 1) LEER ARCADES DESDE ARCHIVO CSV
					if(controller_loadFromText("arcades.csv",listaArcades)==0)
					{
						printf("Se cargaron los datos como texto");
					}
					else
					{
						printf("Hubo un error");
					}
					break;
				case 2:
					// 2) INCORPORAR ARCADE
					if(controller_addArcade(listaArcades) == 0)
					{
						printf("Arcade agregado con exito");
					}
					else
					{
						printf("No se pudo cargar el arcade");
					}
					break;
				case 3:
					// 3) MODIFICAR ARCADE
						if(controller_editArcade(listaArcades) == 0)
						{
							printf("Arcade modificado con exito");
						}
						else
						{
							printf("No se pudo editar el arcade");
						}
					break;
				case 4:
					// 4) ELIMINAR ARCADE
					if(controller_removeArcade(listaArcades) == 0)
					{
						printf("Arcade borrado con exito");
					}
					else
					{
						printf("No se pudo borrar el arcade");
					}
					break;
				case 5:
					// 5) IMPRIMIR ARCADES ordenados por nombre de juego
					if(controller_sortArcade(listaArcades) == 0)
					{
						printf("\nArcades ordenados y listados");
					}
					else
					{
						printf("\nNo se pudo ordenar y listar los arcades");
					}
					break;
				case 6:
					// 6) Generar archivo con JUEGOS
					if(controller_ArchivoJuegos("juegos.txt",listaArcades)==0)
					{
						printf("Se archivaron los juegos");
					}
					else
					{
						printf("No se pudo archivar los juegos");
					}
					break;
				case 7:
					// 7) Generar un archivo con arcades “Multijugador” (mas de 1 jugador)
					if(controller_FilterMulti(listaArcades)==0)
					{
						printf("Se genero un archivo con arcades multijugador");
					}
					else
					{
						printf("No se pudo generar un archivo con arcades multijugador");
					}
					break;
				case 8:
					// 8) Actualizar cantidad de fichas
					if(actualizarCantFichas(listaArcades)==0)
					{
						printf("Se actualizó la cantidad maxima de fichas");
					}
					else
					{
						printf("No se puedo actualizar la cantidad maxima de fichas");
					}
					break;
				case 9:
					printf("Saliendo");
					break;
			}
    	}
	}while (option <9);
return 0;
}
