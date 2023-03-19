//
//  main.c
//  Proyecto 1
//
//  Created by David Pinto Santillán on 15/03/23.
//

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "utilidades.h"
#include "ordenamientos.h"

void menu(int arr[], int LOW, int HIGH){
    int optMord, primero = 0;
    char type = '<';
    double time_spent = 0.0;
    int intercambios = 0, comparaciones = 0, inserciones = 0;
    // para almacenar el tiempo de ejecución del código
    //do{
    printf("\nMENU DE ORDENAMIENTOS"
    "\n Seleccione una opcion:"
    "\n 1. InsertionSort"
    "\n 2. SelectionSort"
    "\n 3. BubbleSort"
    "\n 4. QuickSort"
    "\n 5. HeapSort"
    "\n 6. MergeSort"
    "\n 7. Salir"
    "\n Opcion: ");
    //scanf("%d", &optMord);
    optMord = 6;
    clock_t begin = clock();
    switch (optMord)
    {
    case 1:
        printf("\nSeleccionaste InsertionSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        insertionSort(arr, SIZE, type);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        
        break;
    case 2:
        printf("\nSeleccionaste SelectionSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        selectionSort(arr, SIZE, type);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        break;
    case 3:
        printf("\nSeleccionaste BubbleSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        bubbleSort(arr, SIZE, type);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        break;
    case 4:
        printf("\nSeleccionaste QuickSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        quickSort(arr, LOW, HIGH, type, &comparaciones, &intercambios, &inserciones);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        break;
    case 5:
        printf("\nSeleccionaste HeapSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        HeapSort(arr, SIZE, type);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        break;
    case 6:
        printf("\nSeleccionaste MergeSort\n");
        printf("\nArreglo inicial \n");
        //printArray(arr, SIZE);
        sort(arr, primero, SIZE-1, &comparaciones, &intercambios, &inserciones);
        printf("\nArreglo ordenado \n");
        //printArray(arr, SIZE);
        break;
    case 7:
        break;
    default:
        printf("Opcion invalida, intenta de nuevo");
        break;
    }
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n%f segundos\n", time_spent);
    //}while(optMord != 7);
}

int main(){
    int arr[SIZE], LOW = 0;
    int HIGH = (sizeof(arr) / sizeof(arr[0]) -1);
    bool cont = false;
    printf("\nBienvenido");
    cont = llenado(arr, LOW, HIGH);
    if (cont == true)
        menu(arr, LOW, HIGH);
    printf("\nHasta luego, vuelva pronto \n");
}
