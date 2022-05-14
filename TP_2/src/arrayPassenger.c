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

int occupiedSpace (sPassenger* list, int len)
{
	int index;
	int i;

	index = VACIO;

	for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == OCUPADO)
			{
				index = i;
				break;
			}
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
	int i;

		index = -1;

		for (i = 0; i < len; i++)
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
		return passengerIndex;
	}

	return passengerIndex;
}

int showPassengers (sPassenger* list, int size, sTypePassenger typePassenger[],sStatusFlight statusFlight[])
{
	int i;
	int indexType;
	int indexStatus;

	printf("===============================================================================================================\n"
			"||ID     ||NOMBRE       ||APELLIDO     ||PRECIO       ||FLYCODE   ||TIPO PASAJERO       ||ESTADO VUELO        ||\n"
			"==============================================================================================================\n");

	for (i = 0; i < size; i++)
	{
		indexType = indexTypePassenger(list[i],typePassenger, 4);
		indexStatus = indexStatusFlight(list[i],statusFlight, 3);
		if (list[i].isEmpty == OCUPADO)
		{
			printf("||%-7d||%-13s||%-13s||%-13.2f||%-10s||%-20s||%-20s||\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, typePassenger[indexType].typePassenger , statusFlight[indexStatus].statusFlight );
		}
	}

	printf("===============================================================================================================\n");

	return 0;
}

int indexTypePassenger(sPassenger list, sTypePassenger typePassenger[], int typePassengerSize)
{
	int index;
	int i;

	for (i = 0; i < typePassengerSize; i++)
	{
		if (list.idTypePassenger == typePassenger[i].idTypePassenger)
		{
			index = i;
			break;
		}
	}
	return index;
}

int indexStatusFlight(sPassenger list, sStatusFlight statusFlight[], int statusFlightSize)
{
	int index;
	int i;

	for (i = 0; i < statusFlightSize; i++)
	{
		if (list.idStatusFlight == statusFlight[i].idStatusFlight)
		{
			index = i;
			break;
		}
	}
	return index;
}

int informData (sPassenger* list, int len, sTypePassenger typePassenger[], sStatusFlight statusFlight[])
{
	int option;
	int subOption;
	int order;
	int totalPassengers;
	int finalPrice;
	int average;
	int passengersOverAveragePrice;

	option = 0;
	subOption = 0;
	order = 0;
	totalPassengers = countPassengers(list, len);
	finalPrice = countPassengersPrices(list, len);
	average = calculateAveragePrice(list, len);
	passengersOverAveragePrice = countPassengrOverAveragePrice (list, len);

	do
	{
		printf("|----- > Seleccione una opcion < -----|\n\n");
		printf("\n1-| Informar PASAJEROS  |->");
		printf("\n2-| Informar PROMEDIO y TOTAL |->");
		printf("\n3-| SALIR |->\n");

		printf("\nIngrese opcion:");

		fflush(stdin);
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				printf("|----- > Seleccione una opcion < -----|\n\n");
				printf("\n1-| Ordenados ALFABETICAMENTE y por TIPO DE PASAJERO  |->");
				printf("\n2-| Ordenados por CODIGO DE VUELO |->");
				printf("\n3-| SALIR |->\n");

				printf("\nIngrese opcion:");

				fflush(stdin);
				scanf("%d", &subOption);

				switch (subOption)
				{
					case 1:
						printf("|----- > Seleccione una opcion < -----|\n\n");
						printf("\n1-| Ordenar de MENOR a MAYOR  |->");
						printf("\n2-| Ordenar de MAYOR a MENOR |->");

						printf("\nIngrese opcion:");

						fflush(stdin);
						scanf("%d", &order);

						sortByLastName(list, len, order);
						showPassengers (list, len, typePassenger, statusFlight);
					break;
					case 2:
						printf("|----- > Seleccione una opcion < -----|\n\n");
						printf("\n1-| Ordenar de MENOR a MAYOR  |->");
						printf("\n2-| Ordenar de MAYOR a MENOR |->");

						printf("\nIngrese opcion:");

						fflush(stdin);
						scanf("%d", &order);

						sortByFlyCode(list, len, order);
						showPassengers (list, len, typePassenger, statusFlight);
					break;
					case 3:
						system("pause");
					break;
					default:
					break;
				}

			break;
			case 2:
				printf("-| VALOR TOTAL: [$%d] |->\n", finalPrice);
				printf("-| PROMEDIO DE PRECIOS: [$%d] |->\n", average);
				printf("-| TOTAL PASAJEROS: [%d] |->\n", totalPassengers);
				printf("-| CANTIDAD DE PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO: [%d] |->\n", passengersOverAveragePrice);
			break;
			case 3:
				system("pause");
			break;
			default:
				printf("|----- > OPCION INVALIDA < -----|\n\n");
			break;
		}
	}while (option != 3);

	return 0;
}

int sortByLastName(sPassenger list[], int size, int order)
{
	sPassenger aux;

	if (list != NULL || size >= 0)
	{
		if (order == 1)
		{
			for(int i = 0; i < size - 1; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(list[i].lastName, list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if (strcmp(list[i].lastName, list[j].lastName) == 0)
					{
						if (list[i].idTypePassenger > list[j].idTypePassenger)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		else
		{
			for(int i = 0; i < size - 1; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(list[i].lastName, list[j].lastName) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if (strcmp(list[i].lastName, list[j].lastName) == 0)
					{
						if (list[i].idTypePassenger < list[j].idTypePassenger)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}

		return 0;
}

int sortByFlyCode(sPassenger list[], int size, int order)
{
	sPassenger aux;

	if (list != NULL || size >= 0)
	{
		if (order == 1)
		{
			for(int i = 0; i < size - 1; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(list[i].flycode, list[j].flycode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if (strcmp(list[i].flycode, list[j].flycode) == 0)
					{
						if (list[i].idStatusFlight > list[j].idStatusFlight)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		else
		{
			for(int i = 0; i < size - 1; i++)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(list[i].flycode, list[j].flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if (strcmp(list[i].flycode, list[j].flycode) == 0)
					{
						if (list[i].idStatusFlight < list[j].idStatusFlight)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}

	return 0;
}

int addForcedPassengers(sPassenger* list, int size)
{
	sPassenger forcedPassengers[5] = {{0, "JUAN", "PEREZ", 2500, "A021" , 4, 1, -1},
										{0,"PATRICIO", "PEREZ", 2200, "A32" , 3, 1, -1},
										{0, "THOMAS", "WATTERSON", 1500, "B11" , 2, 2, -1},
										{0, "FLORENCIA", "FRANCO", 500, "B31" , 1, 3, -1},
										{0, "VALENTINA", "FRANCO", 8500, "C91" , 4, 2, -1}};
	int i;

	for (i = 0; i < 5; i++)
	{
		forcedPassengers[i].id = idGenerator();
		list[i] = forcedPassengers[i];
	}

	return 0;
}


