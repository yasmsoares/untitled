#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <utility>
#include "Node.h"
using namespace std;

template<class K, class T>
class DoublyLinkedList
{
private:
    Node<K, T> *head;
public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    Node<K, T> *search(K k)
    {
        Node<K, T> *curr = head;
        while (curr != nullptr)
        {
            if (curr->key == k)
                return curr;
            curr = curr->right;
        }
        return nullptr;
    }
    pair<T *, bool> insert(K k, T v)
    {
        if (search(k) != nullptr)
            return pair<T *, bool>(&search(k)->value, false);
        else
        {
            Node<K, T> *node = new Node(k, v);
            if (head == nullptr)
                head = node;
            else
            {
                node->right = head;
                head = node;
                node->right->left = node;
            }
            return pair<T *, bool>(&node->value, true);
        }
    }
    void remove(K k)
    {
        Node<K, T> *node = search(k);
        if (node == head)
            head = node->right;
        else
            node->left->right = node->right;
        if (node->right != nullptr)
            node->right->left = node->left;
        delete node;
    }
    Node<K,T>* begin(){
        return head;
    }
};

#endif 
