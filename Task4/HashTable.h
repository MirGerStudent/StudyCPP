#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <cstddef>

template <typename T, typename U>
struct HashNode {
    public:
        T key_;
        U data_;
        HashNode<T, U> *next;
        HashNode<T, U> *prev;

        HashNode(const T &key, const U &data) : 
                                                key_{key},
                                                data_{data},
                                                next{nullptr},
                                                prev{nullptr}
                                                {}
};

template <typename T, typename U>
class HashTable {
    private:
        HashNode<T, U>* HashArray_;
        size_t size_;
        size_t count_;
    public:
        HashTable(unsigned int size);
        HashTable();
        ~HashTable();
        void add(const T &key, const U &value);
        void erase(const T &key);
        U search(const T &key) const;
        U& search(const T &key);
        void makeEmpty();
        bool isEmpty() const;
};

#endif //TASK4_HASHTABLE_H