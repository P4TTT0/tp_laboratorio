/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: patri
 */

#include <stdio.h>
#include <stdlib.h>

void separador()
{
	printf("\n|-------------------------------------|\n");
}

void Clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

float validarNumero(char mensaje [], float numeroMin, float numeroMax)
{
	float kilometrosIngresados;

	printf("%s", mensaje);
	scanf("%f", &kilometrosIngresados);
	while(kilometrosIngresados < numeroMin || kilometrosIngresados > numeroMax)
	{
		printf("|--- ERROR (invalid number range) INGRESE UN RANGO NUMERICO VALIDO ---|\n");
		printf("%s", mensaje);
		scanf("%f", &kilometrosIngresados);
	}
	return kilometrosIngresados;
}

