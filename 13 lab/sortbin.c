#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

// Сортировка бинарным включением
void binaryInsertionSort(int *arr, int n, int *C, int *M) {
    int left, right, mid, key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        left = 0;
        right = i;
        while (left < right) {
            mid = left + (right - left) / 2;
            (*C)++;
            if (key < arr[mid])
                right = mid;
            else
                left = mid + 1;
        }
        for (j = i; j > left; j--) {
            arr[j] = arr[j - 1];
            (*M)++;
        }
        arr[j] = key;
        (*M)++;
    }
}
