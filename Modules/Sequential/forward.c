#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Sequential.h"

Matrix forward(Model model, Matrix x) {
    for(int i = 0; i < model.num_layers; i++) {
        if(model.layers[i].type == LINEAR) {
            x = linear_forward(x, model.layers[i].weights);
        }
    }
    return x;

}

Matrix linear_forward(Matrix x, Matrix w) {
    Matrix bias = create_ones_matrix(x.rows, 1);
    x = concat_horizontal(bias, x);
    x = matmul(x, w);
    return x;
}