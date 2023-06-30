#include <stdio.h>
#include <string.h>
#include "funciones.h"

void datosMascota(char (*Mascota)[10]) {
    printf("Ingrese el ID de su mascota: ");
    scanf("%s", *(Mascota + 0));

    printf("Ingrese el nombre de su mascota: ");
    scanf("%s", *(Mascota + 1));

    printf("Ingrese el tipo de su mascota: ");
    scanf("%s", *(Mascota + 2));

    printf("Ingrese la edad de su mascota: ");
    scanf("%s", *(Mascota + 3));

    printf("Ingrese su nombre: ");
    scanf("%s", *(Mascota + 4));
}

void servicios(int (*Servicio)[20]) {
    int opcion3, contador = 0;
    char respuesta;

    servicios:
    printf("Elija los servicios que desea para su mascota:\n");
    printf("1. ID: 1111 Peluqueada $10 (servicio de corte de pelo con limpieza)\n");
    printf("2. ID: 2222 Desparasitacion $40 (servicio que garantiza la salud gastrointestinal)\n");
    printf("3. ID: 3333 Adiestramiento $90 (servicio que incluye 4 semanas de entrenamiento)\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion3);

    int *pServicio = *Servicio;
    int *pPrecio = *(Servicio + 1);

    switch (opcion3) {
        case 1:
            *pPrecio = 10;
            contador += *pPrecio;
            printf("Si desea agregar otro servicio escriba s, caso contrario escriba n: ");
            scanf(" %c", &respuesta);
            if (respuesta == 'S' || respuesta == 's') {
                goto servicios;
            }
            break;

        case 2:
            *pPrecio = 40;
            contador += *pPrecio;
            printf("Si desea agregar otro servicio escriba s, caso contrario escriba n: ");
            scanf(" %c", &respuesta);
            if (respuesta == 'S' || respuesta == 's') {
                goto servicios;
            }
            break;

        case 3:
            *pPrecio = 90;
            contador += *pPrecio;
            printf("Si desea agregar otro servicio escriba s, caso contrario escriba n: ");
            scanf(" %c", &respuesta);
            if (respuesta == 'S' || respuesta == 's') {
                goto servicios;
            }
            break;

        default:
            printf("Error. Fuera de rango\n");
            return;
    }

    for (int i = 0; i < 20; i++) {
        if (*pServicio == 0) {
            *pServicio = opcion3;
            pPrecio++;
            pServicio++;
            *pPrecio = contador;
            break;
        }
        pServicio++;
        pPrecio++;
    }
}

void mascotaFactura(int (*Servicio)[20], char (*Mascota)[10]) {
    char idMascota[10];
    int i, j;
    int encontrado = 0;

    printf("Ingrese el ID de la mascota para generar la factura: ");
    scanf("%s", idMascota);

    for (i = 0; i < 5; i++) {
        if (strcmp(*(Mascota + i), idMascota) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("\n***** FACTURA *****\n");
        printf("ID de la mascota: %s\n", *(Mascota + i + 0));
        printf("Nombre de la mascota: %s\n", *(Mascota + i + 1));
        printf("Tipo de mascota: %s\n", *(Mascota + i + 2));
        printf("Edad de la mascota: %s\n", *(Mascota + i + 3));
        printf("Nombre del propietario: %s\n", *(Mascota + i + 4));
        printf("\nServicios contratados:\n");

        for (j = 0; j < 20; j++) {
            if (*(*(Servicio + 0) + j) != 0) {
                int servicioID = *(*(Servicio + 0) + j);
                int servicioPrecio = *(*(Servicio + 1) + j);

                printf("Numero de servicio : %d\n", servicioID);
                if (servicioID == 1)
                {
                    printf("Peluqueada \t$%d\n", servicioPrecio);
                } else if (servicioID == 2){
                    printf("Desparasitacion \t$%d\n", servicioPrecio);
                } else if (servicioID == 3){
                    printf("Adiestramiento \t$%d\n", servicioPrecio);
                }
                    
            }
        }
    }
}

void servicioFactura(int (*Servicio)[20], char (*Mascota)[10]) {
    int idServicio;
    int i, j;
    int encontrado = 0;

    printf("Ingrese el numero del servicio para generar la factura: ");
    scanf("%d", &idServicio);

    for (j = 0; j < 20; j++) {
        if (*(*(Servicio + 0) + j) == idServicio) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado){
        printf("\n***** FACTURA *****\n");
        printf("ID del servicio: %d\n", *(*(Servicio + 0) + j));
        printf("Precio del servicio: $%d\n", *(*(Servicio + 1) + j));

        char idMascota[10];
        int encontradoMascota = 0;

        printf("\nIngrese el ID de la mascota para vincular con el servicio: ");
        scanf("%s", idMascota);

        for (i = 0; i < 5; i++) {
            if (strcmp(*(Mascota + i), idMascota) == 0) {
                encontradoMascota = 1;
                break;
            }
        }

        if (encontradoMascota) {
            printf("\nDatos de la mascota:\n");
            printf("ID de la mascota: %s\n", *(Mascota + i + 0));
            printf("Nombre de la mascota: %s\n", *(Mascota + i + 1));
            printf("Tipo de mascota: %s\n", *(Mascota + i + 2));
            printf("Edad de la mascota: %s\n", *(Mascota + i + 3));
            printf("Nombre del propietario: %s\n", *(Mascota + i + 4));
        }
    }
}