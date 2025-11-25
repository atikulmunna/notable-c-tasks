#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    struct Element *elements;
};

struct SparseMatrix* createSparseMatrix(int **matrix, int rows, int cols) {
    int i, j, count = 0;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    
    struct SparseMatrix *sparse = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    sparse->rows = rows;
    sparse->cols = cols;
    sparse->numElements = count;
    sparse->elements = (struct Element*)malloc(count * sizeof(struct Element));
    
    int k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse->elements[k].row = i;
                sparse->elements[k].col = j;
                sparse->elements[k].value = matrix[i][j];
                k++;
            }
        }
    }
    
    return sparse;
}

void displaySparse(struct SparseMatrix *sparse) {
    printf("\nSparse Matrix (Row, Col, Value):\n");
    for (int i = 0; i < sparse->numElements; i++) {
        printf("(%d, %d, %d)\n", 
               sparse->elements[i].row, 
               sparse->elements[i].col, 
               sparse->elements[i].value);
    }
}

int main() {
    int rows, cols, i, j;
    int **matrix;
    
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    struct SparseMatrix *sparse = createSparseMatrix(matrix, rows, cols);
    displaySparse(sparse);
    
    printf("\nSpace saved: %d%%\n", 
           (int)(100.0 * (1.0 - (float)sparse->numElements / (rows * cols))));
    
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(sparse->elements);
    free(sparse);
    
    return 0;
}