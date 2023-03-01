#include <iostream>
#include "box.h"

int main() {
    box box1 = box(23, 23, 23, 2300, 2300);
    box box2 = box(12, 12, 12, 1200, 1200);
    box Arr[2];
    Arr[0] = box1;
    Arr[1] = box2;

    box box3 = box(5, 5, 5, 0, 500);
    box box4 = box(1, 1, 1, 0, 100);
    box box5 = box(3, 3, 3, 0, 300);
    box box6 = box(4, 4, 4, 0, 400);
    box box7 = box(6, 6, 6, 0, 600);
    box box8 = box(2, 2, 2, 0, 200);

    box box11 = box(1, 1, 1, 0, 100);

    box ArrEmptyBox[6];
    ArrEmptyBox[0] = box8;
    ArrEmptyBox[1] = box7;
    ArrEmptyBox[2] = box6;
    ArrEmptyBox[3] = box3;
    ArrEmptyBox[4] = box4;
    ArrEmptyBox[5] = box5;

    std::cout << SumWeight(Arr, 2) << std::endl;
    std::cout << IdealBoxs(Arr, 2, 40, 40, 40) << std::endl;
    std::cout << MaxWeight(Arr, 2, 12167) << std::endl;
    std::cout << VolumeOneInOne(ArrEmptyBox, 6) << std::endl;

    std::cout << "Operator == " << (box11 == box4) << std::endl;
    std::cout << "Operator << " << box11 << std::endl;

    box box12;
    std::cout << "Operator >> ";
    std::cin >> box12;
    std::cout << "Output box " << box12 << std::endl;

    return 0;
}