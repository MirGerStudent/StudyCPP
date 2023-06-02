#include "HashTable.h"
#include "HashTable.cpp"

int main() {
    // HashTable<char, int> II = (HashTable<char, int>) alloc(sizeof (HashTable<char, int>));
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

    II.print();

    HashTable<char, int>::HashIterator IT(II);
    IT.start();
    while (!IT.finish()) {
        std::cout << IT.getValue()->data_ << std::endl;
        IT.next();
    }
    

    II.makeEmpty();
    return 0;
}