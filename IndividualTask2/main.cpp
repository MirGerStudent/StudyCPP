#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int x, int y) {
        lines = x;
        columns = y;
        matrixarr = new double*[lines];
		for (int i = 0; i < lines; i++) {
        	matrixarr[i] = new double[columns];
        }
    }

int main() {
    int x = 0, y = 0;
    int fnum, maxnum=0, minnum = 1, k2=1;
    double elem, k1=1;  

    while (x <= 0){
        std::cout << "Input lines - " << std::endl;
        std::cin >> x;
    }
    while (y <= 0) {
        std::cout << "Input columns - " << std::endl;
        std::cin >> y;
    }
    Matrix A = Matrix(x, y);

    while (minnum > maxnum) {
	    		printf("Введите значенния min < max, учтите что это целые числа!\n");
	    		printf("Введите максимальное число: ");
	    		scanf("%d", &maxnum);
	    		printf("Введите минимальное число: ");
	    		scanf("%d", &minnum);
	      }

	      printf("Введите количество знаков после запятой: ");
	      scanf("%d", &fnum);

				Table[value].arr = new double*[Table[value].lines];

        for (int i = 0; i < Table[value].lines; i++) {
          Table[value].arr[i] = new double[Table[value].columns];
        }

					for (int i = 0; i < fnum; i++) {
						k1 = k1/10;
						k2 = k2*10;
					}
					maxnum *= k2;
					minnum *= k2;

					for (int n = 0; n < Table[value].lines; n++) {
						for (int k = 0; k < Table[value].columns; k++) {
							Table[value].arr[n][k] = double(rand() % (maxnum - minnum + 1) + minnum)*k1;
						}
					}

    return 0;
}