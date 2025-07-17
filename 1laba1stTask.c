// Ввести стороны прямоугольного параллелепипеда. Найти площадь поверхности и объем параллелепипеда. Результат вывести с точностью до трех знаков после запятой

#include <stdio.h>
#include <locale.h>

int main() {
	float a, b, c, s1, s2;

	printf("Enter the value sides: ");
	scanf_s("%f %f %f", &a, &b, &c);

	s1 = 2 * (a * b + b * c + a * c);
	s2 = a * b * c;
	printf("Площадь полной поверхности = %.3f\n", s1);
	printf("Объём = %.3f", s2);

	return 0;
}
