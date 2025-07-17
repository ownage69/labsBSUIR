// В массиве из n элементов найти самое часто встречающееся четное число. Дополнительных массивов не использовать

Код:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX 100

int main() {
    int a[MAX], v, size;
    int maxCount = 0;         
    int mostFrequentEven = -1; 
    printf("Введите размер массива : ");
    scanf_s("%d", &size);

    if (size < 1 || size > MAX) {
        printf("Error\n");
        return 1;
    }

    	printf("Выберите метод заполнения массива:\n1. Вручную с клавиатуры\n2. Случайные числа\n1 или 2:\n");
	scanf_s("%d", &v);

	if (v == 1) {
		printf("Вводите элементы массива:\n");
		for (i = 0; i < size; i++) {
			printf("Элемент %d: ", i + 1);
			scanf_s("%d", &a[i]);
		}
	}

	else if (v == 2) {
		printf("Массив из случайных чисел:\n");
		srand(time(NULL)); 

		for (int i = 0; i < size; i++) {
			a[i] = (rand() % 51) - 25; // случайное значение от -25 до +25
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	else {
		printf("Ошибка! Выберите правильное число (1 или 2!)\n");
		return 1;
	}

       for (int i = 0; i < size; i++) { 
        if (a[i] % 2 == 0) {  
            int count = 1;     
            for (int j = i + 1; j < size; j++) { 
                if (a[i] == a[j]) {
                    count++;    
                }
            }
                        if (count > maxCount) {
                maxCount = count;
                mostFrequentEven = a[i];
            }
            else if (count == maxCount && a[i] > mostFrequentEven) {
                mostFrequentEven = a[i];
            }
        }
    }

    if (mostFrequentEven != -1) {
        printf("Самое часто встречающееся четное число: %d\n", mostFrequentEven);
    }
    else {
        printf("Нет четных чисел\n");
    }
    return 0;
}
