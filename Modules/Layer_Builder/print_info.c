#include <stdio.h>

#include "Layer_Builder.h"

void print_layer_type(Layer layer) {
    switch (layer.type) {
        case LINEAR:
            printf("LINEAR (Fully connected)\n");
            break;
        case SIGMOID:
            printf("SIGMOID\n");
            break;
        case RELU:
            printf("RELU\n");
            break;
        default:
            printf("Unknown layer type: %d\n", layer.type);
            break;
    }
}

void print_layer_size(Layer layer) {
    printf("Input dimension: %d\n", layer.input_dim);
    printf("Output dimension: %d\n", layer.output_dim);
}


void print_layer_weights(Layer layer){
    printf("Layer: %d\nParameters:\n", layer.index+1);
    print_matrix(layer.weights);
    printf("\n");
}