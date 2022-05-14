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

//int indexTypePassenger(sPassenger list[], int size, sTypePassenger typePassenger[], int typePassengerSize);

int indexTypePassenger(sPassenger list, sTypePassenger typePassenger[], int typePassengerSize);

int indexStatusFlight(sPassenger list, sStatusFlight statusFlight[], int statusFlightSize);

#endif /* INPUT_H_ */
