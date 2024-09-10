
#ifndef C_LOGISTIC_REGRESSION_MATRIX_H
#define C_LOGISTIC_REGRESSION_MATRIX_H


// matrix base
typedef struct {
    int rows;
    int cols;
    double * data;
} Matrix;
Matrix create_matrix(int rows, int cols);
Matrix create_ones_matrix(int rows, int cols);
void free_matrix(Matrix m);
void print_matrix(Matrix m);
void print_matrix_shape(Matrix m);


//matrix multiplication
#define NUM_THREADS 64
struct v {
    int start;
    int end;
    int A_rows;
    int A_cols;
    int B_cols;
    double *A;
    double *B;
    double *C;
};
void *runner(void *param);
void multiply_thread(double *A, double *B, double *C, int A_rows, int A_cols, int B_cols);
Matrix matmul(Matrix A, Matrix B);


//matrix transpose
Matrix transpose(Matrix matrix);


//matrix linear calculation
Matrix add_scalar(Matrix A, double x);  // A + x
Matrix add_matrix(Matrix A, Matrix B);  // A + B
Matrix scalar_mul(Matrix A, double x);  // x * A
Matrix linear_matrix(Matrix A, Matrix B, double x1, double x2);  // x1 * A + x2 * B


Matrix concat_horizontal(Matrix A, Matrix B);
Matrix concat_vertical(Matrix A, Matrix B);


#endif //C_LOGISTIC_REGRESSION_MATRIX_H
