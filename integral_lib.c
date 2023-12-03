#include "integral_lib.h"
#include <stdio.h>
#include <math.h>

float computeMachineEpsilon() {
    float epsilon = 1.0f;
    while ((1.0f + epsilon) > 1.0f) {
        epsilon /= 2.0f;
    }
    return epsilon;
}

float func(float x) {
    return sin(x);
}

float RectangleMethod(float A, float B, float e) {
    float sum = 0;
    for (float x = A; x < B; x += e) {
        sum += func(x) * e;
    }
    return sum;
}

float TrapezoidalMethod(float A, float B, float e) {
    float sum = 0;
    for (float x = A; x < B; x += e) {
        sum += (func(x) + func(x + e)) * e / 2;
    }
    return sum;
}

float SinIntegral(float A, float B, float e, int method) {
    if (method == 1) {
        return RectangleMethod(A, B, e);
    } else if (method == 2) {
        return TrapezoidalMethod(A, B, e);
    } else {
        fprintf(stderr, "Ошибка: неверный метод!\n");
        return 0;
    }
}
