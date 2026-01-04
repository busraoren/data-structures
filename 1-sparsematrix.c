#include <stdio.h>

#define MAX 100

// Function to convert a standard matrix to a sparse matrix (Triplet representation)
void convertToSparse(int matrix[3][3], int row, int col) {
    int sparseMatrix[MAX][3];
    int k = 1; // Start from 1, index 0 is reserved for metadata

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // If element is non-zero, store it in sparse matrix
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    sparseMatrix[0][0] = row;
    sparseMatrix[0][1] = col;
    sparseMatrix[0][2] = k - 1;

    printf("\nSparse Matrix Representation (Row, Column, Value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

int main() {
    // Example 3x3 matrix with many zeros
    int normalMatrix[3][3] = {
        {0, 0, 5},
        {0, 8, 0},
        {2, 0, 0}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", normalMatrix[i][j]);
        }
        printf("\n");
    }

    convertToSparse(normalMatrix, 3, 3);

    return 0;
}