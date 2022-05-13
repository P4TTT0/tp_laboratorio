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

//Retorna el indice, 0 = OCUPADO de lo contrario devuelve el indice vacio.
int freeSpace (sPassenger* list, int len)
{
	int index;

	index = OCUPADO;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int addPassenger(sPassenger* list, int len, int id, char name[], char lastName[], float price, char flycode[], int typePassenger, int statusFlight)
{
	int index;

	index = freeSpace(list, len);

	if (index != OCUPADO)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		strcpy(list[index].flycode, flycode);
		list[index].idTypePassenger = typePassenger;
		list[index].idStatusFlight = statusFlight;
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
			if (list[i].id == id)
			{
				index = i;
				break;
			}
		}
		return index;
}

