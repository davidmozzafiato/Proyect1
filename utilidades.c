//
//  utilidades.c
//  Proyecto 1
//
//  Created by David Pinto Santillán on 15/03/23.
//

#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[],int size){
    int i;
    for (i=0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void printSubArray(int arr[],int low, int high){
    int i;
    printf("Sub array :  ");
    for (i=low; i <= high; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void randArr(int arr[]){
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % MAXVALSIZE;
}

char dirOrdenamiento(char type){
    printf("\nOrdenamiento de"
        "\n mayor a menor (>)"
        "\n menor a mayor (<)"
        "\n Opcion: ");
        scanf(" %c", &type);
    return type;
}

bool llenado(int arr[], int LOW, int HIGH){
    int j, valor, optMarr = 1;
    bool cont;
    /*
    printf("\n Seleccione una opcion:"
    "\n 1. Llenar el arreglo de manera aleatoria"
    "\n 2. Llenar el arreglo de manera manual"
    "\n 3. Salir"
    "\n Opcion: ");
    scanf("%d", &optMarr);
    */
    switch (optMarr)
    {
    case 1:
        randArr(arr);
        cont = true;
        break;
    case 2:
        for (j = 0; j < SIZE; j++){
            printf("Ingresa el valor de la posicion (%i): ", j);
            scanf("%d", &valor);
            arr[j] = valor;
        }
        cont = true;
        break;
    case 3:
        cont = false;
        break;
    default:
        printf("Opcion invalida, saliendo...");
        cont = false;
        break;
    }
    return cont;
}
