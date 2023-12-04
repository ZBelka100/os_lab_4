#include "first.h"

void Sort(int *array, int size) { //bubble
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

float func(float x) {
    return sin(x);
}

float SinIntegralFunc(float A, float B, float e) {//RectangleMethod
    float sum = 0;
    for (float x = A; x < B; x += e) {
        sum += func(x) * e;
    }
    return sum;
}
