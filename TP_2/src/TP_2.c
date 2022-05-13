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

int main(void)
{
	setbuf(stdout, NULL);

	int option;
	int subOption;

	int validator;
	int index;

	//------------VARIABLES AUXILIARES
	int auxId;
	char auxName[TAM];
	char auxLastName[TAM];
	float auxPrice;
	char auxFlyCode[TAM];
	int auxTypePassenger;
	int auxStatusFlight;
	//------------VARIABLES AUXILIARES

	int passengerId;

	option = 0;
	subOption = 0;

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

		scanf("%d", &option);
		fflush(stdin);

		switch(option)
		{
			case 1:

			//Genera ID y se guarda en su variable.
			auxId = idGenerator();

			//Pide nombre.
			printf("<|---NOMBRE|\n1-Ingrese el nombre: \n");
			//Guarda en la variable NAME.
			gets(auxName);

			validator = validateCharacter(auxName);

			while (validator == 0)
			{
				//Pide nombre.
				printf("<|---NOMBRE (ERROR) |\n1-Ingrese el nombre: \n");
				//Guarda en la variable NAME.
				gets(auxName);
				validator = validateCharacter(auxName);
			}

			//Pide apellido.
			printf("<|---APELLIDO|\n-Ingrese el apellido: \n");
			//Guarda en la variable LASTNAME.
			gets(auxLastName);

			validator = validateCharacter(auxLastName);

			while (validator == 0)
			{
				//Pide apellido.
				printf("<|---APELLIDO|\n-Ingrese el apellido: \n");
				//Guarda en la variable LASTNAME.
				gets(auxLastName);
				validator = validateCharacter(auxLastName);
			}

			//Pide precio.
			printf("<|---PRECIO|\n-Ingrese el precio: \n");
			//Guarda en la variable PRICE.
			scanf("%f", &auxPrice);
			fflush(stdin);
			//Pide codigo de vuelo.
			printf("<|---CODIGO DE VUELO|\n-Ingrese el codigo de vuelo: \n");
			//Guarda en la variable FLYCODE.
			scanf("%s", auxFlyCode);
			fflush(stdin);
			//Pide tipo de pasajero.
			printf("<|---TIPO DE PASAJERO|\n-Ingrese el tipo de pasajero: \n");
			optionsTypePassenger(typePassenger, 4);
			//Guardar en la variable TYPEPASSENGER.
			scanf("%d", &auxTypePassenger);
			fflush(stdin);
			//Pide tipo de pasajero.
			printf("<|---ESTADO DEL VUELO|\n-Ingrese el estado del vuelo: \n");
			optionStatusFlight(statusFlight, 3);
			//Guardar en la variable TYPEPASSENGER.
			scanf("%d", &auxStatusFlight);
			fflush(stdin);

			index = addPassenger(passengers, LEN, auxId, auxName, auxLastName, auxPrice, auxFlyCode, auxTypePassenger, auxStatusFlight);

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
				printf("\n\n|----MODIFICAR PASAJERO----|\n\n"
						"<|---INGRESE EL [ID]\n"
						"-Ingrese el [ID] del pasajero a modificar");
				scanf("%d", &auxId);

				passengerId = findPassengerById(passengers, LEN, auxId);

				if (passengerId == -1)
				{
					printf( "<|---INGRESE EL [ID] (ERROR - ID NO ENCONTRADO)\n"
							"-Ingrese el [ID] del pasajero a modificar");
					scanf("%d", &auxId);
				}
				do
				{
					printf("|----- > Seleccione una opcion < -----|\n\n");
					printf("\n1-| Modificar NOMBRE|->");
					printf("\n2-| Modificar APELLIDO|->");
					printf("\n3-| Modificar PRECIO|->");
					printf("\n4-| Modificar CODIGO DE VUELO|->");
					printf("\n5-| Modificar TIPO DE PASAJERO|->");
					printf("\n6-| Modificar ESTADO VUELO|->");
					printf("\n7-| SALIR |->\n");

					printf("\nIngrese opcion:");

					scanf("%d", &subOption);
					fflush(stdin);
					switch(subOption)
					{
						case 1:
							printf("Nombre %s", passengers[passengerId].name);
						break;
					}
				}while(subOption != 7);
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
