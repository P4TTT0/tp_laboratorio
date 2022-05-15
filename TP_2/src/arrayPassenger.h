/*
 * arrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: Perez Cardenal Patricio
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

/// @fn int idGenerator()
/// @brief Genera un ID que comienza en 0 y va incrementando cada vez que es llamada.
///
/// @return Retorna el ID generado.
int idGenerator();

/// @fn sPassenger getPassenger(sTypePassenger[], sStatusFlight[])
/// @brief Crea un pasajero del tipo Spassenger, luego pide cada uno de los datos de la estrcutura y los almacena en las variables de dicho pasajero.
///
/// @param typePassenger Array del tipo sTypePassenger para pasar por parametro a otra funcion dentro de la misma.
/// @param statusFlight Array del tipo sStatusFlight para pasar por parametro a otra funcion dentro de la misma.
/// @return Retorna el pasajero creado con todos sus datos almacenados.
sPassenger getPassenger (sTypePassenger typePassenger[], sStatusFlight statusFlight[]);

/// @fn int initPassengers(sPassenger*, int)
/// @brief Inicializa todas las variables isEmpty en VACIO = (1) del array pasado por parametro.
///
/// @param list Puntero a array de pasajeros.
/// @param len Longitud del array de pasajeros.
/// @return Retorna 0.
int initPassengers(sPassenger* list, int len);

/// @fn int freeSpace(sPassenger*, int)
/// @brief Busca un espacio libre recorriendo el array y analizando la variable isEmpty de acada una.
///
/// @param list Puntero a array de pasajeros.
/// @param len Longitud del array de pasajeros.
/// @return Retorna OCUPADO (-1) si no encuentra espacio libre || Retorna el indice en el cual haya encontrado un espacio libre.
int freeSpace (sPassenger* list, int len);

/// @fn int occupiedSpace(sPassenger*, int)
/// @brief Busca un espacio ocupado reccoriendo el array y analizando la variable isEmpty de cada una.
///
/// @param list Puntero a array de pasajeros.
/// @param len Longitud del array de pasajeros.
/// @return Retorna VACIO (1) si no encuentra espacio ocupado || Retorna el indice en el cual haya encontrado un espacio ocupado.
int occupiedSpace (sPassenger* list, int len);

/// @fn int addPassenger(sPassenger*, int, sTypePassenger[], sStatusFlight[])
/// @brief Añade un pasajero del tipo sPassenger creado con la funcion [getPassenger] al array de los pasajeros.
///
/// @param list Puntero a array de pasajeros.
/// @param len Longitud del array de pasajeros.
/// @param typePassenger Array del tipo sTypePassenger para pasar por parametro a otra funcion dentro de la misma.
/// @param statusFlight Array del tipo sStatusFlight para pasar por parametro a otra funcion dentro de la misma.
/// @return
int addPassenger(sPassenger *list, int len, sTypePassenger typePassenger[], sStatusFlight statusFlight[]);

/// @fn int optionsTypePassenger(sTypePassenger[], int)
/// @brief Recorre la lista typePassenger printeando los diferentes valores del array de tipo sTypePassenger.
///
/// @param typePassenger Array de la lista de tipo de pasajeros
/// @param size Longitud del array de la lista de tipo de pasajeros.
/// @return Retorna 0.
int optionsTypePassenger(sTypePassenger typePassenger[], int size);

/// @fn int optionStatusFlight(sStatusFlight[], int)
/// @brief Recorre la lista statusFlight printeando los diferentes valores del array de tipo sStatusFlight.
///
/// @param statusFlight Array de la lista de estados de vuelo.
/// @param size Longitud del array de la lista de estados de vuelo.
/// @return retorna 0.
int optionStatusFlight(sStatusFlight statusFlight[], int size);

/// @fn int findPassengerById(sPassenger*, int, int)
/// @brief Recorre el array de pasajeros analizando sus .id
///
/// @param list Puntero a array de pasajeros
/// @param len Longitud del array de pasajeros
/// @param id Id a buscar en dicho array
/// @return retorna el indice en donde se encuentre el ID a buscar
int findPassengerById(sPassenger* list, int len, int id);

/// @fn int modifyData(sPassenger*, int, sTypePassenger[], sStatusFlight[])
/// @brief Realiza la busca de un pasajero por ID y permite modificar todas sus variables.
///
/// @param list Puntero a array de pasajeros
/// @param len Longitud del array de pasajeros
/// @param typePassenger Array del tipo sTypePassenger para pasar por parametro a otra funcion dentro de la misma.
/// @param statusFlight Array del tipo sStatusFlight para pasar por parametro a otra funcion dentro de la misma.
/// @return retorna 0.
int modifyData (sPassenger* list, int len, sTypePassenger typePassenger[], sStatusFlight statusFlight[]);

/// @fn int deletePassenger(sPassenger*, int)
/// @brief Realiza la busqueda de un pasajero por ID y cambia su .isEmpty por VACIO (1)
///
/// @param list Puntero a array de pasajeros
/// @param size Longitud del array de pasajeros.
/// @return
int deletePassenger(sPassenger* list, int size);

/// @fn int showPassengers(sPassenger*, int, sTypePassenger[], sStatusFlight[])
/// @brief Realiza el print de una celda y los diferentes pasajeros con sus diferentes valores en cada respectiva fila y columna.
///
/// @param list Puntero a array de pasajeros
/// @param size Longitud del array de pasajeros.
/// @param typePassenger Array del tipo sTypePassenger para pasar por parametro a otra funcion dentro de la misma.
/// @param statusFlight Array del tipo sStatusFlight para pasar por parametro a otra funcion dentro de la misma.
/// @return retorna 0.
int showPassengers (sPassenger* list, int size, sTypePassenger typePassenger[],sStatusFlight statusFlight[]);

/// @fn int indexTypePassenger(sPassenger, sTypePassenger[], int)
/// @brief Relaciona el ID de la estructura sPassenger con el ID de la estrucutra sTypePassenger.
///
/// @param list Pasajero del array de pasajeros
/// @param typePassenger Array de opciones de tipo de pasajero
/// @param typePassengerSize Longitud del array de opciones de tipo de pasajeros
/// @return retorna el indice donde el .idTypePassenger del pasajero es igual al .idTypePassenger del listado de opciones.
int indexTypePassenger(sPassenger list, sTypePassenger typePassenger[], int typePassengerSize);

/// @fn int indexStatusFlight(sPassenger, sStatusFlight[], int)
/// @brief Relaciona el ID de la estructura sPassenger con el ID de la estrucutra sStatusFlight.
///
/// @param list Pasajero del array de pasajeros
/// @param statusFlight Array de opciones de estados de vuelo.
/// @param statusFlightSize Longitud del array de opciones de estados de vuelo.
/// @return retorna el indice donde el .idStatusFlightSize del pasajero es igual al .idStatusFlightSize del listado de opciones.
int indexStatusFlight(sPassenger list, sStatusFlight statusFlight[], int statusFlightSize);

/// @fn int informData(sPassenger*, int, sTypePassenger[], sStatusFlight[])
/// @brief Realiza un listado de las diferentes formas de informar la informacion.
///
/// @param list Puntero a array de pasajeros
/// @param len longitud de puntero a array de pasajeros.
/// @param typePassenger Array del tipo sTypePassenger para pasar por parametro a otra funcion dentro de la misma.
/// @param statusFlight Array del tipo sStatusFlight para pasar por parametro a otra funcion dentro de la misma.
/// @return retorna 0.
int informData (sPassenger* list, int len, sTypePassenger typePassenger[], sStatusFlight statusFlight[]);

/// @fn int sortByLastName(sPassenger[], int, int)
/// @brief Ordena los pasajeros por apellido y si los apellidos son iguales los ordena por tipo de pasajero.
///
/// @param list Array de pasajeros
/// @param size Longitud del array de pasajeros
/// @param order Opcion para elegir el orden (MENOR A MAYOR O MAYOR A MENOR)
/// @return retorna 0.
int sortByLastName(sPassenger list[], int size, int order);

/// @fn int sortByFlyCode(sPassenger[], int, int)
/// @brief Ordena los pasajeros por CODIGO DE VUELO y si los apellidos son iguales los estados de vuelos NORMAL.
///
/// @param list Array de pasajeros
/// @param size Longitud del array de pasajeros
/// @param order Opcion para elegir el orden (MENOR A MAYOR O MAYOR A MENOR)
/// @return retorna 0.
int sortByFlyCode(sPassenger list[], int size, int order);

/// @fn int addForcedPassengers(sPassenger*, int)
/// @brief Hardcodea un array de pasajeros que luego son añadidos al array de pasajeros principal con la funcion [addPassenger]
///
/// @param list Puntero a array de lista de pasajeros
/// @param size Longitud del array de lista de pasajeros
/// @return retorna 0.
int addForcedPassengers(sPassenger* list, int size);

#endif /* ARRAYPASSENGER_H_ */
