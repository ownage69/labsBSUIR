// В квадратной матрице размером NxN найти максимальный нечетный элемент в 4-ой области

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 
#define MAX_SIZE 100


void inputMatrix(int a[MAX_SIZE][MAX_SIZE], int size) {
    int randomFill;
    printf("Заполнить массив слувайными числами? (1 - да, 0 - нет): ");

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
                while (scanf_s("%d", &a[i][j]) != 1) {
                    printf("Ошибка! Введите целое число [% d][% d]: ", i + 1, j + 1);
                    while (getchar() != '\n');  
                }
            }
        }
    }
}
void printMatrix(int a[MAX_SIZE][MAX_SIZE], int size) {
    printf("\nМатрица %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}
int maxOddInFourthArea(int a[MAX_SIZE][MAX_SIZE], int size) {
    int maxOdd = -1;  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i + j >= size - 1 && j < i) {
                if (a[i][j] % 2 != 0) {  
                    if (maxOdd == -1 || a[i][j] > maxOdd) {
                        maxOdd = a[i][j];
                    }
                }
            }
        }
    }

    return maxOdd
}
int main() {
    system("chcp 1251");
    system("cls");
    int a[MAX_SIZE][MAX_SIZE];
    int size;
    printf("Введите размер квадратной матрицы (1 - %d): ", MAX_SIZE);
    while (scanf_s("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка! Введите число от 1 до %d: ", MAX_SIZE);
        while (getchar() != '\n');  
    }
    inputMatrix(a, size);
    printMatrix(a, size);
    int maxOdd = maxOddInFourthArea(a, size);
    if (maxOdd != -1) {
        printf("Максимальное нечетное число в 4-ой области: %d\n", maxOdd);
    }
    else {
        printf("В 4 области нет нечетных чисел\n");
    }
    return 0;
}
