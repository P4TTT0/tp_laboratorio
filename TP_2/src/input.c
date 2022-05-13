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

/*int validateFloat (char message[], int max, int min)
{
	int validator;

}*/



