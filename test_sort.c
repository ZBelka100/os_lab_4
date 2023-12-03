// test_sort.c
#include <stdio.h>
#include <stdlib.h> 
#include "sort_lib.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <путь_к_файлу>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return EXIT_FAILURE;
    }

    int size;
    if (fscanf(file, "%d", &size) != 1) {
        fprintf(stderr, "Ошибка чтения размера массива из файла\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Ошибка выделения памяти");
        fclose(file);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; ++i) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "Ошибка чтения элемента массива из файла\n");
            fclose(file);
            free(array);
            return EXIT_FAILURE;
        }
    }

    fclose(file);

    // Выбор метода сортировки (1 - пузырьковая, 2 - быстрая)
    int method = 2;

    printf("Исходный массив: ");
    PrintArray(array, size);

    // Сортировка
    int *sortedArray = Sort(array, size, method);
    printf("Отсортированный массив: ");
    PrintArray(sortedArray, size);

    // Освобождение выделенной памяти
    free(array);
    free(sortedArray);

    return 0;
}
