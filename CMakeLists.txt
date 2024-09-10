cmake_minimum_required(VERSION 3.27)
project(C_NeuralNetwork_Framework C)

set(CMAKE_C_STANDARD 11)

add_executable(C_NeuralNetwork_Framework
        Modules/derivation/derivative.c
        Modules/derivation/Jacobian.c
        Modules/Matrix_calculation/matrix_linear.c
        Modules/Matrix_calculation/matrix_multiply.c
        Modules/Matrix_calculation/test_transpose.c
        Modules/Matrix_calculation/test_matmul.c
        Modules/Matrix_calculation/matrix_transpose.c
        Modules/Matrix_calculation/matrix_base.c
        Modules/Sequential/build_model.c
        Modules/Optimizer/optimizer_BasicGD.c
        Modules/Matrix_calculation/matrix.h
        Modules/Optimizer/Optimizer.h
        Modules/Layer_Builder/Layer_Builder.h
        Modules/Optimizer/optimizer_Adam.c
        Modules/Sequential/forward.c
        Modules/Sequential/Sequential.h
        Modules/Layer_Builder/build_Linear.c
        Modules/Layer_Builder/initialization.c
        Modules/Layer_Builder/print_info.c
        run/test.c)
