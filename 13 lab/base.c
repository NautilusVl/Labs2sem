/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Прототипы функций
void generateArray(int *arr, int n, int mode);
void printArray(int *arr, int n);
void binaryInsertionSort(int *arr, int n, int *C, int *M);
void shellSort(int *arr, int n, int *C, int *M);
int bubbleSort(int *arr, int n, int *C, int *M);

int main() {
    srand(time(NULL));
    int n, choice, sortChoice;
    int C = 0, M = 0;

    printf("Введите размер массива n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Выберите способ формирования массива (1 - случайные, 2 - убывание, 3 - возрастание): ");
    scanf("%d", &choice);
    generateArray(arr, n, choice);

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

// Функция вывода массива
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
