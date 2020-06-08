#ifndef NODE_H
#define NODE_H

template<class K, class T>
class Node
{
public:
    K key;
    T value;
    Node *left, *right;
    Node(K k, T v)
    {
        key = k;
        value = v;
        left = right = nullptr;
    }
};

#endif 
