#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "matrix.h"

int main_2()
{
    int m = 3000;
    int n = 400;
    int p = 2000;
    Matrix A = create_matrix(m, n);
    Matrix B = create_matrix(n, p);


    srand(time(NULL));
    for (int i = 0; i < A.rows * A.cols; i++) {
        A.data[i] = (double)rand() / RAND_MAX * 10;  // 随机数在0到10之间
    }
    for (int i = 0; i < B.rows * B.cols; i++) {
        B.data[i] = (double)rand() / RAND_MAX * 10;  // 随机数在0到10之间
    }

    struct timespec t_start, t_end;
    double elapsedTime;

    clock_gettime(CLOCK_REALTIME, &t_start);
    Matrix C = matmul(A, B);
    clock_gettime(CLOCK_REALTIME, &t_end);

    elapsedTime = (t_end.tv_sec - t_start.tv_sec) * 1000.0;
    elapsedTime += (t_end.tv_nsec - t_start.tv_nsec) / 1000000.0;
    printf("Thread elapsedTime: %lf ms\n", elapsedTime);


    //print_matrix(C);
    printf("finished.");

    return 0;
}