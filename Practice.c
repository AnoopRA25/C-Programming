#include <stdio.h>

void transposeMatrix(int matrix[3][4]) {
    int transpose[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    displayMatrix(transpose);
}

void displayMatrix(int matrix[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[3][4] = {{1, 2, 3,10}, {4, 5, 6,11}, {7, 8, 9,12}};

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    printf("\nTransposed Matrix:\n");
    transposeMatrix(matrix);

    return 0;
}
