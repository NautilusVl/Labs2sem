#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dreamhead.h"

int main() {
    srand(time(NULL));
    int n, choice, sortChoice;
    int C = 0, M = 0;

    printf("Введите размер массива n: ");
    //scanf("%d", &n);
    if((scanf("%d",&n) == 1)&&(n>0)){
    int arr[n];

    printf("Выберите способ формирования массива (1 - случайные, 2 - убывание, 3 - возрастание): ");
    scanf("%d", &choice);
    //generateArray(arr, n, choice);
    
    switch (choice) {
    case 1:
        generateArray(arr, n, choice);
        break;
    case 2:
        generateArray(arr, n, choice);
        break;
    case 3:
        generateArray(arr, n, choice);
        break;
    default:
        printf("Неверный выбор способа формирования!\n");
        return -1;
    }
    
    printf("Исходный массив:\n");
    printArray(arr, n);

    printf("Выберите метод сортировки (1 - Бинарное включение, 2 - метод Шелла, 3 - bubble сорт.): ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
    case 1:
        binaryInsertionSort(arr, n, &C, &M);
        break;
    case 2:
        shellSort(arr, n, &C, &M);
        break;
    case 3:
        bubbleSort(arr, n, &C, &M);
        break;
    default:
        printf("Неверный выбор сортировки!\n");
        return -1;
    }

    printf("Отсортированный массив:\n");
    printArray(arr, n);

    printf("Количество сравнений: %d\n Количество перестановок: %d\n", C, M);

    return 0;
    }
    else{
        printf("Неверный размер массива!\n");
        return -1;
    }
}
