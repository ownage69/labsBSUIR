// Определить, находится ли точка M(a,b) внутри верхней части единичного круга с центром в нале координат

#include <stdio.h>
#include <locale.h>

int main() {
    double x, y;

    printf("Введите координаты точки M (x,y): ");
    scanf_s("%lf %lf", &x, &y);


    if (x * x + y * y <= 1 && y >= 0) {
        printf("Да\n");
    }
    else {
        printf("Нет\n");
    }

    return 0;
}
