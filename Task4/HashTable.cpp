#include "HashTable.h"
#include "HashException.h"
#include <iostream>
#include <unordered_map>

template <typename T, typename U>
HashTable<T, U>::HashTable(size_t size) : 
                                                HashArray_{nullptr}, 
                                                size_{size},
                                                count_{0} {
    HashArray_ = new HashNode<T, U>[size_];
    for (size_t i = 0; i < size_; i++) HashArray_[i].HashNode<T, U>::next = nullptr;
}

template <typename T, typename U>
HashTable<T, U>::HashTable() : 
                                HashArray_{nullptr}, 
                                size_{17}, 
                                count_{0} {
    HashArray_ = new HashNode<T, U>[size_];
    for (size_t i = 0; i < size_; i++) HashArray_[i]->HashNode<T, U>::next = nullptr;
}

template <typename T, typename U>
HashTable<T, U>::~HashTable() {
    makeEmpty();
    
    size_ = 0;
    count_ = 0;

    delete[] HashArray_;
}

template<class T, class U>
void HashTable<T, U>::add(const T &key, const U &value) {
    size_t index = std::hash<T>()(key) % size_;

    if (HashArray_[index].next == nullptr) {
        HashNode<T, U> *newNode = new HashNode<T, U>(key, value);
        HashArray_[index].next = newNode;
        count_++;
        // std::cout << "OK" << std::endl;
    } else {
        HashNode<T, U> *newNode = &HashArray_[index];
        do {
            newNode = newNode->next;
        } 
        while (newNode->next != nullptr);
        HashNode<T, U> *newElem = new HashNode<T, U>(key, value);
        newNode->next = newElem;
        count_++;
        // std::cout << "OK+" << std::endl;
    }
}

template<class T, class U>
void HashTable<T, U>::erase(const T &key) {
    size_t index = std::hash<T>()(key) % size_;
    
    HashNode<T, U> *it = &HashArray_[index];
    while (it->next->key_ != key) {
        it = it->next;
    }
    HashNode<T, U> *temp = it->next;
    it->next=temp->next;
    delete temp;
    count_--;
}

template<class T, class U>
U HashTable<T, U>::search(const T &key) const {
    size_t index = std::hash<T>()(key) % size_;

    HashNode<T, U> *res = &HashArray_[index];
    while (res->key_ != key) {
        res = res->next;
    }

    if (res == nullptr) throw HashException("Елемент с таким ключём не найден!");

    try {
        return res->data_;
    } catch (const HashException &err) {
        std::cerr << err.what() << "\n";
    }
}

template<class T, class U>
void HashTable<T, U>::makeEmpty() {
    for (size_t i = 0; i < size_; i++) {
        if (HashArray_[i].next != nullptr) {
            HashNode<T, U> *newNode = new HashNode<T, U>();
            HashArray_[i].next = newNode;

            while(newNode->next != nullptr) {
                HashNode<T, U> *currNode = new HashNode<T, U>();
                currNode = newNode;
                newNode = newNode->next;
                delete currNode;
            }
            delete newNode;
        }
    }

    size_ = 0;
    count_ = 0;
}

template<class T, class U>
bool HashTable<T, U>::isEmpty() const {
    return count_ == 0;
}

template<class T, class U>
HashTable<T, U> &HashTable<T, U>::operator=(const HashTable<T, U> &hash) {
    if (!isEmpty()) {
        makeEmpty();
    }

    this->count_ = hash.count_;
    this->size_ = hash.size_;
    HashArray_ = new HashNode<T, U>[size_];

    for (size_t i = 0; i < size_; i++) {
        if (hash.HashArray_[i].next != nullptr) {
            HashNode<T, U> *nowNode = new HashNode<T, U>();
            HashNode<T, U> *firstNode = new HashNode<T, U>();
            
            nowNode = hash.HashArray_[i].next;
            HashArray_[i].next = firstNode;

            while (nowNode != nullptr) {
                HashNode<T, U> *newNode = new HashNode<T, U>();
                newNode->data_ = nowNode->data_;
                newNode->key_ = nowNode->key_;
                
            }
        }
        
    }

    return (*this);
}

template<typename T, typename U>
HashTable<T, U> &HashTable<T, U>::operator=(HashTable<T, U> &&hash) {


    // return (*this);
}

template<typename T, typename U>
HashTable<T, U>::HashIterator::HashIterator(HashTable<T, U> &hash, HashNode<T, U> *elem, size_t N) :
                                                                                            hash_{(&hash)},
                                                                                            Curr_{elem},
                                                                                            N_{N}
                                                                                            {}

template<typename T, typename U>
HashTable<T, U>::HashIterator::HashIterator(HashTable<T, U> &hash) :
                                                                    hash_{(&hash)},
                                                                    Curr_{nullptr},
                                                                    N_{0}
                                                                    {
    if (!hash_->isEmpty()) {
        while (hash_->HashArray_[N_].next == nullptr) {N_++;}
        Curr_ = hash_->HashArray_[N_].next;
    }
}

template<typename T, typename U>
HashTable<T, U>::HashIterator::HashIterator() :
                                                hash_{nullptr},
                                                Curr_{nullptr},
                                                N_{0}
                                                {}

template<typename T, typename U>
void HashTable<T, U>::HashIterator::start() {
    if (hash_->isEmpty()) {
        throw HashException("Таблица пустая!");
    }

    try {
        N_ = 0;
        while (hash_->HashArray_[N_].next == nullptr) {N_++;}
        Curr_ = hash_->HashArray_[N_].next;
    } catch (const HashException &err) {
        std::cerr << err.what() << "\n";
    } 
}

template<typename T, typename U>
HashNode<T, U> *HashTable<T, U>::HashIterator::getValue() {
    if (Curr_ == nullptr) {
        throw HashException("Итерируемый элемент не задан!");
    }

    try {
        return Curr_;
    } catch (const HashException &err) {
        std::cerr << err.what() << "\n";
    }
}

template<typename T, typename U>
void HashTable<T, U>::HashIterator::next() {
    if (Curr_->next != nullptr) {
        Curr_ = Curr_->next;
    } else {
        N_++;
        while (hash_->HashArray_[N_].next == nullptr) {
            if (N_ < hash_->size_) {
                ++N_;
            } else { 
                start();
            }
        }
        Curr_ = hash_->HashArray_[N_].next;
    }
}

template<typename T, typename U>
bool HashTable<T, U>::HashIterator::finish() {
    if (hash_->isEmpty()) {
        throw HashException("Таблица пустая! Xe");
    }

    try {
        size_t N = (hash_->size_)-1;
        while (hash_->HashArray_[N].next == nullptr) {
            N--;
        }

        HashNode<T, U> *GoodElem = new HashNode<T, U>();
        GoodElem = hash_->HashArray_[N].next;

        if (GoodElem != nullptr) {
            while (GoodElem->next != nullptr) {
                GoodElem = GoodElem->next;
            }
        }
        return Curr_ == GoodElem;    
    } catch (const HashException &err) {
        std::cerr << err.what() << "\n";
    }
}
