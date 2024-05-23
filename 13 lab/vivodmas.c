#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

// Функция вывода массива
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
