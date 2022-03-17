#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    int change_numbers = 0, change_letters = 0, change_sumbols = 0, change_margins = 0;
    const int count_numbers = 10, count_letters = 52, count_sumbols = 31, count_margins = 2;
    int now_number = 100;
    int change = 0;
    int count = -99;
    int count_x = 0;

    char filename[256];
    srand(time(0));

    char margins[2] = {' ', '\n'};
    char letters[52] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char sumbols[31] = {',', '.', '/', '|', '!', '@', '#', '$', '%', '^', '&', '?', '*', '(', ')', '[', ']', '{', '}', '<', '>', ':', ';', '`', '"', '_', '~', '+', '-', '+', '='};

    printf("Генератор файлов 3.0 v\n\n");
    printf("Введите название файла (с расширением) - ");
    scanf("%s", filename);
    std::ofstream data(filename);

    printf("Заполнение файла %s\n\n", filename);

    while (count < 0) {
        printf("Введите колличество элементов для заполнения файлов (не меньше 1, иначе файл будет пустой) - ");
        scanf("%d", &count);
    }

    if (count == 0) printf("Файл %s - пустой!", filename);
    else {
        while ((change_letters <= 0) || (change_letters >= now_number)) {
            printf("Введите число вероятности выпадения букв (в процентах от 0 до %d) - ", now_number);
            scanf("%d", &change_letters);
        }
        now_number = now_number - change_letters;

        while ((change_numbers <= 0) || (change_numbers > now_number)) {
            printf("Введите число вероятности выпадения чисел (в процентах от 0 до %d) - ", now_number);
            scanf("%d", &change_numbers);
        }
        now_number = now_number - change_numbers;

        while ((change_sumbols <= 0) || (change_sumbols > now_number)) {
            printf("Введите число вероятности выпадения символов (в процентах от 0 до %d) - ", now_number);
            scanf("%d", &change_sumbols);
        }
        now_number = now_number - change_sumbols;

        while ((change_margins <= 0) || (change_margins > now_number)) {
            printf("Введите число вероятности выпадения пробела или перехода (в процентах от 0 до %d) - ", now_number);
            scanf("%d", &change_margins);
        }
        now_number = now_number - change_margins;



        while (count_x != count) {
            change = rand() % 101;
            if ((0 <= change) && ( change < change_letters)) {
                data << letters[rand() % count_letters];
            } else
            if ((change_letters <= change) && (change < change_letters + change_numbers)) {
                data << numbers[rand() % count_numbers];
            } else
            if ((change_letters + change_numbers <= change) && (change < change_letters + change_numbers + change_sumbols)) {
                data << sumbols[rand() % count_sumbols];
            } else
            if ((change_letters + change_numbers + change_sumbols <= change) && (change <= 100)) {
                data << margins[rand() % count_margins];
            }   
            count_x++;     
        }

        printf("Файл был успешно создан!");
        data.close();
    }

    return 0;
}