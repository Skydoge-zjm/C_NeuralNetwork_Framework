#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Optimizer.h"

// Initialize Basic_Gradient_Decent Optimizer
Optimizer init_BasicGD_optimizer(double learning_rate) {
    Optimizer optimizer;
    optimizer.type = OPTIMIZER_BASIC_GRADIENT_DECENT;
    optimizer.learning_rate = learning_rate;
    optimizer.m = NULL;
    optimizer.v = NULL;
    optimizer.t = 0;
    return optimizer;
}

/*
void update_weights(Layer *layer, Matrix grad_weights, Matrix grad_biases, Optimizer *optimizer) {
    if (optimizer->type == OPTIMIZER_SGD) {
        // SGD 更新
        for (int i = 0; i < layer->weights.rows; i++) {
            for (int j = 0; j < layer->weights.cols; j++) {
                layer->weights.data[i][j] -= optimizer->learning_rate * grad_weights.data[i][j];
            }
        }
        for (int j = 0; j < layer->biases.cols; j++) {
            layer->biases.data[0][j] -= optimizer->learning_rate * grad_biases.data[0][j];
        }
    } else if (optimizer->type == OPTIMIZER_ADAM) {
        // Adam 更新 (这里只是示例，实际使用时需要考虑更多细节)
        optimizer->t += 1;
        double lr_t = optimizer->learning_rate * sqrt(1.0 - pow(optimizer->beta2, optimizer->t)) / (1.0 - pow(optimizer->beta1, optimizer->t));

        if (optimizer->m == NULL) {
            optimizer->m = malloc(sizeof(Matrix));
            *optimizer->m = init_matrix(layer->weights.rows, layer->weights.cols);
        }
        if (optimizer->v == NULL) {
            optimizer->v = malloc(sizeof(Matrix));
            *optimizer->v = init_matrix(layer->weights.rows, layer->weights.cols);
        }

        // 更新 m 和 v
        for (int i = 0; i < layer->weights.rows; i++) {
            for (int j = 0; j < layer->weights.cols; j++) {
                optimizer->m->data[i][j] = optimizer->beta1 * optimizer->m->data[i][j] + (1.0 - optimizer->beta1) * grad_weights.data[i][j];
                optimizer->v->data[i][j] = optimizer->beta2 * optimizer->v->data[i][j] + (1.0 - optimizer->beta2) * grad_weights.data[i][j] * grad_weights.data[i][j];

                layer->weights.data[i][j] -= lr_t * optimizer->m->data[i][j] / (sqrt(optimizer->v->data[i][j]) + optimizer->epsilon);
            }
        }
    }
}

*/