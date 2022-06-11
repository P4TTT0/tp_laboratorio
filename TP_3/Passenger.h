/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[40];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

void Passenger_list(Passenger* this);

int SaveTxt(FILE* pFile, LinkedList* pArrayListPassenger);
int SaveBinary(FILE* pFile, LinkedList* pArrayListPassenger);

int Passenger_compareByName(void* nombreUno, void* nombreDos);
int Passenger_compareByApellido(void* apellidoUno, void* apellidoDos);
int Passenger_compareByPrecio(void* precioUno, void* precioDos);

int criterioOrdenamiento();

int Passener_buscarId(LinkedList* pArrayListPassenger, int id);

int Passenger_modificarNombre(LinkedList* pArrayListPassenger, int indice);
int Passenger_modificarApellido(LinkedList* pArrayListPassenger, int indice);
int Passenger_modificarPrecio(LinkedList* pArrayListPassenger, int indice);
int Passenger_modificarCodigoVuelo(LinkedList* pArrayListPassenger, int indice);
int Passenger_modificarTipoPasajero(LinkedList* pArrayListPassenger, int indice);
int Passenger_modificarEstadoVuelo(LinkedList* pArrayListPassenger, int indice);
#endif /* PASSENGER_H_ */
