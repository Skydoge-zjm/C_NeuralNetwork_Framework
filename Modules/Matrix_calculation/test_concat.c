#include <stdio.h>

#include "matrix.h"

int main_3()
{
    Matrix A = create_matrix(4, 6);
    Matrix B = create_matrix(4, 1);
    Matrix C = create_matrix(1, 6);

    Matrix a = concat_horizontal(A, B);
    print_matrix_shape(a);
    print_matrix(a);

    Matrix b = concat_vertical(A, C);
    print_matrix_shape(b);
    print_matrix(b);
}