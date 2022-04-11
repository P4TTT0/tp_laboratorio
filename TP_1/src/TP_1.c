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
#include "funciones.h" //Incluir la bibloteca creada con ("")

void MenuPrincipal();

int main(void) {
	setbuf(stdout, NULL);

	MenuPrincipal();

	return EXIT_SUCCESS;
}

void MenuPrincipal()
{
	setbuf(stdout, NULL);

	int opcionIngresada;
	float x;

	do
	{
		printf("|----- > Seleccione una opcion < -----|\n\n");
		printf("\n1-| Ingresar KM |->");
		printf("\n2-| Ingresar precio de vuelvos |->");
		printf("\n3-| Calcular costos |->");
		printf("\n4-| Informar resultados |->");
		printf("\n5-| Carga forzada de datos |->");
		printf("\n6-| SALIR |->\n");

		separador();

		printf("\nIngrese opcion:");
		scanf("%d", &opcionIngresada);

		while(opcionIngresada < 1 || opcionIngresada > 6)
		{
			Clear();
			printf("|--- ERROR (invalid option) INGRESE UNA OPCION VALIDA ---|");
			printf("\nIngrese opcion:");
			scanf("%d", &opcionIngresada);
		}

		switch(opcionIngresada)
		{
		case 1:
			Clear();
			x = validarNumero("Ingrese los KM del viaje: ", 2.7, 21602);
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		case 6:
		break;
		}

	}while(opcionIngresada != 6);
}