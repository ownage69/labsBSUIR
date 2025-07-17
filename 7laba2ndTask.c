// Даны  строки  S  и  S0.  Удалить  из  строки  S  первую  подстроку,  совпадающую  с  S0.  Если  совпадающих  подстрок  нет,  то  вывести  строку  S  без изменений

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int stringLength(char* str);
void getString(char** str, const char* prompt);
void showString(char* str);
void removeSubstring(char** str, char* s0);
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

void showString(char* str) {
    printf("Результирующая строка: %s\n", str);
}

void removeSubstring(char** str, char* s0) {
    int strLen = stringLength(*str);
    int s0Len = stringLength(s0);
    char* pos = *str;
    char* result = NULL;
    int length = 0;

    while (*pos != '\0') {
        // Найти совпадение подстроки
        if (strncmp(pos, s0, s0Len) == 0) {
            pos += s0Len;
            break;
        }

        // Добавить символ в результат
        char* temp = (char*)realloc(result, (length + 1) * sizeof(char));
        if (!temp) {
            free(result);
            printf("Ошибка: недостаточно памяти.\n");
            exit(1);
        }
        result = temp;
        result[length++] = *pos++;
    }

    // Добавить оставшуюся часть строки
    while (*pos != '\0') {
        char* temp = (char*)realloc(result, (length + 1) * sizeof(char));
        if (!temp) {
            free(result);
            printf("Ошибка: недостаточно памяти.\n");
            exit(1);
        }
        result = temp;
        result[length++] = *pos++;
    }

    // Завершить строку
    if (result) {
        char* temp = (char*)realloc(result, (length + 1) * sizeof(char));
        if (!temp) {
            free(result);
            printf("Ошибка: недостаточно памяти.\n");
            exit(1);
        }
        result = temp;
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
    char* s0;
    getString(&str, "Введите строку S: ");
    getString(&s0, "Введите подстроку S0: ");
    removeSubstring(&str, s0);
    showString(str);
    free(str);
    free(s0);
}
