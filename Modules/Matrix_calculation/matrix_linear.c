# include <stdio.h>
# include <stdlib.h>

# include "matrix.h"

Matrix add_scalar(Matrix A, double x) {
    Matrix out = create_matrix(A.rows, A.cols);
    if (out.data == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            out.data[i * A.cols + j] = A.data[i * A.cols + j] + x;
        }
    }
    return out;
}

Matrix add_matrix(Matrix A, Matrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Error: Wrong matrix shape when add.");
        exit(2);
    }
    Matrix out = create_matrix(A.rows, A.cols);
    if (out.data == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < A.rows; i++) {
        for(int j = 0; j < A.cols; j++) {
            out.data[i * A.cols + j] = A.data[i * A.cols + j] + B.data[i * B.cols + j];
        }
    }
    return out;
}

Matrix scalar_mul(Matrix A, double x) {
    Matrix out = create_matrix(A.rows, A.cols);
    if (out.data == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    for (int i = 0; i < A.rows; i++) {
        for(int j = 0; j < A.cols; j++) {
            out.data[i * A.cols + j] = A.data[i * A.cols + j] * x;
        }
    }
    return out;
}

Matrix linear_matrix(Matrix A, Matrix B, double x1, double x2) {
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Error: Wrong matrix shape when add.");
        exit(2);
    }
    Matrix out = create_matrix(A.rows, A.cols);
    if (out.data == NULL) {
        printf("Error: Fail to alloc memory.");
        exit(1);
    }
    int m = A.rows;
    int n = A.cols;
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            out.data[i * n + j] = x1 * A.data[i * n + j] + x2 * B.data[i * n + j];
        }
    }
    return out;
}
