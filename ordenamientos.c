//
//  ordenamientos.c
//  Proyecto 1
//
//  Created by David Pinto Santillán on 15/03/23.
//

#include "ordenamientos.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdbool.h>

int intercambios = 0, comparaciones = 0, inserciones = 0, iteraciones = 0;

void quickSort(int arr[], int low, int high, char type, int* comparaciones, int* intercambios, int* inserciones){
    if (low < high){
        int pi = partition(arr, low, high, type, comparaciones, intercambios);
        //printSubArray(arr,low,pi-1);
        quickSort(arr, low, pi - 1, type, comparaciones, intercambios, inserciones);
        //printSubArray(arr,pi+1,high);
        quickSort(arr, pi + 1, high, type, comparaciones, intercambios, inserciones);
        (*inserciones)++;
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", *comparaciones);
    printf("\nNúmero de intercambios: %d", *intercambios);
    printf("\nNúmero de inserciones: %d", *inserciones);
    printf("\n--------------------------------");
}

int partition(int arr[], int low, int high, char type, int* comparaciones, int* intercambios){
    int pivot = arr[high];
    //printf("Pivote: %d   \n ",pivot);
    int j,i = (low - 1);
    for (j = low; j <= high- 1; j++)
    {
        (*comparaciones)++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            (*intercambios)++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*intercambios)++;
    return (i + 1);
}

int heapSize;
void HeapSort(int* A, int size, char type){
    BuildHeap(A,size, type);
    int i;
    for(i = size - 1; i > 0; i--){
        swap(&A[0],&A[heapSize]);
        heapSize--;
        //printf("Iteracion HS: \n");
        //printArray(A,size);
        intercambios++;
        Heapify(A, 0,size, type, &comparaciones, &intercambios);
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", comparaciones);
    printf("\nNúmero de intercambios: %d", intercambios);
    printf("\nNúmero de inserciones: %d", inserciones);
    printf("\n--------------------------------");
}

void Heapify(int* A, int i, int size, char type, int* comparaciones, int* intercambios){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = 0;
    (*comparaciones)++;
    if(l <= heapSize && A[l] < A[i]){
        largest = l;
    }
    else
        largest = i;
    (*comparaciones)++;
    if(r <= heapSize && A[r] < A[largest]){
        largest = r;
    }
    if(largest != i){
        (*intercambios)++;
        swap(&A[i],&A[largest]);
        //printArray(A, size);
        Heapify(A, largest, size, type, comparaciones, intercambios);
    }
}

void BuildHeap(int* A, int size, char type){
    heapSize = size - 1;
    int i;
    for(i = (size - 1) / 2; i >= 0; i--){
        Heapify(A, i, size, type, &comparaciones, &intercambios);
    }
    printf("Termina de construir el HEAP \n");
}

void insertionSort(int a[], int n, char type){
    int i,j;
    int aux;
    for(i=1; i<n; i++){
        j=i;
        aux=a[i];
        inserciones++;
        while (j>0 && aux < a[j-1]){
            a[j] = a[j-1];
            comparaciones++;
            intercambios++;
            j--;
        }
        a[j]=aux;
        intercambios++;
        //printf("\nIteracion numero %d \n",i);
        //printArray(a,n);
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", comparaciones);
    printf("\nNúmero de intercambios: %d", intercambios);
    printf("\nNúmero de inserciones: %d", inserciones);
}

void selectionSort(int arreglo[], int n, char type){
    int indiceMenor, i, j;
    for (i=0; i<n-1; i++){
        indiceMenor=i;
        for(j = i+1; j<n; j++){
            comparaciones++;
            if(arreglo[j]<arreglo[indiceMenor])
                indiceMenor=j;
        }
        if (i!=indiceMenor){
            swap(&arreglo[i],&arreglo[indiceMenor]);
            intercambios++;
        }
        //printf("\nIteracion numero %d \n",i+1);
        //printArray(arreglo,n);
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", comparaciones);
    printf("\nNúmero de intercambios: %d", intercambios);
    printf("\nNúmero de inserciones: %d", inserciones);
    printf("\nNúmero de iteraciones: %d", iteraciones);
}

void bubbleSort(int a[], int n, char type)
{
    int i, j;
    bool ordenado;
    for(i = 0; i < n - 1; i++)
    {
        ordenado = false;
        for(j = 0; j < n - i - 1; j++)
        {
            comparaciones++;
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
                intercambios++;
                ordenado = true;
            }
        }
        if (ordenado == false)
        break;
        iteraciones++;
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", comparaciones);
    printf("\nNúmero de intercambios: %d", intercambios);
    printf("\nNúmero de inserciones: %d", inserciones);
    printf("\nNúmero de iteraciones: %d", iteraciones);
}

void sort(int arr[], int l, int r, int* comparaciones, int* intercambios, int* inserciones) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sort(arr, l, m, comparaciones, intercambios, inserciones);
        sort(arr, m + 1, r, comparaciones, intercambios, inserciones);

        merge(arr, l, m, r, comparaciones, intercambios, inserciones);
    }
    printf("\n--------------------------------");
    printf("\nNúmero de comparaciones: %d", *comparaciones);
    printf("\nNúmero de intercambios: %d", *intercambios);
    printf("\nNúmero de inserciones: %d", *inserciones);
    printf("\n--------------------------------");
}

void merge(int arr[], int l, int m, int r, int* comparaciones, int* intercambios, int* inserciones) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i=0; i<n1; ++i)
        L[i] = arr[l + i];
        (*inserciones)++;
    for (int j=0; j<n2; ++j)
        R[j] = arr[m + 1+ j];
        (*inserciones)++;

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2)
    {
        (*comparaciones)++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        (*intercambios)++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*intercambios)++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*intercambios)++;
    }
}