// Отсортировать методом слияния массив строк по количеству слов состоящим из четного количества символов

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int stringLength(char* str);
void getString(char** str, const char* prompt);
void showStrings(char** strings, int count);
int countEvenWords(char* str);
void mergeSort(char** strings, int left, int right);
void merge(char** strings, int left, int mid, int right);
void doProgram();

int main() {
    setlocale(LC_ALL, "rus");
    doProgram();
    return 0;
}

int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void getString(char** str, const char* prompt) {
    int length = 0;
    char ch;
    *str = NULL;
    printf("%s", prompt);
    while ((ch = getchar()) != '\n') {
        char* temp = (char*)realloc(*str, (length + 1) * sizeof(char));
        if (!temp) {
            free(*str);
            printf("Ошибка: недостаточно памяти.\n");
            exit(1);
        }
        *str = temp;
        (*str)[length++] = ch;
    }
    char* temp = (char*)realloc(*str, (length + 1) * sizeof(char));
    if (!temp) {
        free(*str);
        printf("Ошибка: недостаточно памяти.\n");
        exit(1);
    }
    *str = temp;
    (*str)[length] = '\0';
}

void showStrings(char** strings, int count) {
    printf("Отсортированные строки:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
    }
}

int countEvenWords(char* str) {
    int evenCount = 0;
    char* start = str;

    while (*start != '\0') {
        while (*start == ' ') start++;

        if (*start == '\0') break;

        char* wordStart = start;
        while (*start != ' ' && *start != '\0') start++;

        int wordLength = start - wordStart;
        if (wordLength % 2 == 0) {
            evenCount++;
        }
    }

    return evenCount;
}

void mergeSort(char** strings, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(strings, left, mid);
        mergeSort(strings, mid + 1, right);
        merge(strings, left, mid, right);
    }
}

void merge(char** strings, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char** leftArray = (char**)malloc(n1 * sizeof(char*));
    char** rightArray = (char**)malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) {
        leftArray[i] = strings[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = strings[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (countEvenWords(leftArray[i]) <= countEvenWords(rightArray[j])) {
            strings[k++] = leftArray[i++];
        }
        else {
            strings[k++] = rightArray[j++];
        }
    }

    while (i < n1) {
        strings[k++] = leftArray[i++];
    }

    while (j < n2) {
        strings[k++] = rightArray[j++];
    }

    free(leftArray);
    free(rightArray);
}

void doProgram() {
    int n;
    printf("Введите количество строк: ");
    scanf_s("%d", &n);
    getchar();  // Удаление символа новой строки после ввода числа

    char** strings = (char**)malloc(n * sizeof(char*));
    if (!strings) {
        printf("Ошибка: недостаточно памяти.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        getString(&strings[i], "Введите строку: ");
    }

    mergeSort(strings, 0, n - 1);

    showStrings(strings, n);

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
}
