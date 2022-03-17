#include <iostream>
#include <fstream>

void average_among10(std::ifstream &data, int &err, double &result);
 
int main() {
    char filename[256];
    int error = 0;
    double result = 0;

    printf("Введите название файла (с расширением) - ");
  	scanf("%s", filename);
    std::ifstream data(filename);

    average_among10(data, error, result);
    if (error == 0) printf("Успешно!\nСредняя длинна идентификатора - %f", result);
    if (error == -1) printf("ERROR: Файл пуст!");
    if (error == -2) printf("ERROR: Поток файла не открыт!");

    if (data.is_open()) data.close();

    return 0;
}

void average_among10(std::ifstream &data, int &err, double &result) {
    char str;
    
    double average_amount = 0;

    int count = 0;
    int length = 0;
    int count_av = 0;

    bool lett = false;
    bool numb = false;
    bool sumb = false;
    bool prev = false; //previous character
    
    char letters[52] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char sumbols[31] = {',', '.', '/', '|', '!', '@', '#', '$', '%', '^', '&', '?', '*', '(', ')', '[', ']', '{', '}', '<', '>', ':', ';', '`', '"', '_', '~', '+', '-', '+', '='};

    if (!data.is_open()) err = -2;
    else {
        while (data.get(str)) {
            //std::cout << str;
            count++;
            for (int i = 0; i < 52; i++){
                if (str == letters[i]) {
                    lett = true;
                }
            }
            for (int i = 0; i < 10; i++){
                if (str == numbers[i]) {
                    numb = true;
                }
            }
            for (int i = 0; i < 31; i++){
                if (str == sumbols[i]) {
                    sumb = true;
                }
            }
            
            if (prev) {
                if (lett || numb) {
                    length++;
                } else {
                    length++;
                    //std::cout << " " << length << std::endl;
                    average_amount = average_amount + length;
                    length = 0;
                    count_av++;
                    prev = false;
                }
            }
            
            if (lett) {
                prev = true;
            }

            lett = false; numb = false; sumb = false;
        }  if (count == 0) err = -1;
        if (count != 0) {
            if (length != 0) {
            length++;
            //std::cout << " " << length << std::endl;
            average_amount = average_amount + length;
            length = 0;
            count_av++;
            }
            result = average_amount / count_av;
        }
    }
    //printf("\ncount - %d, average among - %f", count, average_amount);
    data.close();
}
