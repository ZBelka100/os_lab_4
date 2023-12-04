#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void QuickSort(int *array, int low, int high) {//QuickSort
    if (low < high) {
        int pivot = array[low + (high - low) / 2];
        int i = low;
        int j = high;
        while (i <= j) {
            while (array[i] < pivot) {
                ++i;
            }
            while (array[j] > pivot) {
                --j;
            }
            if (i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                ++i;
                --j;
            }
        }
        QuickSort(array, low, j);
        QuickSort(array, i, high);
    }
}

float func(float x) {
    return sin(x);
}

void sort(int *array, int size) {
    QuickSort(array, 0, size - 1);
}

float SinIntegralFunc(float A, float B, float e) {//TrapezoidalMethod
    float sum = 0;
    for (float x = A; x < B; x += e) {
        sum += (func(x) + func(x + e)) * e / 2;
    }
    return sum;
}
