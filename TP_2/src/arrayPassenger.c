/*
 * arrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: patri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "input.h"

int idCounter = 0;

int idGenerator()
{
	idCounter++;

	return idCounter;
}

int initPassengers(sPassenger* list, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		list[i].isEmpty = VACIO;
	}

	return 0;
}

sPassenger getPassenger (sTypePassenger typePassenger[], sStatusFlight statusFlight[])
{
	sPassenger onePassenger;
	int validator;

	validator = 0;

	//Genera ID y se guarda en su variable.
	onePassenger.id = idGenerator();

	//Pide nombre.
	printf("<|---NOMBRE|\n1-Ingrese el nombre: \n");
	//Guarda en la variable NAME.
	scanf("%s", onePassenger.name);

	validator = validateCharacter(onePassenger.name);

	while (validator == 0)
	{
		//Pide nombre.
		printf("<|---NOMBRE (ERROR) |\n1-Ingrese el nombre: \n");
		//Guarda en la variable NAME.
		scanf("%s", onePassenger.name);
		validator = validateCharacter(onePassenger.name);
	}

	//Pide apellido.
	printf("<|---APELLIDO|\n-Ingrese el apellido: \n");
	//Guarda en la variable LASTNAME.
	scanf("%s", onePassenger.lastName);

	validator = validateCharacter(onePassenger.lastName);

	while (validator == 0)
	{
		//Pide apellido.
		printf("<|---APELLIDO|\n-Ingrese el apellido: \n");
		//Guarda en la variable LASTNAME.
		scanf("%s", onePassenger.lastName);
		validator = validateCharacter(onePassenger.lastName);
	}

	//Pide precio.
	printf("<|---PRECIO|\n-Ingrese el precio: \n");
	//Guarda en la variable PRICE.
	fflush(stdin);
	scanf("%f", &onePassenger.price);
	//Pide codigo de vuelo.
	printf("<|---CODIGO DE VUELO|\n-Ingrese el codigo de vuelo: \n");
	//Guarda en la variable FLYCODE.
	scanf("%s", onePassenger.flycode);
	//Pide tipo de pasajero.
	printf("<|---TIPO DE PASAJERO|\n-Ingrese el tipo de pasajero: \n");
	optionsTypePassenger(typePassenger, 4);
	//Guardar en la variable TYPEPASSENGER.
	fflush(stdin);
	scanf("%d", &onePassenger.idTypePassenger);
	//Pide tipo de pasajero.
	printf("<|---ESTADO DEL VUELO|\n-Ingrese el estado del vuelo: \n");
	optionStatusFlight(statusFlight, 3);
	//Guardar en la variable TYPEPASSENGER.
	fflush(stdin);
	scanf("%d", &onePassenger.idStatusFlight);

	return onePassenger;
}

//Retorna el indice, 0 = OCUPADO de lo contrario devuelve el indice vacio.
int freeSpace (sPassenger* list, int len)
{
	int index;
	int i;

	index = OCUPADO;

	for (i = 0; i < len; i++)
	{
		if (list[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int addPassenger(sPassenger *list, int len, sTypePassenger typePassenger[], sStatusFlight statusFlight[])
{
	int index;

	index = freeSpace(list, len);

	if (index != OCUPADO)
	{
		list[index] = getPassenger(typePassenger, statusFlight);
		list[index].isEmpty = OCUPADO;
	}
	return index;
}

int optionsTypePassenger(sTypePassenger typePassenger[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf ("\n [%d] <|- %s\n", typePassenger[i].idTypePassenger, typePassenger[i].typePassenger);
	}

	return 0;
}

int optionStatusFlight(sStatusFlight statusFlight[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf ("\n [%d] <|- %s\n", statusFlight[i].idStatusFlight, statusFlight[i].statusFlight);
	}

	return 0;
}

int findPassengerById(sPassenger* list, int len, int id)
{
	int index;

		index = -1;

		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				index = i;
				break;
			}
		}
		return index;
}

int modifyData (sPassenger* list, sTypePassenger typePassenger[], sStatusFlight statusFlight[])
{
	int auxId;
	int passengerIndex;
	int indexType;
	int indexStatus;
	int subOption;

	auxId = 0;
	passengerIndex = 0;
	indexType = 0;
	indexStatus = 0;
	subOption = 0;

	printf("\n\n|----MODIFICAR PASAJERO----|\n\n"
			"<|---INGRESE EL [ID]\n"
			"-Ingrese el [ID] del pasajero a modificar");
	scanf("%d", &auxId);
	passengerIndex = findPassengerById(list, LEN, auxId);

	while (passengerIndex == -1)
	{
		printf( "<|---INGRESE EL [ID] (ERROR - ID NO ENCONTRADO)\n"
				"-Ingrese el [ID] del pasajero a modificar");
		scanf("%d", &auxId);

		passengerIndex = findPassengerById(list, LEN, auxId);
	}

	do
	{
		indexType = indexTypePassenger(list[passengerIndex],typePassenger, 4);
		indexStatus = indexStatusFlight(list[passengerIndex],statusFlight, 3);

		printf("|----- > Seleccione una opcion < -----|\n\n");
		printf("|---| PASAJERO |-> [%d]\n", auxId);
		printf("\n1-| Modificar NOMBRE|-> [%s]", list[passengerIndex].name);
		printf("\n2-| Modificar APELLIDO|-> [%s]", list[passengerIndex].lastName);
		printf("\n3-| Modificar PRECIO|-> [%f]", list[passengerIndex].price );
		printf("\n4-| Modificar CODIGO DE VUELO|-> [%s]", list[passengerIndex].flycode);
		printf("\n5-| Modificar TIPO DE PASAJERO|-> [%d] <|- [%s]", list[passengerIndex].idTypePassenger, typePassenger[indexType].typePassenger);
		printf("\n6-| Modificar ESTADO VUELO|-> [%d] <|- [%s]", list[passengerIndex].idStatusFlight, statusFlight[indexStatus].statusFlight);
		printf("\n7-| SALIR |->\n");

		printf("\nIngrese opcion:");

		scanf("%d", &subOption);
		fflush(stdin);
		switch(subOption)
		{
			case 1:
				printf("\n\n|---| NOMBRE ACTUAL |-> [%s]\n", list[passengerIndex].name);
				printf("\n\n-| Ingrese el nuevo nombre |->");
				gets(list[passengerIndex].name);
			break;
			case 2:
				printf("\n\n|---| APELLIDO ACTUAL |-> [%s]\n", list[passengerIndex].lastName);
				printf("\n\n-| Ingrese el nuevo apellido|->");
				gets(list[passengerIndex].lastName);
			break;
			case 3:
				printf("\n\n|---| PRECIO ACTUAL |-> [%f]\n", list[passengerIndex].price);
				printf("\n\n-| Ingrese el nuevo apellido |->");
				fflush(stdin);
				scanf("%f", &list[passengerIndex].price);
			break;
			case 4:
				printf("\n\n|---| CODIGO DE VUELO ACTUAL |-> [%s]\n", list[passengerIndex].flycode);
				printf("\n\n-| Ingrese el nuevo codigo de vuelo |->");
				gets(list[passengerIndex].flycode);
			break;
			case 5:
				printf("\n\n|---| TIPO DE PASAJERO ACTUAL |-> [%d] <|- [%s]", typePassenger[indexType].idTypePassenger, typePassenger[indexType].typePassenger);
				printf("\n\n-| Ingrese el nuevo tipo de pasajero |->");
				optionsTypePassenger(typePassenger, 4);
				fflush(stdin);
				scanf("%d", &list[passengerIndex].idTypePassenger);
			break;
			case 6:
				printf("\n\n|---| ESTADO DE VUELO ACTUAL |-> [%d] <|- [%s]", statusFlight[indexStatus].idStatusFlight, statusFlight[indexStatus].statusFlight);
				printf("\n\n-| Ingrese el nuevo estado de vuelo |->");
				optionStatusFlight(statusFlight, 3);
				fflush(stdin);
				scanf("%d", &list[passengerIndex].idStatusFlight);
			break;
			case 7:
				system("pause");
			break;
			default:
				printf("\n\n|---| OPCION INVALIDA |>\n\n");
			break;
		}
	}while(subOption != 7);

	return 0;
}

int deletePassenger(sPassenger* list, int size)
{
	int auxId;
	int passengerIndex;

	auxId = 0;
	passengerIndex = 0;

	printf("\n\n|----ELIMINAR PASAJERO----|\n\n"
				"<|---INGRESE EL [ID]\n"
				"-Ingrese el [ID] del pasajero a eliminar");
	scanf("%d", &auxId);
	passengerIndex = findPassengerById(list, size, auxId);

	while (passengerIndex == -1)
	{
		printf( "<|---INGRESE EL [ID] (ERROR - ID NO ENCONTRADO)\n"
				"-Ingrese el [ID] del pasajero a modificar");
		scanf("%d", &auxId);

		passengerIndex = findPassengerById(list, size, auxId);
	}

	if (list[passengerIndex].isEmpty == OCUPADO)
	{
		list[passengerIndex].isEmpty = VACIO;
		return 0;
	}

	return 1;
}

