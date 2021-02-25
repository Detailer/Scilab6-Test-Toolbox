#include <stdio.h>

void transpose(double* origMatrix, int R, int C, double* transMatrix){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++)
            *((transMatrix + j * R) + i) = *((origMatrix + i * C) + j);
    }
}