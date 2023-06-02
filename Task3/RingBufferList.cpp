#include "RingBufferList.h"
#include "AbstractList.h"
#include "RBLExeption.cpp"
#include <iostream>

template <typename T>
RingBufferList<T>::RingBufferList() : Buff{nullptr}, length{0} {
    NodE<T> *newNodE = new NodE<T>();
    Buff = newNodE;
    Buff->next = Buff;
    Buff->prev = Buff;
}

template <typename T>
RingBufferList<T>::RingBufferList(const RingBufferList<T>& cop) : Buff{nullptr}, length{cop.length} {
    NodE<T> *newNodE = new NodE<T>();
    Buff = newNodE;
    Buff->next = Buff;
    Buff->prev = Buff;

    NodE<T> *NowElem = cop.Buff->next;
    NodE<T> *Curr = Buff;

    while (NowElem != cop.Buff) {
        push_back(NowElem->Data);
        NodE<T> *newElem = new NodE<T>(NowElem->Data);
        Curr->next = newElem;
        newElem->prev = Curr;

        Curr = Curr->next;
        NowElem = NowElem->next;
    }

    Buff->prev = Curr;
    Curr->next = Buff;

    NowElem = nullptr;
    Curr = nullptr;
    delete Curr;
    delete NowElem;
}

template <typename T>
RingBufferList<T>::RingBufferList(RingBufferList<T> &&cop) : Buff{nullptr}, length{cop.length} {
    Buff = cop.Buff;
    length = cop.length;
    cop.Buff = nullptr;
    cop.length = 0;
}

template <typename T>
RingBufferList<T>::~RingBufferList() {
    makeEmpty();
    delete Buff;
}

template <typename T>
RingBufferList<T>::ListIterator::ListIterator(RingBufferList<T> &List, NodE<T> *node) : Curr{node}, list{(&List)} {}

template <typename T>
RingBufferList<T>::ListIterator::ListIterator(RingBufferList<T> &List) : Curr{List.Buff->next}, list{(&List)} {}

template <typename T>
RingBufferList<T>::ListIterator::ListIterator() : Curr{nullptr}, list{nullptr} {}

template <typename T>
void RingBufferList<T>::ListIterator::start() {
    Curr = list->Buff->next;
}

template <typename T>
NodE<T> *RingBufferList<T>::ListIterator::getValue() {
    return Curr;
}

template <typename T>
void RingBufferList<T>::ListIterator::next() {
    Curr = Curr->next;
}

template <typename T>
bool RingBufferList<T>::ListIterator::finish() {
    return Curr == list->Buff;
}

template <typename T> 
void RingBufferList<T>::push(const T &value, AbstractListIterator<T> &it) {
    NodE<T> *newElem = new NodE<T>(value);
    it.getValue()->next->prev = newElem;
    newElem->next = it.getValue()->next;
    it.getValue()->next = newElem;
    newElem->prev = it.getValue();
    length++;
}

template <typename T>
void RingBufferList<T>::push_back(const T &value) {
    NodE<T> *newElem = new NodE<T>(value);
    newElem->next = Buff;
    newElem->prev = Buff->prev;
    Buff->prev->next = newElem;
    Buff->prev = newElem;
    length++;
}

template <typename T>
void RingBufferList<T>::push_front(const T &value) {
    NodE<T> *newElem = new NodE<T>(value);
    Buff->next->prev = newElem;
    newElem->next = Buff->next;
    Buff->next = newElem;
    newElem->prev = Buff;
    length++;
}

template <typename T> 
void RingBufferList<T>::pop(AbstractListIterator<T> &it) {
    if (it.getValue()->next == Buff) {
        throw RingBuffException("Список пуст!");
    }

    try {
        NodE<T>* elem = it.getValue();
        it.getValue()->prev->next = elem->next;
        elem->next->prev = it.getValue()->prev;
        delete elem;
        length--;
    }
    catch(const RingBuffException& err) {
        std::cerr << err.what() << '\n';
    }
}

template <typename T>
void RingBufferList<T>::pop_back() {
    if (isEmpty()) {
        throw RingBuffException("Список пуст!");
    }
    try {
        NodE<T>* elem = Buff->prev;
        Buff->prev = elem->prev;
        elem->prev->next = Buff;
        delete elem;
        length--;
    } catch (const RingBuffException& err) {
        std::cerr << err.what() << "\n";
    }
}

template <typename T>
void RingBufferList<T>::pop_front() {
    if (isEmpty()) {
        throw RingBuffException("Список пуст!");
    }
    try {
        NodE<T>* elem = Buff->next;
        Buff->next = elem->next;
        elem->next->prev = Buff;
        delete elem;
        length--;
    } catch (const RingBuffException& err) {
        std::cerr << err.what() << "\n";
    }
}

template <typename T> 
void RingBufferList<T>::print() {
    NodE<T> *elem = Buff->next;
    while (elem != Buff) {
        std::cout << elem->Data << " ";
        elem = elem->next;
    }   
}

template <typename T>
typename RingBufferList<T>::ListIterator& RingBufferList<T>::find(T value) {
    if (isEmpty()) {
        throw RingBuffException("Очередь пустая!");
    }

    try {
        NodE<T> *elem = Buff->next;
        ListIterator *newIterator;
        while (elem != Buff) {
            if (elem->Data == value) {
                newIterator = new ListIterator((*this), elem);
                return *newIterator;
            }
            elem = elem->next;
        }

        newIterator = new ListIterator((*this));
        return *newIterator;
    } catch(const RingBuffException &err) {
        std::cerr << err.what() << "\n";
    }
}

template <typename T>
void RingBufferList<T>::makeEmpty() {
    while (!isEmpty()) {
        NodE<T>* elem = Buff->next;
        Buff->next = elem->next;
        elem->next->prev = Buff;
        delete elem;
    }
}

template <typename T>
RingBufferList<T> &RingBufferList<T>::operator=(const RingBufferList &list) {
    if (this != &list) {
        if (!isEmpty()) {
            makeEmpty();
        }
        delete Buff;

        Buff = new NodE<T>(0);
        NodE<T> *NowElem = list.Buff->next;

        while (NowElem != list.Buff) {
            push_back(NowElem->Data);
            NowElem = NowElem->next;
        }
        NowElem = nullptr;
        delete NowElem;
    }
    return (*this);
}

template <typename T>
RingBufferList<T> &RingBufferList<T>::operator=(RingBufferList &&list) {
    if (this != &list) {
        if (!isEmpty()) {
            makeEmpty();
        }
        delete Buff;
        Buff = list.Buff;
        length = list.length;
        list.Buff = nullptr;
        list.length = 0;
    }

    return (*this);
}

template <typename T>
bool RingBufferList<T>::isEmpty() {
    return (Buff->next == Buff) && (Buff->prev == Buff);
}

template <typename T>
unsigned RingBufferList<T>::len() {
    return length;
}

template <typename T>
typename RingBufferList<T>::ListIterator& RingBufferList<T>::getIteratorFirst() {
    ListIterator *newListIterator = new ListIterator((*this));
    
    return *newListIterator;
}