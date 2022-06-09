/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: PATRICIO PEREZ CARDENAL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

	/*int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;*/

Passenger* Passenger_new()
{
	Passenger* this;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* codigoVueloStr,char* estadoVueloStr)
{
	Passenger* this = NULL;
	int id;
	float precio;
	int tipoPasajero;

	this = Passenger_new(); //ASIGNAMOS ESPACIO EN MEMORIA DINAMICA.

	id = atoi(idStr);

	Passenger_setId(this, id);

	Passenger_setNombre(this, nombreStr);

	Passenger_setApellido(this, apellidoStr);

	precio = atof(precioStr);

	Passenger_setPrecio(this, precio);

	if (strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if (strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}

	Passenger_setTipoPasajero(this, tipoPasajero);

	Passenger_setCodigoVuelo(this, codigoVueloStr);

	Passenger_setEstadoVuelo(this, estadoVueloStr);

	if (this != NULL)
	{
		if(Passenger_setId(this, id) == -1 ||
		   Passenger_setNombre(this, nombreStr) == -1||
		   Passenger_setApellido(this, apellidoStr) == -1||
		   Passenger_setPrecio(this, precio) == -1||
		   Passenger_setTipoPasajero(this, tipoPasajero) == -1||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == -1)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}

//-------------------------------- [ID] --------------------------------------
int Passenger_setId(Passenger* this,int id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [NOMBRE] --------------------------------------
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [APELLIDO] --------------------------------------
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = 0;

	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [CODIGO DE VUELO] --------------------------------------
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [TIPO DE PASAJERO] --------------------------------------
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno;

	retorno = 0;

	if (this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [PRECIO] --------------------------------------
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;

	retorno = 0;

	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

//-------------------------------- [ESTADO DE VUELO] --------------------------------------
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, estadoVuelo);
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno;

	retorno = 0;

	if (this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->codigoVuelo);
		retorno = 1;
	}

	return retorno;
}
//-------------------------------- [BORRAR PASAJERO] --------------------------------------
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}
