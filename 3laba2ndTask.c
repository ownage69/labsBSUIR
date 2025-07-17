// В массиве из n элементов до каждого k-го элемента добавить 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX 100

int main() {
    int a[MAX]; 
    int size, v, k;
    int i = 0;
    int j = 0;
    printf("Введите желаемый размер массива: ");
    scanf_s("%d", &size);

	if (size < 1 || size > MAX) {
		printf("Ошибка!\n");
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
    printf("Введите число k (после которых надо добавить 0) : ");
    scanf_s("%d", &k);
    for (i = size - 1; i >= 0; i--) { 
        if ((i + 1) % k == 0) { 
                     for (j = size; j > i; j--) {  
                a[j] = a[j - 1]; 
            }
            a[i] = 0; 
            size++;        
                 }
    }
    printf("Изменённый массив: ");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
