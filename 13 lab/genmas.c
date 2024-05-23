#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

// Функция генерации массива
void generateArray(int *arr, int n, int mode) {
    srand(time(NULL)); // Инициализация генерации случайных чисел
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 203 - 101; // Случайные числа в диапазоне [-101, 101]
    }

    if (mode == 2) { // Убывание
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else if (mode == 3) { // Возрастание
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
