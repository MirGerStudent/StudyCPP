#include <iostream>
#include <cmath>

int main() {
	//Константы которые можно менять
	const int ArgWidthY = 14;		  //Ширина вывода значения аргумента
	const int ArgWidthFloatY = 11; //Ширина вывода значения после запятой
	const int ArgWidthX = 6;		  //Ширина вывода значения аргумента
	const int ArgWidthFloatX = 2; //Ширина вывода значения после запятой
	const int lines = 10;  //Число строк (без учёта пояснений)
	const int columns = 3; //Число столбцов
	//Константы не подлежащие изминениям
	const double MinXBorder = -2.7f; //Нижняя граница x
	const double MaxXBorder = 2.3f;  //Верхняя граница x
	const double MinPBorder = -3.0f; //Нижняя граница p
	const double MaxPBorder = 3.0f;  //Верхняя граница p
	const double h = 0.05; //Шаг для x

	int n=0, page=0, column, count, nextPage=0;
	double p=10.0, x, MaxX;
	double y; //Значение функции f(x)
	char nextChar;

	while ((p<MinPBorder) || (p>MaxPBorder)) {
		system("clear");
		printf("Введите значение p, такое что соответсвует условию: p должно быть больше или равно 3\n");
		scanf("%lf", &p);
	}
	//printf("Число подходит!\n");

	MaxX = MaxXBorder + h*0,3;
	x = MinXBorder;
	while (x <= MaxX) {
		system("clear");
		page++;
		printf("Страница %d\n", page);
		printf("Таблица значений функции при параметре %4.2lf\n", p);

		// count = columns*26+1;
		count = columns*(12+ArgWidthY+ArgWidthX)+1;
		for (int i = 0; i < count; ++i) {
			printf("*");
		}
		printf("\n");

		for (column = 1; column <= columns; column++) {
				 printf("*  ARGUMENT  ");
				 printf("*  ");
				 for (int i = 0; i < floor((ArgWidthY-8)/2); ++i) {
	 			   printf(" ");
	 		   }
				 printf("FUNCTION  ");
				 if (ArgWidthY%2 == 1) {
					 printf(" ");
				 }
				 for (int i = 0; i < floor((ArgWidthY-8)/2); ++i) {
	 			   printf(" ");
	 		   }
		}
		printf("*\n");

		for (int line = 0; (line <= lines) && (x <= MaxX); line++) {
			for (int i = 0; i < count; ++i) {
			  printf("*");
		  }
		printf("\n");

		for (column = 0; (column < columns) && (x <= MaxX); column++) {
			if (x >= atan(p-2)) {
				//y = 10;
	 			y = pow((x*x*x*x+1)/(0.2 + p*p*x*x), 1./3.);
	 		}
	 		else {
				//y = 10+1;
	 			y = log10(2*M_PI + exp(fabs(p*x)));
	 		}

			printf("*  %*.*lf    ", ArgWidthX, ArgWidthFloatX, x);
			printf("* %*.*lf   ", ArgWidthY, ArgWidthFloatY, y);
			x += h;
			}
			printf("*\n");
		}

		for (int i = 0; i < count; ++i) {
			printf("*");
		} printf("\n");

			printf("Перейти на следующую страницу? (Y)\n");
			while (nextChar != 'Y') {
			scanf("%c", &nextChar);
		}
		nextChar = 'K';
 	}
    return 0;
}