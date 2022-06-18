#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int validacion = 0;
    int banderaTexto = 0;
    int banderaBinario = 0;
    int banderaGuardadoTexto = 1;
    int banderaGuardadoBinario = 1;

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* cloneArray = NULL;

    do
    {
    	printf("||----< | [MENU] | >---||\n\n"

    			"[1] | CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO TEXTO)\n"
    			"[2] | CARGAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO BINARIO)\n"
    			"[3] | CARGAR COPIA DE SEGURIDAD\n"
    			"[4] | CARGAR PASAJERO\n"
    			"[5] | MODIFICAR PASAJERO\n"
    			"[6] | ELIMINAR PASAJERO\n"
    			"[7] | LISTAR PASAJERO\n"
    			"[8] | ORDENAR PASAJEROS\n"
    			"[9] | GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO TEXTO)\n"
    			"[10]| GUARDAR LOS DATOS DE LOS PASAJEROS DESDE EL ARCHIVO 'data.csv' (MODO BINARIO)\n"
    			"[11]| GUARDAR COPIA DE SEGURIDAD\n"
    			"[12]| [SALIR]->|\n\n"

    			"||--->[INGRESAR OPCION]:");

    			fflush(stdin);
    			scanf("%d", &option);

        switch(option)
        {
            case 1:

            	if (ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
            	{
            		validacion = controller_loadFromText("data.csv",listaPasajeros);

					if (validacion == 1)
					{
						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
						ll_sort(listaPasajeros, Passenger_compareById, 1);
						system("pause");
						banderaTexto = 1;
					}
					else
					{
						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
						system("pause");
					}
            	}
            	else
            	{
            		printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
					system("pause");
            	}
			break;

            case 2:
            	if (ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
				{
					validacion = controller_loadFromBinary("data.bin",listaPasajeros);

					if (validacion == 1)
					{
						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
						ll_sort(listaPasajeros, Passenger_compareById, 1);
						system("pause");
						banderaBinario = 1;
					}
					else
					{
						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
						system("pause");
					}
				}
				else
				{
					printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 3:
            	if (ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
				{
					validacion = controller_loadFromText("backup.csv",listaPasajeros);

					if (validacion == 1)
					{
						printf("||----< [DATOS CARGADOS CORRECTAMENTES] >----\n");
						ll_sort(listaPasajeros, Passenger_compareById, 1);
						system("pause");
						banderaTexto = 1;
					}
					else
					{
						printf("||----< [ERROR] - NO SE HAN PODIDO CARGAR LOS DATOS. >----\n");
						system("pause");
					}
				}
				else
				{
					printf("||----< [ERROR] - LOS DATOS YA HAN SIDO CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 4:
            	controller_addPassenger(listaPasajeros);
            	banderaGuardadoTexto = 0;
            	banderaGuardadoBinario = 0;
			break;

            case 5:
            	if (!ll_isEmpty(listaPasajeros))
            	{
            		controller_editPassenger(listaPasajeros);
            		banderaGuardadoTexto = 0;
					banderaGuardadoBinario = 0;
            	}
            	else
            	{
            		printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
					system("pause");
            	}
			break;

            case 6:
            	if (!ll_isEmpty(listaPasajeros))
				{
            		controller_removePassenger(listaPasajeros);
            		banderaGuardadoTexto = 0;
					banderaGuardadoBinario = 0;
				}
				else
				{
					printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 7:
            	if (!ll_isEmpty(listaPasajeros))
				{
            		controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 8:
            	if (!ll_isEmpty(listaPasajeros))
				{
            		controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("||----< [ERROR] - NO HAY PASAJEROS CARGADOS. >----\n");
					system("pause");
				}
			break;

            case 9:
            	validacion = controller_saveAsText("data.csv", listaPasajeros);

            	if (validacion == 1)
				{
					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
					system("pause");
					banderaGuardadoTexto = 1;
				}
				else
				{
					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
					system("pause");
				}
			break;

            case 10:
            	validacion = controller_saveAsBinary("data.bin", listaPasajeros);

            	if (validacion == 1)
				{
					printf("||----< [DATOS GUARDADOS CORRECTAMENTES] >----\n");
					system("pause");
					banderaGuardadoBinario = 1;
				}
				else
				{
					printf("||----< [ERROR] - NO SE HAN PODIDO GUARDAR LOS DATOS >----\n");
					system("pause");
				}
			break;

            case 11:
            	cloneArray = ll_clone(listaPasajeros);

				if (!ll_containsAll(listaPasajeros, cloneArray))
				{
					validacion = controller_saveAsText("backup.csv", cloneArray);

					if (validacion == 1)
					{
						printf("||----< [COPIA DE SEGURIDAD REALIZADA] >----\n");
						system("pause");
					}
					else
					{
						printf("||----< [ERROR] - NO SE HA PODIDO REALIZAR LA COPIA DE SEGURIDAD>----\n");
						system("pause");
					}
				}
				else
				{
					printf("||----< [ERROR] - LA COPIA DE SEGURIDAD YA HA SIDO REALIZADA>----\n");
					system("pause");
				}

			break;

            case 12:
            	if (banderaGuardadoTexto == 1 && banderaGuardadoBinario == 1)
            	{
            		printf("|| - [SALIENDO] - ||");
            		ll_deleteLinkedList(listaPasajeros);
            	}
            	else
            	{
            		printf("||[ERROR] | DEBES GUARDAR LOS CAMBIOS ANTES DE SALIR.\n");
            		option = 1;
            		system("pause");
            	}
			break;
        }
    }while(option != 12);

    return 0;
}

