#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "Layer_Builder.h"


void ones_init(Matrix m) {
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = 1.0;
    }
}

void zeros_init(Matrix m) {
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = 0.0;
    }
}

void random_init(Matrix m) {
    srand(time(NULL));
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = (double)rand() / RAND_MAX;
    }
}

void uniform_init(Matrix m) {
    srand(time(NULL));
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = 2.0 * ((double)rand() / RAND_MAX) - 1.0;
    }
}

void xavier_init(Matrix m) {
    srand(time(NULL));
    double variance = 2.0 / (m.rows + m.cols);
    double stddev = sqrt(variance);
    for (int i = 0; i < m.rows * m.cols; i++) {
        m.data[i] = stddev * ((double)rand() / RAND_MAX);
    }
}

