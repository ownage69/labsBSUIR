// Составить программу, которая бы с помощью оператора CASE реализовала бы все возможные операции над двумя целыми числами

#include <stdio.h>
#include <locale.h>

int main() {
	int a, b, c;
	char operation;

	printf("Введите первое число: ");
	scanf_s("%d", &a);

	printf("Введите второе число: ");
	scanf_s("%d", &b);

	printf("Выберите операцию: + (сложение), - (вычитание), * (умножение), / (деленеие) \n");
	scanf_s(" %c", &operation);

	switch (operation) {
	case '+':
		c = a + b;
		printf("Результат = %d ", c);
		break;
	case '-':
		c = a - b;
		printf("Результат = %d", c);
		break;
	case '/':
		c = a / b;
		printf("Результат = %d", c);
		break;
	case '*':
		c = a * b;
		printf("Результат = %d", c);
		break;
	default: printf("Ошибка! Выберите операцию");
		break;
	}
	return 0;
}
