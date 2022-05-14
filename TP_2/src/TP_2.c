/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"
#include "input.h"

#define LEN 2000

int main(void)
{
	setbuf(stdout, NULL);

	int option;
	int index;

	option = 0;
	index = 0;


	sPassenger passengers[LEN];
	sStatusFlight statusFlight[3] = {{1,"NORMAL"}, {2,"DEMORADO"}, {3, "CANCELADO"}};
	sTypePassenger typePassenger[4] = {{1, "ECONOMICO"}, {2, "PREMIUM"}, {3, "VIP"}, {4, "LORD"}};


	initPassengers(passengers, LEN);

	do
	{
		printf("|----- > Seleccione una opcion < -----|\n\n");
		printf("\n1-| Ingresar PASAJERO |->");
		printf("\n2-| Modificar PASAJERO |->");
		printf("\n3-| Eliminar PASAJERO |->");
		printf("\n4-| Informar PASAJEROS |->");
		printf("\n5-| Carga forzada de Pasajeros|->");
		printf("\n6-| SALIR |->\n");

		printf("\nIngrese opcion:");

		fflush(stdin);
		scanf("%d", &option);

		switch(option)
		{
			case 1:

				index = addPassenger(passengers, LEN, typePassenger, statusFlight);

				if (index == OCUPADO)
				{
					printf("\n <|-----LISTA LLENA-----|>");
					printf("\n (imposible guardar)\n");
				}
				else
				{
					printf("\n <|-----GUARDADO CON EXITO-----|>");
					printf("\n (Guardado en la posicion [%d] ID [%d])\n", index, passengers[index].id);
				}
			break;

			case 2:
				modifyData(passengers, typePassenger, statusFlight);
			break;

			case 3:
			break;

			case 4:
			break;

			case 5:
			break;

			case 6:
			break;

			default:
			break;
		}
	}while(option != 6);

	return EXIT_SUCCESS;
}
