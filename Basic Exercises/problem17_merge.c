#include <stdio.h>
#include <stdlib.h>

int* mergeArrays(int *arr1, int n1, int *arr2, int n2, int *resultSize) {
    *resultSize = n1 + n2;
    int *result = (int *)malloc((*resultSize) * sizeof(int));
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2) {
        if (*(arr1 + i) <= *(arr2 + j)) {
            *(result + k) = *(arr1 + i);
            i++;
        } else {
            *(result + k) = *(arr2 + j);
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        *(result + k) = *(arr1 + i);
        i++;
        k++;
    }
    
    while (j < n2) {
        *(result + k) = *(arr2 + j);
        j++;
        k++;
    }
    
    return result;
}

int main() {
    int n1, n2, i, resultSize;
    int *arr1, *arr2, *merged;
    
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    arr1 = (int *)malloc(n1 * sizeof(int));
    
    printf("Enter %d sorted elements:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", arr1 + i);
    }
    
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    arr2 = (int *)malloc(n2 * sizeof(int));
    
    printf("Enter %d sorted elements:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", arr2 + i);
    }
    
    merged = mergeArrays(arr1, n1, arr2, n2, &resultSize);
    
    printf("Merged array: ");
    for (i = 0; i < resultSize; i++) {
        printf("%d ", *(merged + i));
    }
    printf("\n");
    
    free(arr1);
    free(arr2);
    free(merged);
    
    return 0;
}