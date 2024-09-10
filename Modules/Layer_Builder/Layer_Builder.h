#ifndef C_COMPUTATIONAL_GRAPH_LAYER_BUILDER_H
#define C_COMPUTATIONAL_GRAPH_LAYER_BUILDER_H

#include "../Matrix_calculation/matrix.h"

typedef enum {
    LINEAR,   // Fully connected
    SIGMOID,  // Sigmoid
    RELU,     // ReLU
} LayerType;

typedef enum {
    ONES_INITIALIZATION,
    ZEROS_INITIALIZATION,
    RANDOM_INITIALIZATION,
    UNIFORM_INITIALIZATION,
    XAVIER_INITIALIZATION,
} InitializationType;

typedef struct {
    int index;           // Layer index
    LayerType type;      // Layer type
    char is_activation;   // Activation(1) or not(0)
    int input_dim;       // Input dimension
    int output_dim;      // Output dimension
    Matrix weights;     // weight matrix
    InitializationType init_type;  // Method of initialization
} Layer;

void print_layer_type(Layer layer);
void print_layer_size(Layer layer);
void print_layer_weights(Layer layer);

Layer init_linear_layer(int input_dim, int output_dim, InitializationType init_type);

void ones_init(Matrix m);
void zeros_init(Matrix m);
void random_init(Matrix m);
void uniform_init(Matrix m);
void xavier_init(Matrix m);

#endif //C_COMPUTATIONAL_GRAPH_LAYER_BUILDER_H
