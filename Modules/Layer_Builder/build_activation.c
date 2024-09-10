#include <stdio.h>
#include <stdlib.h>

#include "Layer_Builder.h"

Layer init_ReLU_layer(int input_dim) {
    Layer layer;
    layer.type = RELU;
    layer.input_dim = input_dim;
    layer.output_dim = input_dim;
    return layer;
}

Layer init_Sigmoid_layer(int input_dim) {
    Layer layer;
    layer.type = SIGMOID;
    layer.input_dim = input_dim;
    layer.output_dim = input_dim;
    return layer;
}
