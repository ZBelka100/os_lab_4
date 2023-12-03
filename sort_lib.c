// sort_lib.c
#include "sort_lib.h"
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *array, int size) {
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

void QuickSort(int *array, int low, int high) {
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

int *Sort(int *array, int size, int method) {
    int *sortedArray = (int *)malloc(size * sizeof(int));
    if (sortedArray == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        sortedArray[i] = array[i];
    }
    switch (method) {
        case 1:
            BubbleSort(sortedArray, size);
            break;
        case 2:
            QuickSort(sortedArray, 0, size - 1);
            break;
        default:
            fprintf(stderr, "Ошибка: неверный метод сортировки!\n");
            free(sortedArray);
            exit(EXIT_FAILURE);
    }

    return sortedArray;
}

void PrintArray(const int *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
