#include "IteratorRingBuff.h"
#include <iostream>

int main() {
    RingBuffer Q = RingBuffer(5);
    
    for (int i = 0; i < 5; i++) {
        Q.push(i);
    }

    // Q.push(8);
    for (int i = 0; i < 5; i++) {
        std::cout << Q.get_front() << std::endl;
    }
    for (int i = 0; i < 3; i++) {
        Q.push(i);
    }
    // std::cout << Q.get_front() << std::endl;
    // std::cout << Q.get_front() << std::endl;
    // std::cout << Q.get_front() << std::endl;
    // std::cout << Q.get_front() << std::endl;


    // Q.push(9);
    std::cout << "Head: " << Q.get_head() << std::endl;
    std::cout << "Tail: " << Q.get_tail() << std::endl;

    Q.push(8);
    Q.push(7);
    IteratorRingBuff NewQ = IteratorRingBuff(Q);
    NewQ.start();
    while (!NewQ.finish()) {
        std::cout << NewQ.getValue() << " ";
        NewQ.next();
    }

    return 0;
}