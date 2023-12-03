// sort_lib.h
#ifndef SORT_LIB_H
#define SORT_LIB_H

// Пузырьковая сортировка
void BubbleSort(int *array, int size);

// Реализация сортировки Хоара (быстрой сортировки)
void QuickSort(int *array, int low, int high);

// Функция для сортировки массива (выбор метода сортировки)
int *Sort(int *array, int size, int method);

// Функция для вывода массива
void PrintArray(const int *array, int size);

#endif // SORT_LIB_H