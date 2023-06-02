#include "HashTable.h"
#include "HashTable.cpp"

int main() {
    HashTable<char, int> II(5);

    II.add('K', 98);
    II.add('G', 30);
    II.add('D', 17);
    II.add('F', 12389);
    II.add('R', 192398);
    II.add('W', 240); //
    II.add('Q', 919);
    II.add('T', 728);
    II.add('L', 900);
    II.add('X', 600);
    II.add('I', 976);
    II.add('B', 20);
    II.add('C', 76);

    HashTable<char, int>::HashIterator IT(II);
    IT.start();
    while (!IT.finish()) {
        std::cout << IT.getValue()->data_ << " ";
        IT.next();
    }
    std::cout << std::endl;

    II.erase('R');

    std::cout << "\n\n" << std::endl;

    IT.start();
    while (!IT.finish()) {
        std::cout << IT.getValue()->data_ << " ";
        IT.next();
    }

    std::cout << "\n\n" << std::endl;

    std::cout << II.search('K') << std::endl;

    II.makeEmpty();
    return 0;
}