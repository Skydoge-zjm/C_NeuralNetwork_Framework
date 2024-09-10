
#include "../Modules/Sequential/Sequential.h"


int main()
{
    Model my_model = model_create("model_1");

    Layer layer1 = init_linear_layer(4, 8, RANDOM_INITIALIZATION);
    add_layer(&my_model, layer1);

    Layer layer2 = init_linear_layer(8, 10, XAVIER_INITIALIZATION);
    add_layer(&my_model, layer2);

    print_model_info(my_model);
    print_layer_weights(my_model.layers[0]);
    print_layer_weights(my_model.layers[1]);

}