/*
 * input.c
 *
 *  Created on: 12 may. 2022
 *      Author: patri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "input.h"

//1 = NO CONTIENE NUMEROS
//0 = SI CONTIENE NUMEROS
int validateCharacter (char string[])
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(string); i++)
	{
		if (isdigit(string[i]) || isalpha(string[i]) == 0)
		{
			validator = 0;
		}
	}
	return validator;
}

int validateNumber (char numbers[])
{
	int validator;
	int i;

	validator = 1;

	for(i = 0; i < strlen(numbers); i++)
	{
		if (!(isdigit(numbers[i])))
		{
			validator = 0;
		}
	}
	return validator;
}

int countPassengers (sPassenger* list, int size)
{
	int countPassenger;
	int i;

	countPassenger = 0;

	for (i = 0; i < size; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			countPassenger++;
		}
	}

	return countPassenger;
}

int countPassengersPrices (sPassenger* list, int size)
{
	int countPassengerPrices;
	int i;

	countPassengerPrices = 0;

	for (i = 0; i < size; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			countPassengerPrices = countPassengerPrices + list[i].price;
		}
	}

	return countPassengerPrices;
}

int calculateAveragePrice (sPassenger* list, int size)
{
	int average;
	int totalPassengers = countPassengers (list, size);
	int totalPassengerPrices = countPassengersPrices (list, size);

	average = totalPassengerPrices / totalPassengers;

	return average;
}

int countPassengrOverAveragePrice (sPassenger* list, int size)
{
	int average;
	int i;
	int countPassengersOverAveragePrice;

	countPassengersOverAveragePrice = 0;

	average = calculateAveragePrice(list, size);

	for (i = 0; i < size; i++)
	{
		if (list[i].isEmpty == OCUPADO)
		{
			if (list[i].price > average)
			{
				countPassengersOverAveragePrice++;
			}
		}
	}

	return countPassengersOverAveragePrice;
}
