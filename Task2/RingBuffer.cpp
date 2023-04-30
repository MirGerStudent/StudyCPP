#include "MyExeption.cpp"
#include "RingBuffer.h"
#include <iostream>

RingBuffer::RingBuffer() : size(100),
                           head(0), 
                           tail(0), 
                           Array(new int[100]) 
                           {}

RingBuffer::RingBuffer(int size) : size(size), 
                                   head(0), 
                                   tail(0), 
                                   Array(new int[size]) 
                                   {}

RingBuffer::RingBuffer(const RingBuffer &cop) : size(cop.size), 
                                                head(cop.head), 
                                                tail(cop.tail), 
                                                Array(cop.Array)
                                                {}

RingBuffer::~RingBuffer() {
    size = 0;
    head = 0;
    tail = 0;
    delete[] Array;
}

int RingBuffer::length() {
    return size;
}

void RingBuffer::clear() {
    for (int i = 0; i < size; i++) Array[i] = 0;
    head = 0;
    tail = 0;
}

bool RingBuffer::isEmpty() {
    return head == tail;
}

void RingBuffer::push(int value) {
    if((tail+1)%(size+1) == head) {
        throw RingBuffException("Массив полон!");
    }

    try {
        Array[tail] = value;
        tail = (tail+1)%(size+1);
    }
    catch(const RingBuffException &err) {
		std::cerr << err.what() << '\n';
    }
}

int RingBuffer::front() {
    if (isEmpty()) {
        throw RingBuffException("Очередь пуста!");
    }

    try {
        return Array[head];
    }
    catch(const RingBuffException &err) {
        std::cerr << err.what() << '\n';
    }
}

int RingBuffer::get_front() {
    if (isEmpty()) {
        throw RingBuffException("Очередь пуста!");
    }

    try {
        int res = 0;
        res = Array[head];
        head = (head+1)%(size+1);

        return res;
    }
    catch(const RingBuffException &err) {
        std::cerr << err.what() << '\n';
    }   
}

int RingBuffer::get_head() {
    return head;
}

int RingBuffer::get_tail() {
    return tail;
}

// int RingBuffer::operator[] (int index) {
    
// }