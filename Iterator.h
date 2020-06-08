#ifndef ITERATOR_H
#define ITERATOR_H
#include "DoublyLinkedList.h"
const int SIZE = 107;

template<class K, class T>
class Iterator{
private:
    DoublyLinkedList<K, T>* table;
    int index;
    Node<K,T>* curr;
public:
    Iterator(DoublyLinkedList<K, T>* table):table(table),index(0){
        curr = table[0].begin();
    };

    Iterator begin(){
        return Iterator(table);
    }

    Iterator end(){
        auto it = Iterator(table);
        it.index = SIZE;
        curr = nullptr;
    }

    Iterator operator++(){
        if(curr != nullptr)
            curr = curr->right;
        if (curr == nullptr){
            index++;
            if(index < SIZE){
                curr = table[index].begin();
            }
        }
        return *this;
    }
    Iterator operator++(int){
        auto tmp = *this;
        ++(*this);
        return tmp;
    }
    pair<K,T> operator*(){
        return make_pair(curr->key,curr->value);
    }

};

#endif 
