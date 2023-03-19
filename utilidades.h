//
//  utilidades.h
//  Proyecto 1
//
//  Created by David Pinto Santillán on 15/03/23.
//

#ifndef utilidades_h
#define utilidades_h

#include <stdio.h>
#include <stdbool.h>
#define SIZE 5
#define MAXVALSIZE 9999

void swap(int* a, int* b);
void printArray(int arr[],int size);
void printSubArray(int arr[],int low, int high);
bool llenado(int arr[], int LOW, int HIGH);
char dirOrdenamiento(char type);
void randArr(int arr[]);

#endif /* utilidades_h */
