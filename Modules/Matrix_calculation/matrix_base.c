# include <stdlib.h>
# include <stdio.h>

# include "matrix.h"

Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)malloc(rows * cols * sizeof(double));
    if (m.data == NULL) {
        fprintf(stderr, "Error: Fail to alloc memory.\n");
        exit(EXIT_FAILURE);
    }
    return m;
}

void free_matrix(Matrix m) {
    free(m.data);
}

void print_matrix(Matrix m) {
    for(int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            printf("%.6f  ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

void print_matrix_shape(Matrix m) {
    printf("shape=(%d, %d)\n", m.rows, m.cols);
}