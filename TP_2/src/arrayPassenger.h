/*
 * arrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: patri
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TAM 25
#define VACIO 1
#define LEN 2000
#define OCUPADO -1

typedef struct
{
	int idStatusFlight;
	char statusFlight[TAM];
}sStatusFlight;

typedef struct
{
	int idTypePassenger;
	char typePassenger[TAM];
}sTypePassenger;

typedef struct
{
	int id;
	char name[TAM];
	char lastName[TAM];
	float price;
	char flycode[TAM];
	int idTypePassenger;
	int idStatusFlight;
	int isEmpty;
}sPassenger;

int idGenerator();

sPassenger getPassenger(sTypePassenger typePassenger[], int typePassengerSize);

int initPassengers(sPassenger* list, int len);

int freeSpace (sPassenger* list, int len);

int addPassenger(sPassenger *list, int len, int id, char name[], char lastName[], float price, char flycode[], int typePassenger, int statusFlight);

int optionsTypePassenger(sTypePassenger typePassenger[], int size);

int optionStatusFlight(sStatusFlight statusFlight[], int size);

int findPassengerById(sPassenger* list, int len, int id);

#endif /* ARRAYPASSENGER_H_ */
