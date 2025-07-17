// Найти в матрице первую строку, все элементы которой равны нулю. Все элементы столбца с таким же номером уменьшить вдвое

#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 100

void inputMatrix(int a[MAX_SIZE][MAX_SIZE], int size) {
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
        printf("Введите эелменты массива:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                while (scanf_s("%d", &a[i][j]) != 1) {
                    printf("Ошибка! Введите целое число [%d][%d]: ", i + 1, j + 1);
                    while (getchar() != '\n');  
                }
            }
        }
    }
}
void printMatrix(float a[MAX_SIZE][MAX_SIZE], int size) {
    printf("\nМатрица %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%6.1f ", a[i][j]);
        }
        printf("\n");
    }
}
void findZeroRowAndModifyColumn(int a[MAX_SIZE][MAX_SIZE], float fa[MAX_SIZE][MAX_SIZE], int size) {
    int foundRow = -1;
    for (int i = 0; i < size; i++) {
        int allZeros = 1; 
        for (int j = 0; j < size; j++) {
            if (a[i][j] != 0) {
                allZeros = 0; 
                break;
            }
        }
        if (allZeros) {
            foundRow = i;
            printf("\nНулевая строчка найдена: строчка %d\n", i + 1);
            break;
        }
    }
    if (foundRow == -1) {
        printf("\nНулевой строки не обнаружено!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fa[i][foundRow] = (float)a[i][foundRow] / 2.0;
    }
}
int main() { 
    system("chcp 1251");
    system("cls");
    int a[MAX_SIZE][MAX_SIZE];
    float fa[MAX_SIZE][MAX_SIZE];
    int size;
    printf("Введите размер матрицы (1 - %d): ", MAX_SIZE);
    while (scanf_s("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка! Введите число от 1 до %d: ", MAX_SIZE);
        while (getchar() != '\n');  
    }
    inputMatrix(a, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fa[i][j] = (float)a[i][j];
        }
    }
    printMatrix(fa, size);
    findZeroRowAndModifyColumn(a, fa, size);
    printMatrix(fa, size);
    return 0;
}
