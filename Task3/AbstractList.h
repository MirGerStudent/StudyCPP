#ifndef TASK3_ABSTRACTLIST_H
#define TASK3_ABSTRACTLIST_H

#include "AbstractListIterator.h"

template <typename T>
class AbstractList {
    public:
        virtual void push(const T &value, AbstractListIterator<T> &it) = 0;
        virtual void pop(AbstractListIterator<T> &it) = 0;
        virtual AbstractListIterator<T>& find(T value) = 0;
        virtual void makeEmpty() = 0;
        virtual bool isEmpty() = 0;
        virtual unsigned len() = 0;
        virtual AbstractListIterator<T>& getIteratorFirst() = 0;
};;

#endif //TASK3_ABSTRACTLIST_H