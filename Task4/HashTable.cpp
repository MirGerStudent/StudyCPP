#include "HashTable.h"
#include <functional>

template <typename T, typename U>
HashTable<T, U>::HashTable(unsigned int size) : 
                                                HashArray_{nullptr}, 
                                                size_{size}, 
                                                count_{0} {
    HashNode<T, U> *newArr = new HashNode<T, U>(size);
    HashArray_ = newArr;
    newArr = nullptr;
    delete newArr;

    for (size_t i = 0; i < 0; i++) HashArray_[i] = nullptr;
}

template<class T, class U>
void HashTable<T, U>::add(const T &key, const U &value) {
    size_t index = std::hash(key) % size_;

    if (HashArray_[index] == nullptr) {
        HashNode<T, U> * newNode = new HashNode<T, U>(key, value);
        HashArray_[index] = newNode;
    } else {
        while (HashArray_[index] != nullptr) {
            HashArray_[index] = HashArray_[index].next;
        }
    }
}

template<class T, class U>
void HashTable<T, U>::erase(const T &key) {

}

template<class T, class U>
U HashTable<T, U>::search(const T &key) const {

}

template<class T, class U>
U &HashTable<T, U>::search(const T &key) {

}


template<class T, class U>
void HashTable<T, U>::makeEmpty() {

}

template<class T, class U>
bool HashTable<T, U>::isEmpty() const {

}
