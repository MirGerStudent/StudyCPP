#ifndef TASK3_ABSTRACTLISTITERATOR_H
#define TASK3_ABSTRACTLISTITERATOR_H

template <typename T>
struct NodE {
    NodE<T> *next;
    NodE<T> *prev;
    T Data;

    NodE(T value) : Data(value) {}
    NodE() {}
};

template <typename T>
class AbstractListIterator {
    public:
        virtual void start() = 0;
        virtual NodE<T>* getValue() = 0;
        virtual void next() = 0;
        virtual bool finish() = 0;
};

#endif //TASK3_ABSTRACTLISTITERATOR_H