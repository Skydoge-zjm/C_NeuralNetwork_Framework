#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

Matrix concat_horizontal(Matrix A, Matrix B) {
    if (A.rows != B.rows) {
        printf("Error: Matrices must have the same number of rows for horizontal concatenation.\n");
        exit(1);
    }

    Matrix result;
    result.rows = A.rows;
    result.cols = A.cols + B.cols;
    result.data = (double *)malloc(result.rows * result.cols * sizeof(double));

    for (int i = 0; i < result.rows; ++i) {
        // Copy A's data
        memcpy(result.data + i * result.cols, A.data + i * A.cols, A.cols * sizeof(double));
        // Copy B's data
        memcpy(result.data + i * result.cols + A.cols, B.data + i * B.cols, B.cols * sizeof(double));
    }

    return result;
}


Matrix concat_vertical(Matrix A, Matrix B) {
    if (A.cols != B.cols) {
        printf("Error: Matrices must have the same number of columns for vertical concatenation.\n");
        exit(1);
    }

    Matrix result;
    result.rows = A.rows + B.rows;
    result.cols = A.cols;
    result.data = (double *)malloc(result.rows * result.cols * sizeof(double));

    // Copy A's data
    memcpy(result.data, A.data, A.rows * A.cols * sizeof(double));
    // Copy B's data
    memcpy(result.data + A.rows * A.cols, B.data, B.rows * B.cols * sizeof(double));

    return result;
}

