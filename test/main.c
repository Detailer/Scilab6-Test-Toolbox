#include <stdio.h>
#include <stdlib.h>
#include "trans.h"

int main(){
    // Get Input Matrix
    int R, C;
    printf("Input Rows: ");
    scanf ("%d", &R);

    printf("Input Columns: ");
    scanf ("%d", &C);
    
    double inputMatrix[R][C];
    double* outputMatrix = malloc(C * R * sizeof(double));

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf("%lf", &inputMatrix[i][j]);
        }
    }

    printf("Input Matrix: \n");
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%lf ", inputMatrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the input Matrix
    transpose((double *)inputMatrix, R, C, outputMatrix);

    // Print Transposed Matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < C; i++){
        for (int j = 0; j < R; j++)
            printf("%lf ", *((outputMatrix + i * R) + j));
        printf("\n");
    }
}