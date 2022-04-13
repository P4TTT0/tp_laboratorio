/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: patri
 */

#include <stdio.h>
#include <stdlib.h>

void Separador()
{
	printf("\n|-------------------------------------|\n");
}

void Clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void Error(char tipoError [], char mensaje [])
{
	printf("|--- ERROR (invalid %s) %s ---|\n\n", tipoError, mensaje);
}

void OpcionElegida(int opcionIngresada)
{
	printf("|---------- OPCION >%d< ----------|\n\n", opcionIngresada);
}

float ValidarNumero(char mensaje [], float numeroMin, float numeroMax)
{
	float kilometrosIngresados;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &kilometrosIngresados);

	while(kilometrosIngresados < numeroMin || kilometrosIngresados > numeroMax)
	{
		Error("number range", "INGRESE UN RANGO NUMERICO VALIDO");
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &kilometrosIngresados);
	}

	return kilometrosIngresados;
}

void SystemPause(char mensaje [])
{
	printf("%s", mensaje);
	system("pause");
	Clear();
}

float CalcularPrecioDebito(float precioBruto)
{
	int descuento;
	float precioDescuento;
	float precioFinal;

	descuento = 10;

	precioDescuento = precioBruto * descuento / 100;

	precioFinal = precioBruto - precioDescuento;

	return precioFinal;
}

float CalcularPrecioCredito(float precioBruto)
{
	int interes;
	float precioInteres;
	float precioFinal;

	interes = 25;

	precioInteres = precioBruto * interes / 100;

	precioFinal = precioBruto + interes;

	return precioFinal;
}

float CalcularPrecioBitcoin(float precioBruto)
{
	float precioFinal;

	precioFinal = precioBruto / 4606954.55;

	return precioFinal;
}

float CalcularPrecioUnitario(float kilometros, float precioBruto)
{
	float precioFinal;

	precioFinal = kilometros / precioBruto;

	return precioFinal;
}

float CalcularDiferenciaPrecio(float precioBrutoUno, float precioBrutoDos)
{
	float diferenciaPrecio;

	if (precioBrutoUno > precioBrutoDos)
	{
		diferenciaPrecio = precioBrutoUno - precioBrutoDos;
	}
	else
	{
		diferenciaPrecio = precioBrutoDos - precioBrutoUno;
	}

	return diferenciaPrecio;
}

int informarDatos(int opcion)
{
	if (opcion == 1);

	return 0;
}



