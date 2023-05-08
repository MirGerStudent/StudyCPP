#include "AbstractList.h"
#include "ListIterator.h"
// #include "node.cpp"

template <typename T> struct node {
    int *next;
    int *prev;
    T Data;

    node(const T& value) : Data(value) {}
};

template <typename T>

class RingBufferList : public AbstractList {
    private:
        node<T> Buff;
        length = 0;
    public:
        RingBufferList();
        ~RingBufferList();
        void push(const T &value, ListIterator<T> &it);
        void pop(ListIterator<T> &it);
        ListIterator<T>& find(T value);
        void makeEmpty();
        bool isEmpty();
        int length();
        ListIterator<T>& getIteratorFirst();
};;;