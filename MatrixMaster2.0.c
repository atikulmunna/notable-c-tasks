
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

void printMatrix(int r, int c, double M[r][c]) {
    printf("\n" CYAN "Resulting Matrix:\n\n" RESET);
    for (int i = 0; i < r; i++) {
        printf(YELLOW "+");
        for (int j = 0; j < c; j++) printf("-------");
        printf("+\n| " RESET);
        for (int j = 0; j < c; j++) printf("%5.2f | ", M[i][j]);
        printf("\n");
    }
    printf(YELLOW "+");
    for (int j = 0; j < c; j++) printf("-------");
    printf("+\n" RESET);
}

void transpose(int r, int c, double A[r][c], double T[c][r]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = A[i][j];
}

double determinant(double **A, int n) {
    if (n == 1) return A[0][0];
    if (n == 2) return A[0][0]*A[1][1] - A[0][1]*A[1][0];
    double det = 0;
    for (int p = 0; p < n; p++) {
        double **sub = malloc((n-1) * sizeof(double*));
        for (int i = 0; i < n-1; i++) sub[i] = malloc((n-1) * sizeof(double));
        for (int i = 1; i < n; i++) {
            int colIndex = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                sub[i-1][colIndex++] = A[i][j];
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * A[0][p] * determinant(sub, n-1);
        for (int i = 0; i < n-1; i++) free(sub[i]);
        free(sub);
    }
    return det;
}

void inverse(int n, double A[n][n]) {
    double aug[n][2*n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2*n; j++)
            aug[i][j] = (j < n) ? A[i][j] : (i == j-n);

    for (int i = 0; i < n; i++) {
        double pivot = aug[i][i];
        if (pivot == 0) {
            printf(RED "Matrix not invertible.\n" RESET);
            return;
        }
        for (int j = 0; j < 2*n; j++)
            aug[i][j] /= pivot;
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = aug[k][i];
            for (int j = 0; j < 2*n; j++)
                aug[k][j] -= factor * aug[i][j];
        }
    }

    double inv[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = aug[i][j+n];

    printMatrix(n, n, inv);
}

int main() {
    int op, r1, c1, r2, c2;

    printf(CYAN "\n==============================\n" RESET);
    printf(GREEN "   MatrixMaster Scientific 2.0\n" RESET);
    printf(CYAN "==============================\n\n" RESET);

    while (1) {
        printf(YELLOW "Menu:\n" RESET);
        printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Transpose\n");
        printf(" 5. Determinant\n 6. Inverse\n 7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &op);

        if (op == 7) {
            printf(GREEN "\nGoodbye!\n" RESET);
            break;
        }

        if (op < 1 || op > 7) {
            printf(RED "Invalid option.\n" RESET);
            continue;
        }

        if (op <= 3) {
            printf("Enter rows and columns of Matrix 1: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of Matrix 2: ");
            scanf("%d %d", &r2, &c2);

            if ((op == 1 || op == 2) && (r1 != r2 || c1 != c2)) {
                printf(RED "Dimension mismatch.\n" RESET);
                continue;
            }
            if (op == 3 && c1 != r2) {
                printf(RED "Invalid sizes for multiplication.\n" RESET);
                continue;
            }

            double A[r1][c1], B[r2][c2];
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    scanf("%lf", &A[i][j]);
            for (int i = 0; i < r2; i++)
                for (int j = 0; j < c2; j++)
                    scanf("%lf", &B[i][j]);

            if (op == 1 || op == 2) {
                double C[r1][c1];
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        C[i][j] = (op == 1) ? A[i][j] + B[i][j] : A[i][j] - B[i][j];
                printMatrix(r1, c1, C);
            } else {
                double C[r1][c2];
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c2; j++) {
                        C[i][j] = 0;
                        for (int k = 0; k < c1; k++)
                            C[i][j] += A[i][k] * B[k][j];
                    }
                printMatrix(r1, c2, C);
            }
        } 
        else if (op == 4) {
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);
            double A[r1][c1];
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    scanf("%lf", &A[i][j]);
            double T[c1][r1];
            transpose(r1, c1, A, T);
            printMatrix(c1, r1, T);
        }
        else if (op == 5) {
            printf("Enter matrix size n x n: ");
            scanf("%d", &r1);
            double **A = malloc(r1 * sizeof(double*));
            for (int i = 0; i < r1; i++)
                A[i] = malloc(r1 * sizeof(double));
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < r1; j++)
                    scanf("%lf", &A[i][j]);
            double det = determinant(A, r1);
            printf(GREEN "Determinant = %.2f\n" RESET);
            for (int i = 0; i < r1; i++) free(A[i]);
            free(A);
        }
        else if (op == 6) {
            printf("Enter size n x n: ");
            scanf("%d %d", &r1, &c1);
            if (r1 != c1) {
                printf(RED "Not a square matrix.\n" RESET);
                continue;
            }
            double A[r1][c1];
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    scanf("%lf", &A[i][j]);
            inverse(r1, A);
        }
    }
}
