#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

// Сортировка методом Шелла
void shellSort(int *arr, int n, int *C, int *M) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                (*M)++;
                (*C)++;
            }
            arr[j] = temp;
            if (j != i) { // Если перестановка произошла
                (*M)++;
            }
        }
    }
}
