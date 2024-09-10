#include <stdio.h>
#include <stdlib.h>

#include "Layer_Builder.h"

Layer init_linear_layer(int input_dim, int output_dim, InitializationType init_type) {
    Layer layer;
    layer.type = LINEAR;
    layer.input_dim = input_dim;
    layer.output_dim = output_dim;
    layer.init_type = init_type;

    // Create and Initialize
    layer.weights = create_matrix(input_dim + 1, output_dim);
    switch (init_type) {
        case ONES_INITIALIZATION:
            ones_init(layer.weights);
            break;
        case ZEROS_INITIALIZATION:
            zeros_init(layer.weights);
            break;
        case RANDOM_INITIALIZATION:
            random_init(layer.weights);
            break;
        case UNIFORM_INITIALIZATION:
            uniform_init(layer.weights);
            break;
        case XAVIER_INITIALIZATION:
            xavier_init(layer.weights);
            break;
        default:
            printf("No such initialization: %d.", init_type);
            printf(" Using ONES_INITIALIZATION instead.\n");
            ones_init(layer.weights);
    }

    return layer;
}
