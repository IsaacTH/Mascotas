#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char Mascota[5][10];
    int Servicio[3][20] = {0};
    int opcion1, opcion2;

    do {
        printf("1. Ingresar datos de mascota\n");
        printf("2. Servicios\n");
        printf("3. Facturar servicio\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion1);

        switch (opcion1) {
            case 1:
                datosMascota(Mascota);
                break;

            case 2:
                servicios(Servicio);
                break;

            case 3:
                printf("Escriba 1 para facturar con el ID de su mascota\n");
                printf("Escriba 2 para facturar con el ID del servicio\n");
                scanf("%d", &opcion2);

                switch (opcion2) {
                    case 1:
                        mascotaFactura(Servicio, Mascota);
                        break;

                    case 2:
                        servicioFactura(Servicio, Mascota);
                        break;

                    default:
                        printf("Error. Fuera de rango\n");
                        break;
                }
                break;

            case 4:
                printf("Gracias por preferirnos!\n");
                return 0;
                break;

            default:
                printf("Error. Fuera de rango\n");
                break;
        }
    } while (opcion1 != 4);
}