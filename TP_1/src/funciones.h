/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Perez Cardenal Patricio
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void Separador();

void Clear();

void Error(char tipoError [], char mensaje []);

void OpcionElegida(int);

float ValidarNumero(char mensaje [], float numeroMin, float numeroMax);

void SystemPause(char mensaje []);

float CalcularPrecioDebito(float precioBruto);

float CalcularPrecioCredito(float precioBruto);

float CalcularPrecioBitcoin(float precioBruto);

float CalcularPrecioUnitario(float kilometros, float precioBruto);

float CalcularDiferenciaPrecio(float precioBrutoUno, float precioBrutoDos);

#endif /* FUNCIONES_H_ */
