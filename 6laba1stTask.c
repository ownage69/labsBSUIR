// В одномерном массиве выполнить сортировку нечетных отрицательных элементов методом пузырька

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void clearInputBuffer() {
    while (getchar() != '\n');
}

void inputArray(int* array, int size) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        while (scanf_s("%d", &array[i]) != 1) {
            printf("Ошибка: введите числовое значение для элемента %d: ", i + 1);
            clearInputBuffer();
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int* num, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > i; j--) {
            if ((num[j - 1] < 0 && num[j - 1] % 2 != 0) &&
                (num[j] < 0 && num[j] % 2 != 0) &&
                (num[j - 1] > num[j]))
            {
                // Обмен элементов
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

int allocateArray(int** array, int size) {
    *array = (int*)malloc(size * sizeof(int));
    if (*array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 0; 
    }
    return 1; 
}


int main() {
    setlocale(LC_ALL, "RUS");

    int size;
    int* array = NULL;
    printf("Введите размер массива: ");
    while (scanf_s("%d", &size) != 1 || size <= 0) {
        printf("Ошибка: введите положительное числовое значение для размера массива: ");
        clearInputBuffer();
    }
    if (!allocateArray(&array, size)) {
        return 0;
    }
    inputArray(array, size);
    printf("Исходный массив:\n");
    printArray(array, size);
    bubbleSort(array, size);
    printf("Массив после сортировки пузырьком:\n");
    printArray(array, size);
    printf("Нечетные отрицательные числа: ");
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 && array[i] % 2 != 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    free(array); 
    return 0;
}
