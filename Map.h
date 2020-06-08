#ifndef MAP_H
#define MAP_H
#include <utility>
#include <typeinfo>
#include <string>
#include "Node.h"
#include "DoublyLinkedList.h"
using namespace std;
const int SIZE = 107;

template<class K, class T>
class Map
{
private:
    DoublyLinkedList<K, T> table[SIZE];

    int hash(int k)
    {
        return k % SIZE;
    }
    int hash(string k)
    {
        int sum = 0;
        for (auto c: k)
        {
            sum += static_cast<int>(c);
        }
        return sum % SIZE;
    }
public:
    T * search(K k)
    {
        int hashKey = hash(k);
        auto pos = table[hashKey].search(k);
        if(pos == nullptr){
            return nullptr;
        }
        return &pos->value;
    }
    pair<T *, bool> insert(K k, T v)
    {
        int hashKey = hash(k);
        return table[hashKey].insert(k, v);
    }
    void remove(int k)
    {
        int hashKey = hash(k);
        table[hashKey].remove(k);
    }
    T & operator[](K &k)
    {
        if (search(k) == nullptr)
        {
            T* v = new T();
            insert(k, *v);
        }
        return *search(k);
    }

};


#endif 
