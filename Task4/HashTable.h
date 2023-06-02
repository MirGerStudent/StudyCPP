#ifndef TASK4_HASHTABLE_H
#define TASK4_HASHTABLE_H

#include <cstddef>

template <typename T, typename U>
struct HashNode {
    public:
        T key_;
        U data_;
        HashNode<T, U> *next;

        HashNode(const T &key, const U &data) : 
                                                key_{key},
                                                data_{data},
                                                next{nullptr}
                                                {}
        HashNode() :
                    next{nullptr}
                    {}
};

template <typename T, typename U>
class HashTable {
    private:
        HashNode<T, U>* HashArray_;
        size_t size_;
        size_t count_;
    public:
        HashTable(size_t size);
        HashTable(const HashTable<T, U> &cop);
        HashTable(HashTable<T, U> &&cop);
        HashTable();
        ~HashTable();
        void add(const T &key, const U &value);
        void erase(const T &key);
        U search(const T &key) const;
        // U search(T key) const;
        void makeEmpty();
        bool isEmpty() const;
        HashTable<T, U>& operator=(const HashTable<T, U> &hash);
        HashTable<T, U>& operator=(HashTable<T, U> &&hash);
        class HashIterator {
            private:
                HashTable<T, U> *hash_;
                HashNode<T, U> *Curr_;
                size_t N_;
            public:
                HashIterator(HashTable<T, U> &hash, HashNode<T, U> *elem, size_t N);
                HashIterator(HashTable<T, U> &hash);
                HashIterator();
                void start(); 
                HashNode<T, U> *getValue();
                void next(); // ++
                bool finish();
        };
        
};

#endif //TASK4_HASHTABLE_H