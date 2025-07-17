// В одномерном массиве, состоящем из k целых элементов, вычислить:
// - количество положительных элементов массива;
// - сумму элементов массива, расположенных после последнего элемента, равного нулю

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAX 100

int main()
{
	int a[MAX], v, size, c, i, sum;
	c = 0;
	sum = 0;
	printf("Введите размер массива : ");
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

	for (i = 0; i < size; i++) {
		if (a[i] > 0) {
			c = c + 1;
		}
	}
	for (i = 0; i < size; i++) {
		if (a[i] == 0) break;
	}
	for (i++; i < size; i++) {
		sum = sum + a[i];
	}
	printf("Кол-во положительных чисел в массиве = %d\n", c);
	printf("Сумма эелментов массива после 0 = %d", sum);
	return 0;
}


