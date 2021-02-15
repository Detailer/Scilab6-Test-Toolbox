#include <stdio.h>

void transpose(){
    int R, C;
    printf("Enter No. of Rows & Columns:\n");
    scanf("%d %d", &R, &C);
    
    int origMatrix[R][C], transMatrix[C][R];
    printf("Enter Matrix:\n");
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            scanf("%d", &origMatrix[i][j]);
    }

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            transMatrix[j][i] = origMatrix[i][j];
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < C; i++){
        for (int j = 0; j < R; j++)
            printf("%d ", transMatrix[i][j]);
        printf("\n");
    }
}