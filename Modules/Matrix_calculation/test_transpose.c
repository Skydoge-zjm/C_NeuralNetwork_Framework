# include <stdio.h>

#include "matrix.h"

int main_1()
{
    Matrix A = create_matrix(4, 3);
    double a = 0.0;
    for (int i=0; i<4*3; i++){
        A.data[i] = a;
        a += 0.1;
    }
    print_matrix(A);
    print_matrix_shape(A);
    printf("\n");
    print_matrix(scalar_mul(A,2));

    Matrix AT = transpose(A);
    print_matrix(AT);
    print_matrix_shape(AT);
    free_matrix(A);
    return 0;
}