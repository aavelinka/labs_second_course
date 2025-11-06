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
    Deque()
    {
        top = nullptr;
        buttom = nullptr;
    };
    ~Deque()
    {
        while(top != nullptr)
        {
            Node<T>* tmp = top;
            top = tmp->prev;
            delete tmp;
        }
    };

    //Node& operator==(Node&); //?????????
    Deque& operator=(Deque& tmp)
    {
        if(this != tmp)
        {
            top = tmp.top;
            buttom = tmp.buttom;
        }

        return *this;
    }
    friend ostream& operator<<(ostream& out, Deque& object)
    {
        out << object.top->item << endl;

        return out;
    }
    friend istream& operator>>(istream& in, Deque& object)
    {
        in >> object.top->item;

        return in;
    }
    void pushFront(T object)
    {
        struct Node<T>* tmp = new Node<T>{object, nullptr, nullptr};
        if(top != nullptr)
        {
            tmp->prev = top;
            tmp->next = nullptr;
            top = tmp;
        } else
        {
            top = buttom = tmp;
        }
    }
    void pushBack(T object)
    {
        struct Node<T>* tmp = new Node<T>{object, nullptr, nullptr};
        if(buttom != nullptr)
        {
            tmp->next = buttom;
            tmp->prev = nullptr;
            buttom = tmp;
        } else
        {
            top = buttom = tmp;
        }
    }
    T popFront()
    {
        if(top == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }
        T object = top->item;
        struct Node<T>* tmp = top;
        top = top->next;
        if(top != nullptr)
        {
            top->prev = nullptr;
        } else 
        {
            buttom = nullptr;
        }

        delete tmp;
        return object;
    }
    T popBack()
    {
        if(buttom == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }
        T object = buttom->item;
        struct Node<T>* tmp = buttom;
        buttom = buttom->prev;
        if(buttom != nullptr)
        {
            buttom->next = nullptr;
        } else 
        {
            top = nullptr;
        }

        delete tmp;
        return object;
    }
    T peekFirst()
    {
        if(top == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }

        return top->item;
    }
    T peekLast()
    {
        if(buttom == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }

        return buttom->item;
    }
    bool isEmpty()
    {
        return top == nullptr && buttom == nullptr;
    }
};