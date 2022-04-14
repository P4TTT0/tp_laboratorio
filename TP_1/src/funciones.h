/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Perez Cardenal Patricio
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn void Separador()
/// @brief Funcion estetica para colocar lineas separadoras.
///
void Separador();

/// @fn void Clear()
/// @brief Funcion estetica para simular (CLEAR).
///
void Clear();

/// @fn void Error(char[], char[])
/// @brief Funcion estetica para comentar un ERROR.
///
/// @param tipoError - Para indicar el tipo de error.
/// @param mensaje - Para indicar que debe hacer para solucionar dicho error.
void Error(char tipoError [], char mensaje []);

/// @fn void OpcionElegida(int)
/// @brief Funcion estetica para comentar la opcion elegida.
///
/// @param INT - Indicas el valor INTEGER de la opcion.
void OpcionElegida(int);

/// @fn float ValidarNumero(char[], float, float)
/// @brief Funcion para validar numero entre dos rangos numericos.
///
/// @param mensaje - Para indicar lo que debe ingresar.
/// @param numeroMin - Para indicar el rango minimo.
/// @param numeroMax - Para indicar el rango maximo.
/// @return Retorna el numero ingresado.
float ValidarNumero(char mensaje [], float numeroMin, float numeroMax);

/// @fn void SystemPause(char[])
/// @brief Funcion estetica para reiniciar sistema.
///
/// @param mensaje - Mensaje estetico.
void SystemPause(char mensaje []);

/// @fn float CalcularPrecioDebito(float)
/// @brief Funcion para calcular 10% de descuento.
///
/// @param precioBruto - Indicar el valor a aplicar dicho 10% de descuento.
/// @return Retorna el valor con dicho 10% de descuento aplicado.
float CalcularPrecioDebito(float precioBruto);

/// @fn float CalcularPrecioCredito(float)
/// @brief Funcion para calcular 25% de interes.
///
/// @param precioBruto - Indicar el valor a aplicar dicho 25% de interes.
/// @return Retorna el valor con dicho 25% de interes aplicado.
float CalcularPrecioCredito(float precioBruto);

/// @fn float CalcularPrecioBitcoin(float)
/// @brief Funcion para dividir un valor determinado por 1 BITCOIN.
///
/// @param precioBruto - Indicar valor para transformar a BITCOIN.
/// @return Retorna el valor ingresado transformado en BITCOIN.
float CalcularPrecioBitcoin(float precioBruto);

/// @fn float CalcularPrecioUnitario(float, float)
/// @brief Funcion para dividir un valor por una cantidad.
///
/// @param kilometros - Indicar CANTIDAD.
/// @param precioBruto - Indicar VALOR TOTAL.
/// @return Retorna el valor unitario de C/ CANTIDAD.
float CalcularPrecioUnitario(float kilometros, float precioBruto);

/// @fn float CalcularDiferenciaPrecio(float, float)
/// @brief Funcion para restar un valor mayor por un valor menor para calcular la diferencia entre los mismos.
///
/// @param precioBrutoUno - VALOR UNO
/// @param precioBrutoDos - VALOR DOS
/// @return Retorna la diferencia entre dos dichos valores.
float CalcularDiferenciaPrecio(float precioBrutoUno, float precioBrutoDos);

/// @fn int InformarDatos(int, float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Funcion para printear datos ingresados o para printear datos forzados.
///
/// @param opcion - Indicar informar datos ingresados (!0) o forzados (0).
/// @param kilometros - Indicar variable de kilometros.
/// @param precioLatam - Indicar variable de precio Latam
/// @param debitoLatam - Indicar variable de debito Latam
/// @param creditoLatam - Indicar variable de credito Latam
/// @param bitcoinLatam - Indicar variable de bitcoin Latam
/// @param unitarioLatam - Indicar variable de precio unitario Latam
/// @param precioAerolineas - Indicar variable de precio Aerolineas
/// @param debitoAerolineas - Indicar variable de debito Aerolineas
/// @param creditoAerolineas - Indicar variable de credito Aerolineas
/// @param bitcoinAerolineas - Indicar variable de bitcoin Aerolineas
/// @param unitarioAerolineas - Indicar variable de precio unitario Aerolineas
/// @param diferenciaPrecio - Indicar variable de diferencia de ambas AEROLINEAS.
/// @return - Retorna la opcion indicada.
int InformarDatos(int opcion, float kilometros, float precioLatam, float debitoLatam, float creditoLatam, float bitcoinLatam, float unitarioLatam, float precioAerolineas, float debitoAerolineas, float creditoAerolineas, float bitcoinAerolineas, float unitarioAerolineas, float diferenciaPrecio);

/// @fn void AnimacionApagado(void)
/// @brief Funcion estetica para simular carga de apagado.
///
void AnimacionApagado(void);

#endif /* FUNCIONES_H_ */
