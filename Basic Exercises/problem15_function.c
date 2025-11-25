#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int applyOperation(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

void sortArray(int *arr, int n, int (*compare)(int, int)) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int ascending(int a, int b) { return a > b; }
int descending(int a, int b) { return a < b; }

int main() {
    int a = 10, b = 5;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Addition: %d\n", applyOperation(a, b, add));
    printf("Subtraction: %d\n", applyOperation(a, b, subtract));
    printf("Multiplication: %d\n", applyOperation(a, b, multiply));
    printf("Division: %d\n", applyOperation(a, b, divide));
    
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    
    sortArray(arr, n, ascending);
    printf("\nAscending: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    
    sortArray(arr, n, descending);
    printf("\nDescending: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}