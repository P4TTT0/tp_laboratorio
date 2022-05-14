/*
 * input.h
 *
 *  Created on: 12 may. 2022
 *      Author: patri
 */

#ifndef INPUT_H_
#define INPUT_H_

int validateCharacter (char string[]);

int validateNumber (char numbers[]);

int countPassengers (sPassenger* list, int size);

int countPassengersPrices (sPassenger* list, int size);

int calculateAveragePrice (sPassenger* list, int size);

int countPassengrOverAveragePrice (sPassenger* list, int size);

int orderInteger(char number[]);

int orderFloat(char numbersFloat[]);

int validateNumber (char numbers[]);

#endif /* INPUT_H_ */
