// В матрице размером NxM выполнить сортировку столбцов по убыванию значения максимального элемента методом Шелла

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void shellSortColumn(int** matrix, int rows, int col) {
    int gap = rows / 2;  
    while (gap > 0) {     
        for (int i = gap; i < rows; i++) 
            int temp = matrix[i][col]; 
            int j = i;
            while (j >= gap && matrix[j - gap][col] < temp) { 
                matrix[j][col] = matrix[j - gap][col
                j -= gap;
            }
            matrix[j][col] = temp; 
        }
        gap /= 2; 
    }
}

int findMaxInColumn(int** matrix, int rows, int col) {
    int max = matrix[0][col];
    for (int i = 1; i < rows; i++) {
        if (matrix[i][col] > max) {
            max = matrix[i][col];
        }
    }
    return max;
}

void sortColumnsByMax(int** matrix, int rows, int cols) {
    for (int col = 0; col < cols - 1; col++) {  
        for (int nextCol = col + 1; nextCol < cols; nextCol++) {
            if (findMaxInColumn(matrix, rows, col) < findMaxInColumn(matrix, rows, nextCol)) {
                for (int row = 0; row < rows; row++) {
                    int temp = matrix[row][col];
                    matrix[row][col] = matrix[row][nextCol];
                    matrix[row][nextCol] = temp;
                }
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    int rows, cols;
    printf("Введите количество строк и столбцов: ");
    while (scanf_s("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Ошибка: введите положительные числовые значения для строк и столбцов: ");
    }
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти для строки %d.\n", i + 1);
            return 1;
        }
    }
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            while (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("Ошибка: введите числовое значение для элемента [%d][%d]: ", i + 1, j + 1);
                while (getchar() != '\n'); // Очистка буфера ввода
            }
        }
    }

    printf("\nИсходная матрица:\n");
    printMatrix(matrix, rows, cols);
    sortColumnsByMax(matrix, rows, cols);
    printf("\nМатрца после сортировки столбцов по убыванию максимального элемента:\n");
    printMatrix(matrix, rows, cols);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

