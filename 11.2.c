#include <stdio.h>
#include <stdlib.h>

int findMaxNegative(int arr[], int size, int index, int maxNegative) {
    if (index == size) {
        return maxNegative;
    }

    if (arr[index] < 0 && arr[index] > maxNegative) {
        maxNegative = arr[index];
    }

    return findMaxNegative(arr, size, index + 1, maxNegative);
}

int main() {
    int size;
    printf("Enter size of arr: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter element:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int maxNegative = -999999;
    maxNegative = findMaxNegative(arr, size, 0, maxNegative);

    if (maxNegative != -999999) {
        printf("Max negative element = : %d\n", maxNegative);
    } else {
        printf("there is no negative elements\n");
    }

    free(arr);
    return 0;
}
