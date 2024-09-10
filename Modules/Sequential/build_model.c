#include <stdio.h>
#include <stdlib.h>

#include "Sequential.h"

Model model_create(char *model_name) {
    Model model;
    model.model_name = model_name;
    model.num_layers = 0;
    model.layers = NULL;
    return model;
}

void add_layer(Model *model, Layer layer) {
    Layer *new_layers = realloc(model->layers, (model->num_layers + 1) * sizeof(Layer));

    if (new_layers == NULL) {
        fprintf(stderr, "Memory allocation failed while adding a new layer.\n");
        exit(EXIT_FAILURE);
    }

    model->layers = new_layers;
    model->layers[model->num_layers] = layer;
    model->layers[model->num_layers].index = model->num_layers;
    model->num_layers += 1;
}

void print_model_info(Model model) {
    printf("--------------MODEL INFORMATION--------------\n");
    printf("Model: %s\n", model.model_name);
    printf("Number of Layers: %d\n\n", model.num_layers);
    printf("Layers:\n\n");
    for(int i = 0; i < model.num_layers; i++) {
        printf("Layer %d: ", i+1);
        print_layer_type(model.layers[i]);
        print_layer_size(model.layers[i]);
        printf("\n");
    }
}