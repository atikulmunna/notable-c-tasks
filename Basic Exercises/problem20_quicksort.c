#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = *(arr + high);
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (*(arr + j) <= pivot) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int* readArray(int *size) {
    printf("Enter array size: ");
    scanf("%d", size);
    
    int *arr = (int *)malloc((*size) * sizeof(int));
    
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", arr + i);
    }
    
    return arr;
}

int main() {
    int size;
    int *arr = readArray(&size);
    
    printf("\nOriginal array: ");
    printArray(arr, size);
    
    quickSort(arr, 0, size - 1);
    
    printf("Sorted array: ");
    printArray(arr, size);
    
    free(arr);
    return 0;
}