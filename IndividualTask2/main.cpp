#include <iostream>
#include "Matrix.h"

void Matrix::information() {
    std::cout << "lines - " << lines << std::endl << "columns - " << columns << std::endl; 
}

int main() {
    int x = 0, y = 0;
    int fnum, maxnum=0, minnum = 1, k2=1;
    double k1=1, value;  
    char answer = 'o';

    while (answer != 'e') {
        system("clear");
  		printf("Меню программы:\n");
        printf("Создать класс матрицы:");
        printf("");
    }
    

    while (x <= 0) {
        printf("Input lines - ");
        scanf("%d", &x);
    }
    while (y <= 0) {
        printf("Input columns - ");
        scanf("%d", &y);
    }
    Matrix A = Matrix(x, y);

    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++) {
    //         printf("Введите значение Matrix[%d][%d] - ", i, j);
    //         std::cin >> value;
    //         A.setvalue(i, j, value);
    //     }
    // }

    // for (int i = 0; i < x; i++) {
    //     for (int j = 0; j < y; j++) {
    //         A.getvalue(i, j, value);
    //         std::cout << value << " ";
    //     }
    //     std::cout << std::endl;
    // }
    

    while (minnum > maxnum) {
		printf("Введите значенния min < max, учтите что это целые числа!\n");
		printf("Введите максимальное число: ");
		scanf("%d", &maxnum);
		printf("Введите минимальное число: ");
		scanf("%d", &minnum);
	}

    printf("Введите количество знаков после запятой: ");
    scanf("%d", &fnum);

	for (int i = 0; i < fnum; i++) {
    	k1 = k1/10;
		k2 = k2*10;
	}
	
    maxnum *= k2;
	minnum *= k2;

	for (int n = 0; n < A.getlines(); n++) {
		for (int k = 0; k < A.getcolumns(); k++) {
			A.setvalue(n, k, double(rand() % (maxnum - minnum + 1) + minnum)*k1);
		}
	}

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            A.getvalue(i, j, value);
            printf("  %f  ", value);
        }
        printf("\n");
    }


    return 0;
}