#include <iostream>
#include <string>
#include "RingBufferList.h"
#include "RingBufferList.cpp"

int main() {
    std::cout << "Создали первый список" << std::endl;
    RingBufferList<int> I = RingBufferList<int>();

    std::cout << "Проверка на пустоту" << I.isEmpty() << std::endl;

    I.push_back(7);
    I.push_back(8);
    I.push_back(9);
    I.push_front(6);    
    
    std::cout << "Создаём итератор и проходим по первому списку (циклом while)" << std::endl;
    RingBufferList<int>::ListIterator II = RingBufferList<int>::ListIterator(I);

    while (!II.finish()) {
        std::cout << II.getValue()->Data << " ";
        II.next();
    }
    std::cout << std::endl;

    std::cout << "Ставим итератор для первой очереди в начало" << std::endl;
    II = I.getIteratorFirst();

    std::cout << "Проходим по первому списку и добавляем 12 к каждому элементу (циклом while)" << std::endl;
    while (!II.finish()) {
        II.getValue()->Data += 12;
        std::cout << II.getValue()->Data << " ";
        II.next();
    }
    std::cout << std::endl;

    std::cout << "Создаём новый список копируя первый " << std::endl;
    RingBufferList<int>* J = new RingBufferList<int>(I);

    std::cout << "Итерируемся по новому списку к каждому элементу прибавляя 2 (циклом for) " << std::endl;
    for (RingBufferList<int>::ListIterator JJ = RingBufferList<int>::ListIterator(*J); !JJ.finish(); JJ.next()) {
        JJ.getValue()->Data += 2;
        std::cout << JJ.getValue()->Data << "|";
    }
    std::cout << std::endl;

    std::cout << "Удаляем из первого списка первый и последний элементы " << std::endl;
    I.pop_front();
    I.pop_back();
    I.print();
    std::cout << std::endl;

    std::cout << "Создаём список на string" << std::endl;

    RingBufferList<std::string> StrList = RingBufferList<std::string>();

    std::string s1 = std::string("Hello!");
    std::string s2 = std::string("How are you?");
    std::string s3 = std::string("My dear friend.");

    StrList.push_front(s1);

    RingBufferList<std::string>::ListIterator StrIT = RingBufferList<std::string>::ListIterator(StrList);

    StrList.push_back(s2);
    StrList.push(s3, StrIT);
    StrIT.next();
    StrList.push("Jon.", StrIT);
    StrIT.next();
    StrIT.next();

    RingBufferList<std::string>::ListIterator StrR = StrList.getIteratorFirst();

    while (!StrR.finish()) {
        std::cout << StrR.getValue()->Data << " ";
        StrR.next();
    }
    StrR = StrList.find("Jon.");
    StrList.pop(StrR);
    StrR.start();

    std::cout << std::endl;

    while (!StrR.finish()) {
        std::cout << StrR.getValue()->Data << " ";
        StrR.next();
    }

    return 0;
}