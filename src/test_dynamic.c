#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef float (*SinIntegralFunc)(float A, float B, float e);
typedef void (*SortFunc)(int *array, int size);

int main() {
    void *libHandle;
    int number_lib = 1;
    SinIntegralFunc sinIntegral;
    SortFunc sort;
    libHandle = dlopen("./libfirst.so", RTLD_LAZY);
    int choice = 1;  // Инициализация, чтобы цикл начался

    while (choice != -1) {
        printf("Выберите операцию (-1 - выход, 0 - сменить библиотеку, 1 - вычислить интеграл, 2 - отсортировать массив): ");
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        } else if (choice == 0) {
            // Закрытие текущей библиотеки (если есть)
            if (libHandle) {
                dlclose(libHandle);
            }

            // Смена библиотеки
            if (number_lib == 2) {
                libHandle = dlopen("./libfirst.so", RTLD_LAZY);
                number_lib = 1;
            } else {
                libHandle = dlopen("./libsecond.so", RTLD_LAZY);
                number_lib = 2;
            }

            if (libHandle == NULL) {
                fprintf(stderr, "Ошибка загрузки библиотеки: %s\n", dlerror());
                continue;
            }
        } else if (choice == 1) {
            sinIntegral = (SinIntegralFunc)dlsym(libHandle, "SinIntegralFunc");
            if (!sinIntegral) {
                fprintf(stderr, "Ошибка получения функции SinIntegral: %s\n", dlerror());
                dlclose(libHandle);
                return 1;
            }

            float A, B, e;
            scanf("%f %f %f", &A, &B, &e);
            float result = sinIntegral(A, B, e);
            printf("Результат вычислений: %f\n", result);
        } else if (choice == 2) {
            int size;
            scanf("%d", &size);

            int *array = (int *)malloc(size * sizeof(int));
            for (int i = 0; i < size; ++i) {
                scanf("%d", &array[i]);
            }

            sort = (SortFunc)dlsym(libHandle, "Sort");
            if (!sort) {
                fprintf(stderr, "Ошибка получения функции сортировки: %s\n", dlerror());
                free(array);
                continue;
            }

            sort(array, size);

            printf("Отсортированный массив: ");
            for (int i = 0; i < size; ++i) {
                printf("%d ", array[i]);
            }
            printf("\n");

            free(array);
        } else {
            printf("Некорректный выбор операции.\n");
        }
    }

    if (libHandle) {
        dlclose(libHandle);
    }

    return 0;
}
