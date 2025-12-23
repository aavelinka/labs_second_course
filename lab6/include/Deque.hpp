#pragma once

#include <iostream>
#include<iomanip>
using namespace std;

template <typename T>
struct Node
{
    T item;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class Deque
{
private:
    Node<T>* top;
    Node<T>* buttom;

public:
    class Iterator
    {
    private:
        Node<T>* current;
        
    public:
        Iterator(Node<T>* node = nullptr) : current(node) {}

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }

        Iterator& operator++()
        {
            if (current)
            {
                current = current->next;
            }
            return *this;
        }

        Iterator& operator--()
        {
            if (current)
            {
                current = current->prev;
            }
            return *this;
        }

        T& operator*() const { return current->item; }
        T* operator->() const { return &(current->item); }
        Node<T>* getNode() const { return current; }
    };
    Deque()
    {
        top = nullptr;
        buttom = nullptr;
    };
    Deque(const Deque& other);
    ~Deque();

    Deque& operator=(const Deque& otherDeque);
    friend ostream& operator<<(ostream& out, Deque& object);
    friend istream& operator>>(istream& in, Deque& object);

    void pushFront(T object);
    void pushBack(T object);
    T popFront();
    T popBack();
    T peekFirst();
    T peekLast();
    bool isEmpty();
    
    int size();
    Deque<T> search(T key);
    void sort();
    void clear();
    Node<T>* getTop() const;
    Iterator begin() const { return Iterator(top); }
    Iterator end() const { return Iterator(nullptr); }
};

#include "Deque.tpp"
