/*
 * calculcar.c
 *
 *  Created on: 7 abr. 2022
 *      Author: patri
 */
//.C Para guardar el desarrollo que cada funcion creada.

#include <stdio.h>
#include <stdlib.h>

int sumar(void) {
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUno);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDos);

	resultado = numeroUno + numeroDos;

	return resultado;
}

