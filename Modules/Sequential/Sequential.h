#ifndef C_COMPUTATIONAL_GRAPH_SEQUENTIAL_H
#define C_COMPUTATIONAL_GRAPH_SEQUENTIAL_H

#include "../Layer_Builder/Layer_Builder.h"
#include "../Optimizer/Optimizer.h"


typedef struct {
    char *model_name;
    int num_layers;
    Layer *layers;
    Optimizer optimizer;
} Model;


Model model_create(char *model_name);
void add_layer(Model *model, Layer layer);
void print_model_info(Model model);


#endif //C_COMPUTATIONAL_GRAPH_SEQUENTIAL_H
