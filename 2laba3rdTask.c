// Дано целое число N (> 1). Найти первое число Фибоначчи, большее N

#include <stdio.h>
#include <locale.h>

int main() {
    int N, fib1 = 0, fib2 = 1, fibNext;


    printf("Введите число N > 1: ");
    if (scanf_s("%d", &N) != 1 || N <= 1) {
        printf("Некорерктный ввод! Введите число > 1\n");
        return 1;
    }

    while (1) { 
        fibNext = fib1 + fib2; 
        if (fibNext > N) {
            printf("Первое число Фибоначчи большее %d: %d\n", N, fibNext);
            break;
        }
        fib1 = fib2;
        fib2 = fibNext;
    }

    return 0;
}
