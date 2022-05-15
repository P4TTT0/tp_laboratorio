/*
 * input.c
 *
 *  Created on: 12 may. 2022
 *      Author: Perez Cardenal Patricio
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

int orderInteger(char message[])
{
	int integer;

	char number[1000];

	printf(message);
	scanf("%s", number);

	while(!validateNumber(number))
	{
		printf("\nERROR");
		printf(message);
		scanf("%s",number);
	}

	integer = atoi(number);

	return integer;
}

int orderFloat(char message[])
{
	int numberFloat;

	char numbersFloat[1000];

	printf(message);
	scanf("%s", numbersFloat);

	while(!validateNumber(numbersFloat))
	{
		printf("\n(ERROR)");
		printf(message);
		scanf("%s",numbersFloat);
	}

	numberFloat = atof(numbersFloat);

	return numberFloat;
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
