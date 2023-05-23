#ifndef TASK3_RINGBUFFERLIST_H
#define TASK3_RINGBUFFERLIST_H

#include "AbstractList.h"
#include "AbstractListIterator.h"

template <typename T>
class RingBufferList : public AbstractList<T> {
    public:
        class ListIterator : public AbstractListIterator<T> {
            protected:
                NodE<T>* Curr;
                RingBufferList<T>* list;
            public: 
                ListIterator(RingBufferList &list, NodE<T> *elem);
                ListIterator(RingBufferList &list);
                ListIterator();
                void start(); 
                NodE<T> *getValue();
                void next(); // ++
                bool finish();

                // ListIterator& operator= (const ListIterator &IT);
                // ListIterator& operator= (ListIterator &&IT);
        };;
        RingBufferList(const RingBufferList<T>& cop);
        RingBufferList(RingBufferList<T> &&cop);
        RingBufferList();
        ~RingBufferList();
        void push(const T &value, AbstractListIterator<T> &it);
        void push_back(const T &value);
        void push_front(const T &value);
        void pop(AbstractListIterator<T> &it);
        void pop_back();
        void pop_front();
        ListIterator& find(T value);
        void makeEmpty();
        bool isEmpty();
        unsigned len();
        ListIterator& getIteratorFirst();
        RingBufferList<T>& operator= (const RingBufferList &list);
        RingBufferList<T>& operator= (RingBufferList &&list);
        void print();
    private:
        NodE<T>* Buff;
        unsigned length = 0;
        
};;;

#endif //TASK3_RINGBUFFERLIST_H