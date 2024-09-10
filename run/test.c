
#include "../Modules/Sequential/Sequential.h"


int main()
{
    Model my_model = model_create("model_1");

    Layer layer1 = init_linear_layer(4, 8, RANDOM_INITIALIZATION);
    add_layer(&my_model, layer1);

    Layer layer2 = init_linear_layer(8, 10, XAVIER_INITIALIZATION);
    add_layer(&my_model, layer2);

    Layer layer3 = init_linear_layer(10, 5, XAVIER_INITIALIZATION);
    add_layer(&my_model, layer3);
/*
    Layer layer3 = init_ReLU_layer(10);
    add_layer(&my_model, layer3);
*/
    print_model_info(my_model);
    print_layer_weights(my_model.layers[0]);
    print_layer_weights(my_model.layers[1]);

    Matrix x = create_matrix(1, 4);
    print_matrix_shape(x);
    Matrix y = forward(my_model, x);

    print_matrix_shape(y);
    print_matrix(y);

    return 0;
}