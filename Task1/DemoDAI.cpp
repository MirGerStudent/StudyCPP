#include "Dynamic_array_of_integers.h"
// #include <iostream>

int main() {
    int size = 0;
    int number = 0;

    std::cout << "Constructor from size\n" << "Input DAI(Arr1) size: ";
    std::cin >> size;

    ArrayList Arr1 = ArrayList(size);
    std::cout << "cout for DAI(Arr1)\n" << Arr1;

    std::cout << "Defult constructor DAI(Arr2)" << std::endl;
    ArrayList Arr2 = ArrayList();
    std::cout << "Cin for DAI(Arr2) ";
    std::cin >> Arr2;

    std::cout << "cout for DAI(Arr2)\n" << Arr2;

    std::cout << "Constructor by size and nomber\n" << "Input DAI(Arr3) size: ";
    std::cin >> size;
    std::cout << "Input DAI(Arr3) number: " << std::endl;
    std::cin >> number;

    ArrayList Arr3 = ArrayList(size, number);
    std::cout << "cout for DAI(Arr3)\n" << Arr3;

    std::cout << "Constructor copy\n" << "Copy DAI(Arr3) in DAI(Arr4)" << std::endl;
    // ArrayList Arr4 = ArrayList(Arr3);
    ArrayList Arr4 = std::move(Arr3);
    std::cout << "cout for DAI(Arr3)\n" << Arr3;
    std::cout << "cout for DAI(Arr4)\n" << Arr4;

    std::cout << "\n<--- Tests mothods --->\n";

    std::cout << "Arr4 == Arr3 " << (Arr4 == Arr3) << std::endl;
    std::cout << "Arr4 != Arr2 " << (Arr4 != Arr2) << std::endl;

    ArrayList Arr5 = Arr4 + Arr2;
    std::cout << "Arr4 + Arr2 " << Arr5 << std::endl;

    std::cout << " " << std::endl;

    for (int i = 0; i < Arr2.length(); i++) {
        std::cout << "Input " << i << " element: " << std::endl;
        std::cin >> Arr2[i];
    }

    std::cout << "Arr4 < Arr3 " << (Arr4 < Arr3) << std::endl;
    std::cout << "Arr4 > Arr3 " << (Arr4 > Arr3) << std::endl;
    std::cout << "Arr4 >= Arr3 " << (Arr4 >= Arr3) << std::endl;
    std::cout << "Arr4 <= Arr3 " << (Arr4 <= Arr3) << std::endl;

    

    return 0;
}