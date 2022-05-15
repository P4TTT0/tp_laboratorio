/*
 * input.h
 *
 *  Created on: 12 may. 2022
 *      Author: Perez Cardenal Patricio
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @fn int validateCharacter(char[])
/// @brief Recorre un array de string y valida que contenga letras.
///
/// @param string Array a recorrer
/// @return Retorna 0 si se encontro algun numero || Retorna 1 si contiene unicamente letras.
int validateCharacter (char string[]);

/// @fn int countPassengers(sPassenger*, int)
/// @brief Recorre la lista de pasajeros analizando la variable isEmpty y cuenta la cantidad de pasajeros.
///
/// @param list Puntero a array de lista de pasajeros
/// @param size Longitud del array de lista de pasajeros
/// @return retorna la cantidad de pasajeros.
int countPassengers (sPassenger* list, int size);

/// @fn int countPassengersPrices(sPassenger*, int)
/// @brief Acumula los precios de los vuelos de los diferentes pasajeros
///
/// @param list Puntero a array de lista de pasajeros
/// @param size Longitud del array de lista de pasajeros
/// @return retorna el precio final de todos los pasajeros juntos
int countPassengersPrices (sPassenger* list, int size);

/// @fn int calculateAveragePrice(sPassenger*, int)
/// @brief Calcula el precio promedio entre el precio final y todos los pasajeros
///
/// @param list Puntero a array de lista de pasajeros
/// @param size Longitud del array de lista de pasajeros
/// @return retorna el promedio.
int calculateAveragePrice (sPassenger* list, int size);

/// @fn int countPassengrOverAveragePrice(sPassenger*, int)
/// @brief Recorre la lista de pasajeros y evalua quienes tengan un precio mayor al promedio
///
/// @param list Puntero a array de lista de pasajeros
/// @param size Longitud del array de lista de pasajeros
/// @return retorna la cantidad de pasajeros que su precio sea mayor al promedio
int countPassengrOverAveragePrice (sPassenger* list, int size);

/// @fn int orderInteger(char[])
/// @brief Pide un entero.
///
/// @param number array de numeros
/// @return retorna el entero.
int orderInteger(char number[]);

/// @fn int orderFloat(char[])
/// @brief Pide un flotante
///
/// @param numbersFloat
/// @return retorna el flotante
int orderFloat(char numbersFloat[]);

/// @fn int validateNumber(char[])
/// @brief Recorre un array evaluando si contiene digitos
///
/// @param numbers array de numeros
/// @return retorna Retorna 0 si contiene todo lo que no sean digitos || Retorna 1 si contiene unicamente numeros.
int validateNumber (char numbers[]);

#endif /* INPUT_H_ */
