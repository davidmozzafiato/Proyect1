//
//  ordenamientos.h
//  Proyecto 1
//
//  Created by David Pinto Santillán on 15/03/23.
//

#ifndef ordenamientos_h
#define ordenamientos_h

#include <stdio.h>
// Proyecto 1
/*
* La codificación de las funciones en C 'merge' y 'sort' fueron importadas del proyecto Intercalacion proporcionado
* por el profesor en el lenguaje Java en la Práctica 3.
*/
void merge(int arr[], int l, int m, int r, int* comparaciones, int* intercambios, int* inserciones);
void sort(int arr[], int l, int r, int* comparaciones, int* intercambios, int* inserciones);

//Practica 02
void HeapSort(int* A, int size, char type);
void Heapify(int* A, int i, int size, char type, int* comparaciones, int* intercambios);
void BuildHeap(int* A, int size, char type);
void quickSort(int arr[], int low, int high, char type, int* comparaciones, int* intercambios, int* inserciones);
int partition (int arr[], int low, int high, char type, int* comparaciones, int* intercambios);

//Practica 01
void selectionSort(int arreglo[], int n, char type);
void insertionSort(int a[], int n, char type);
void bubbleSort(int a[], int n, char type);

#endif /* ordenamientos_h */
