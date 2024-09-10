#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Optimizer.h"

// 初始化 Adam 优化器
Optimizer init_adam_optimizer(double learning_rate, double beta1, double beta2, double epsilon) {
    Optimizer optimizer;
    optimizer.type = OPTIMIZER_ADAM;
    optimizer.learning_rate = learning_rate;
    optimizer.beta1 = beta1;
    optimizer.beta2 = beta2;
    optimizer.epsilon = epsilon;
    optimizer.m = NULL;  // 动态分配矩阵在使用时初始化
    optimizer.v = NULL;
    optimizer.t = 0;
    return optimizer;
}

