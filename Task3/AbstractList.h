#include "AbstractListIterator.h"

template <typename T>

class AbstractList {
    public:
        virtual void push(const T &value, AbstractListIterator &it);
        virtual void pop(AbstractListIterator &it);
        virtual AbstractListIterator& find(T value);
        virtual void makeEmpty();
        virtual bool isEmpty();
        virtual int length();
        virtual AbstractListIterator& getIteratorFirst();
};