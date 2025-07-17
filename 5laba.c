// Заполнить массив с клавиатуры. Удалить все элементы с наименьшим значением.
// В двумерном массиве натуральных чисел удалить четные числа, стоящие в чётных столбцах. Количество чисел в строке может быть различным, последнее число - -1.
// В двумерной матрице размером NxM удалить все столбцы содержащие только отрицательные числа

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Функция для проверки, является ли строка числом
int isNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;  
        }
    }
    return 1;  
}

// Функция для ввода целого положительного числа через строку
int getPositiveInt() {
    char input[100];
    while (1) {
        printf("Введите положительное числовое значение: ");
        fgets(input, sizeof(input), stdin);  
        input[strcspn(input, "\n")] = '\0';  

        if (isNumber(input)) {
            int num = atoi(input);  
            if (num > 0) {
                return num;  
            }
        }
        printf("Ошибка: введено некорректное значение. Пожалуйста, введите положительное число.\n");
    }
}

// Функция для ввода номера задачи
int getTaskChoice() {
    int choice;
    char input[100];

    printf("Выберите задачу:\n1 - Удалить элементы с минимальным значением из массива\n");
    printf("2 - Удалить чётные числа в чётных столбцах в двумерном массиве\n");
    printf("3 - Удалить столбцы с отрицательными числами в двумерной матрице\n");

    while (1) {
        printf("Введите номер задачи: ");
        fgets(input, sizeof(input), stdin);  
        input[strcspn(input, "\n")] = '\0'; 

        if (isNumber(input)) {
            choice = atoi(input);  
            if (choice >= 1 && choice <= 3) {
                return choice;  
            }
        }
        printf("Ошибка: введите корректный номер задачи (1, 2 или 3).\n");
    }
}

// Функция для заполнения массива с клавиатуры с проверкой ввода
void fillArray(int* array, int size) {
    printf("Введите элементы массива:\n");
    char input[100];
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        while (1) {
            fgets(input, sizeof(input), stdin);  
            input[strcspn(input, "\n")] = '\0';  

            if (isNumber(input)) {
                array[i] = atoi(input);
                break;
            }
            printf("Ошибка: введите числовое значение для элемента %d: ", i + 1);
        }
    }
}

// Функция для удаления элементов с минимальным значением из массива
void removeMinElements(int** array, int* size) {
    int min = (*array)[0];
    for (int i = 1; i < *size; i++) {
        if ((*array)[i] < min) {
            min = (*array)[i];
        }
    }

    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if ((*array)[i] != min) {
            newSize++;
        }
    }


    int* newArray = (int*)malloc(newSize * sizeof(int));
    if (newArray == NULL) {  
        printf("Ошибка выделения памяти.\n");
        return;
    }

    int j = 0;
    for (int i = 0; i < *size; i++) {
        if ((*array)[i] != min) {
            newArray[j++] = (*array)[i];  
        }
    }

    free(*array);  
    *array = newArray;  
    *size = newSize;  
}

// Функция для удаления чётных чисел в чётных столбцах
void removeEvenInEvenColumns(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        int* row = matrix[i];
        for (int j = 1; row[j] != -1; j += 2) { 
            if (row[j] % 2 == 0) {
                row[j] = -1;  
            }
        }
    }
}

// Функция для удаления столбцов с отрицательными числами
void removeColumnsWithAllNegative(int** matrix, int rows, int* cols) {
    int* toRemove = (int*)calloc(*cols, sizeof(int));  
    for (int j = 0; j < *cols; j++) {
        int allNegative = 1;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] >= 0) {  
                allNegative = 0;
                break;
            }
        }
        if (allNegative) {
            toRemove[j] = 1;  
        }
    }

    int newCols = 0;
    for (int j = 0; j < *cols; j++) {
        if (!toRemove[j]) {
            newCols++;  
        }
    }

    // Перестроение строк без удалённых столбцов
    for (int i = 0; i < rows; i++) {
        int* newRow = (int*)malloc(newCols * sizeof(int));  
        if (newRow == NULL) {
            printf("Ошибка выделения памяти.\n");
            free(toRemove);
            return;
        }
        int index = 0;
        for (int j = 0; j < *cols; j++) {
            if (!toRemove[j]) {
                newRow[index++] = matrix[i][j];  
            }
        }
        free(matrix[i]);
        matrix[i] = newRow; 
    }

    *cols = newCols;  
    free(toRemove);  
}

// Функция для вывода одномерного массива
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функция для вывода двумерного массива с -1 в конце строки
void printMatrixWithEndMarker(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; matrix[i][j] != -1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("-1\n");
    }
}

// Функция для вывода обычной матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для задачи 1
void task1() {
    int size;
    printf("Введите размер массива: ");
    size = getPositiveInt();

    int* array = (int*)malloc(size * sizeof(int));  
    if (array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return;
    }

    fillArray(array, size);
    printf("Исходный массив:\n");
    printArray(array, size);

    removeMinElements(&array, &size);
    printf("Массив после удаления элементов с минимальным значением:\n");
    printArray(array, size);

    free(array); 
}

// Функция для задачи 2
void task2() {
    int rows;
    printf("Введите количество строк: ");
    rows = getPositiveInt();

    int** matrix = (int**)malloc(rows * sizeof(int*));  
    for (int i = 0; i < rows; i++) {
        int cols;
        printf("Введите количество элементов в строке %d (последнее значение -1): ", i + 1);
        scanf_s("%d", &cols);

        matrix[i] = (int*)malloc((cols + 1) * sizeof(int));  
        for (int j = 0; j < cols; j++) {
            printf("Элемент %d строки %d: ", j + 1, i + 1);
            while (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("Ошибка: введите числовое значение для элемента [%d][%d]: ", i + 1, j + 1);
            }
        }
        matrix[i][cols] = -1;  
    }

    printf("Исходный массив:\n");
    printMatrixWithEndMarker(matrix, rows);

    removeEvenInEvenColumns(matrix, rows);
    printf("Массив после удаления чётных чисел в чётных столбцах:\n");
    printMatrixWithEndMarker(matrix, rows);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);  
    }
    free(matrix);  
}

// Функция для задачи 3
void task3() {
    int rows, cols;
    printf("Введите количество строк: ");
    rows = getPositiveInt();

    printf("Введите количество столбцов: ");
    cols = getPositiveInt();

    int** matrix = (int**)malloc(rows * sizeof(int*));  
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));  
        for (int j = 0; j < cols; j++) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            while (scanf_s("%d", &matrix[i][j]) != 1) {
                printf("Ошибка: введите числовое значение для элемента [%d][%d]: ", i + 1, j + 1);
            }
        }
    }

    printf("Исходная матрица:\n");
    printMatrix(matrix, rows, cols);

    removeColumnsWithAllNegative(matrix, rows, &cols);
    printf("Матрица после удаления столбцов с отрицательными числами:\n");
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]); 
    }
    free(matrix);  
}

int main() {
    setlocale(LC_ALL, "RUS");

    int choice = getTaskChoice();  

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    default: printf("Некорректный выбор.\n"); break;
    }

    return 0;
}
