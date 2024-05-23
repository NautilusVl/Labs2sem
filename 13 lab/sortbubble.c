#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

// Сортировка пузырьком
int bubbleSort(int *arr, int n, int *C, int *M) {
    int swapped = 1;
    for (int i = 0; i < n - 1 && swapped; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            (*C)++;
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
                (*M)++;
            }
        }
    }
    return swapped;
}
