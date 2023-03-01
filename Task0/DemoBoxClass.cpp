#include <iostream>
#include "Container.h"

int main() {
    Box Box1 = Box(23, 23, 23, 2300, 2300);
    Box Box2 = Box(12, 12, 12, 1200, 1200);
    Box Arr[2];
    Arr[0] = Box1;
    Arr[1] = Box2;

    Box Box3 = Box(5, 5, 5, 0, 500);
    Box Box4 = Box(1, 1, 1, 0, 100);
    Box Box5 = Box(3, 3, 3, 0, 300);
    Box Box6 = Box(4, 4, 4, 0, 400);
    Box Box7 = Box(6, 6, 6, 0, 600);
    Box Box8 = Box(2, 2, 2, 0, 200);

    Box Box11 = Box(1, 1, 1, 0, 100);

    Box ArrEmptyBox[6];
    ArrEmptyBox[0] = Box8;
    ArrEmptyBox[1] = Box7;
    ArrEmptyBox[2] = Box6;
    ArrEmptyBox[3] = Box3;
    ArrEmptyBox[4] = Box4;
    ArrEmptyBox[5] = Box5;

    std::cout << SumWeight(Arr, 2) << std::endl;
    std::cout << IdealBoxs(Arr, 2, 40, 40, 40) << std::endl;
    std::cout << MaxWeight(Arr, 2, 12167) << std::endl;
    std::cout << VolumeOneInOne(ArrEmptyBox, 6) << std::endl;

    std::cout << "Operator == " << (Box11 == Box4) << std::endl;
    std::cout << "Operator << " << Box11 << std::endl;

    Box Box12;
    std::cout << "Operator >> ";
    std::cin >> Box12;
    std::cout << "Output Box " << Box12 << std::endl;

    Container CC = Container(20, 20, 20, 300.90);
    CC.addBox(Box12);
    CC.addBox(Box11);
    std::cout << CC.containerWeight() << std::endl;

    
    return 0;
}