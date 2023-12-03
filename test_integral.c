#include <dlfcn.h>
#include <stdio.h>
//#include "integral_lib.h"

typedef float (*SinIntegralFunc)(float A, float B, float e, int method);

int main() {
    // Загрузка библиотеки
    //gcc -shared -fPIC integral_lib.c -o integral_lib.so -lm
    void *libHandle = dlopen("./libintegral.so", RTLD_LAZY);
    if (!libHandle) {
        fprintf(stderr, "Ошибка загрузки библиотеки: %s\n", dlerror());
        return 1;
    }

    // Получение указателя на функцию SinIntegral 
    SinIntegralFunc sinIntegral = (SinIntegralFunc)dlsym(libHandle, "SinIntegral");
    if (!sinIntegral) {
        fprintf(stderr, "Ошибка получения функции SinIntegral: %s\n", dlerror());
        dlclose(libHandle);
        return 1;
    }

    int method;
    float A, B, e;

    printf("Выберите метод для вычисления интеграла (1 - прямоугольники, 2 - трапеции): ");
    scanf("%d", &method);

    printf("Введите нижний предел интегрирования A: ");
    scanf("%f", &A);

    printf("Введите верхний предел интегрирования B: ");
    scanf("%f", &B);

    printf("Введите шаг интегрирования e: ");
    scanf("%f", &e);

    // Вычисление интеграла с использованием динамически загруженной функции
    float result = sinIntegral(A, B, e, method);

    // Вывод результата
    printf("Результат вычислений: %f\n", result);

    // Закрытие библиотеки
    dlclose(libHandle);

    return 0;
}
