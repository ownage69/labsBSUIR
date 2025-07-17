// Дана целочисленная квадратная матрица. Определить произведение элементов в тех строках, которые не содержат отрицательных элементов; максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <locale.h>
#define MAX_SIZE 100


void inputArray(int a[MAX_SIZE][MAX_SIZE], int size) {
    int randomFill;
    printf("Заполнить массив случайными числами? (1 - да, 0 - нет): ");
while (scanf_s("%d", &randomFill) != 1 || (randomFill != 0 && randomFill != 1)) { 
        printf("Ошибка! Введите 1 или 0: ");
        while (getchar() != '\n');  
    }
    if (randomFill) {
        srand(time(0));  
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                a[i][j] = rand() % 21 - 10;  
            }
        }
    }
    else {
        printf("Введите элементы массива:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                while (scanf_s("%d", &a[i][j]) != 1) { // 
                    printf("Ошибка! Введите целое число [% d][% d]: ", i + 1, j + 1);
                    while (getchar() != '\n');  
                }
            }
        }
    }
}
void printArray(int a[MAX_SIZE][MAX_SIZE], int size) {
    printf("\nМатрица %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}
void productRowsNoNegatives(int a[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        int product = 1; 
        int hasNegative = 0;  
        for (int j = 0; j < size; j++) {
            if (a[i][j] < 0) {
                hasNegative = 1;
                break;
            }
            product *= a[i][j];
        }
        if (!hasNegative) { 
            printf("Произведение чисел в строке % d: % d\n", i + 1, product);
        }
        else {
            printf("Строка %d содержит отрицательные числа\n", i + 1);
        }
    }
}
int maxSumDiagonals(int a[MAX_SIZE][MAX_SIZE], int size) {
    int maxSum = 0;
    int firstIteration = 1;
    for (int d = 0; d < size; d++) {
        int sum = 0;
        printf("\Диагональ,начиная с элемента [%d][%d]: ", 0, d);  
        for (int i = 0, j = d; j < size; i++, j++) {
            printf("%d ", a[i][j]);
            sum += a[i][j];
        }
        printf("\nСумма элементов этой диагонали: %d\n", sum);
        if (firstIteration || sum > maxSum) {
            maxSum = sum;
            firstIteration = 0;
        }
    }
    for (int d = 1; d < size; d++) {
        int sum = 0;
        printf("\nДиагональ,начиная с элемента [%d][%d]: ", d, 0);  
        for (int i = d, j = 0; i < size; i++, j++) {
            printf("%d ", a[i][j]);
            sum += a[i][j];
        }
        printf("\nСумма элементов этой диагонали:: %d\n", sum);
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}
int main() {
    system("chcp 1251");
    system("cls");
    int a[MAX_SIZE][MAX_SIZE];
    int size;
    printf("Введите размер квадратной матрицы  (1 - %d): ", MAX_SIZE);
    while (scanf_s("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка! Введите число от 1 до %d: ", MAX_SIZE);
        while (getchar() != '\n');  // Очищаем буфер ввода
    }
    inputArray(a, size);
    printArray(a, size);
    printf("\nПроизведение элементов в строке без отрицательных чисел:\n");
    productRowsNoNegatives(a, size);
    int maxDiagonalSum = maxSumDiagonals(a, size);
    printf("\Максимум среди сумм диагонаей, параллельных главной: %d\n", maxDiagonalSum);
    return 0;
}

