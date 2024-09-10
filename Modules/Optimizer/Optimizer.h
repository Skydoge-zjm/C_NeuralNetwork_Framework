#ifndef C_COMPUTATIONAL_GRAPH_OPTIMIZER_H
#define C_COMPUTATIONAL_GRAPH_OPTIMIZER_H

#include "../Matrix_calculation/matrix.h"
#include "../Layer_Builder/Layer_Builder.h"

// 定义 OptimizerType 枚举
typedef enum {
    OPTIMIZER_BASIC_GRADIENT_DECENT,  //梯度下降
    OPTIMIZER_SGD,  // 随机梯度下降
    OPTIMIZER_ADAM  // Adam 优化器
} OptimizerType;

typedef struct {
    OptimizerType type;      // 优化器类型
    double learning_rate;    // 学习率

    double beta1;
    double beta2;
    double epsilon;

    Matrix *m;               // momentum_1
    Matrix *v;               // momentum_2
    int t;                   // time_step
} Optimizer;

#endif //C_COMPUTATIONAL_GRAPH_OPTIMIZER_H
