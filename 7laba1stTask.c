// Дана строка. Удалить все слова меньшие k букв

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int getNaturalValue();
int stringLength(char* str);
void getString(char** str);
void showString(char* str);
void removeShortWords(char** str, int k);
void doProgram();

int main() {
    setlocale(LC_ALL, "rus");
    doProgram();
    return 0;
}

int getNaturalValue() {
#define MAX_STRING_SIZE 255
    int stringValueSize = 0, checker, value = 0;
    char stringValue[MAX_STRING_SIZE], temp;
    while (true) {
        printf("Введите натуральное значение: ");
        gets(stringValue);
        checker = true;
        for (int i = 0; i < MAX_STRING_SIZE; i++) {
            temp = stringValue[i];
            if (temp == '\0') {
                stringValueSize = i;
                break;
            }
            if (temp < '0' || temp > '9') {
                checker = false;
                break;
            }
        }
        if (checker) {
            for (int i = 0; i < stringValueSize; i++) {
                value = value * 10 + (stringValue[i] - '0');
            }
            if (value > 0)
                break;
        }
        printf("Вы ввели неверное значение. Попробуйте ещё раз!\n\n");
        value = 0;
    }
    return value;
}

int stringLength(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void getString(char** str) {
    int length = 0;
    char ch;
    *str = NULL;
    printf("Введите строку: ");
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

void showString(char* str) {
    printf("Строка: %s\n", str);
}

void removeShortWords(char** str, int k) {
    char* result = NULL;
    int length = 0;
    char* start = *str;
    char* wordStart;

    while (*start != '\0') {
        while (*start == ' ') start++;

        if (*start == '\0') break;

        wordStart = start;
        while (*start != ' ' && *start != '\0') start++;

        int wordLength = start - wordStart;
        if (wordLength >= k) {
            char* temp = (char*)realloc(result, (length + wordLength + 2) * sizeof(char));
            if (!temp) {
                free(result);
                printf("Ошибка: недостаточно памяти.\n");
                exit(1);
            }
            result = temp;
            for (int i = 0; i < wordLength; i++) {
                result[length++] = wordStart[i];
            }
            result[length++] = ' ';
        }
    }

    if (length > 0 && result[length - 1] == ' ') {
        result[length - 1] = '\0';
    }
    else if (result) {
        result[length] = '\0';
    }
    else {
        result = (char*)malloc(sizeof(char));
        if (!result) {
            printf("Ошибка: недостаточно памяти.\n");
            exit(1);
        }
        result[0] = '\0';
    }

    free(*str);
    *str = result;
}

void doProgram() {
    char* str;
    int k;
    getString(&str);
    showString(str);
    k = getNaturalValue();
    removeShortWords(&str, k);
    showString(str);
    free(str);
}
