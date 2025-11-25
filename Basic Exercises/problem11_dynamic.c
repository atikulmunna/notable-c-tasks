#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n, i, newSize;
    
    printf("Enter initial size: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Current array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter new size: ");
    scanf("%d", &newSize);
    
    arr = (int *)realloc(arr, newSize * sizeof(int));
    
    if (newSize > n) {
        printf("Enter %d more elements:\n", newSize - n);
        for (i = n; i < newSize; i++) {
            scanf("%d", &arr[i]);
        }
    }
    
    printf("New array: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}