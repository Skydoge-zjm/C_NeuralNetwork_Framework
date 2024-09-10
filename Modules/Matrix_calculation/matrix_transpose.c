#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"


Matrix transpose(Matrix matrix) {
    Matrix transposed = create_matrix(matrix.rows, matrix.cols);;
    transposed.rows = matrix.cols;
    transposed.cols = matrix.rows;
    transposed.data = (double *) malloc(transposed.rows * transposed.cols * sizeof(double));
    if (transposed.data == NULL) {
        fprintf(stderr, "Error: Fail to alloc memory for transposed matrix.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            transposed.data[j * matrix.rows + i] = matrix.data[i * matrix.cols + j];
        }
    }

    return transposed;
}