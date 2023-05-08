#include "AbstractListIterator.h"

template <typename T>

class ListIterator : public AbstractListIterator {
    private:
    public: 
        node<T> current;
        void start();
        T& getValue();
        void next();
        bool finish();
};