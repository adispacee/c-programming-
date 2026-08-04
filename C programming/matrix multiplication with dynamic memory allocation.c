#include <stdio.h>
#include <stdlib.h>

// Function to allocate matrix
int** allocateMatrix(int rows, int cols) {
    int **mat = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        *(mat + i) = (int*) malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to read matrix
void readMatrix(int **mat, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

// Function to display matrix
void displayMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

// Function to multiply matrices
int** multiplyMatrix(int **A, int **B, int r1, int c1, int c2) {
    int **C = allocateMatrix(r1, c2);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(C + i) + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(*(C + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
        }
    }
    return C;
}

// Function to free memory
void freeMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; i++) {
        free(*(mat + i));
    }
    free(mat);
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int **A = allocateMatrix(r1, c1);
    int **B = allocateMatrix(r2, c2);

    printf("Matrix A:\n");
    readMatrix(A, r1, c1);

    printf("Matrix B:\n");
    readMatrix(B, r2, c2);

    printf("Matrix A:\n");
    displayMatrix(A, r1, c1);

    printf("Matrix B:\n");
    displayMatrix(B, r2, c2);

    int **C = multiplyMatrix(A, B, r1, c1, c2);

    printf("Product Matrix:\n");
    displayMatrix(C, r1, c2);

    // Free memory
    freeMatrix(A, r1);
    freeMatrix(B, r2);
    freeMatrix(C, r1);

    return 0;
}
