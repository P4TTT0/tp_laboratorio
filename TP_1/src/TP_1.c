/*
 ============================================================================
 Name        : TP_1.c
 Author      : Perez Cardenal Patricio
 Version     :
 Copyright   : TTT
 Description : TP_1 GITHUB
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"

int main(void) {
	setbuf(stdout, NULL);

	int suma;

	suma = sumar();

	printf("La suma de ambos numeros es: %d", suma);

	return EXIT_SUCCESS;
}
