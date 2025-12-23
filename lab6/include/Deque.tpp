#pragma once
#include "Deque.hpp"

template <typename T>
Deque<T>::Deque(const Deque<T>& other)
{
    top = nullptr;
    buttom = nullptr;
    for (Iterator it = other.begin(); it != other.end(); ++it)
    {
        pushBack(*it);
    }
}

template <typename T>
Deque<T>::~Deque()
{
    clear();
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& otherDeque)
    {
        if(this != &otherDeque)
        {
            clear();
            for (Iterator it = otherDeque.begin(); it != otherDeque.end(); ++it)
            {
                pushBack(*it);
            }
        }
        return *this;
    }

    template <typename T>
    ostream& operator<<(ostream& out, Deque<T>& object)
    {
        out << object.top->item << endl;

        return out;
    }

    template <typename T>
    istream& operator>>(istream& in, Deque<T>& object)
    {
        in >> object.top->item;

        return in;
    }

    template <typename T>
    void Deque<T>::pushFront(T object)
    {
        struct Node<T>* tmp = new Node<T>{object, nullptr, nullptr};
        if(top != nullptr)
        {
            tmp->next = top;
            top->prev = tmp;
            top = tmp;
        } else
        {
            top = buttom = tmp;
        }
    }

    template <typename T>
    void Deque<T>::pushBack(T object)
    {
        struct Node<T>* tmp = new Node<T>{object, nullptr, nullptr};
        if(buttom != nullptr)
        {
            tmp->prev = buttom;
            buttom->next = tmp;
            buttom = tmp;
        } else
        {
            top = buttom = tmp;
        }
    }

    template <typename T>
    T Deque<T>::popFront()
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

    template <typename T>
    T Deque<T>::popBack()
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

    template <typename T>
    T Deque<T>::peekFirst()
    {
        if(top == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }

        return top->item;
    }

    template <typename T>
    T Deque<T>::peekLast()
    {
        if(buttom == nullptr)
        {
            cout << "Deque is empty!" << endl;
            return nullptr;
        }

        return buttom->item;
    }

    template <typename T>
    bool Deque<T>::isEmpty()
    {
        return top == nullptr && buttom == nullptr;
    }
    
    template <typename T>
    int Deque<T>::size()
    {
        int count = 0;
        for (Iterator it = begin(); it != end(); ++it)
        {
            count++;
        }

        return count;
    }

    template <typename T>
    Deque<T> Deque<T>::search(T key)
    {
        Deque<T> result;
        for (Iterator it = begin(); it != end(); ++it)
        {
            if(**it == *key)
            {
                result.pushBack(*it);
            }
        }

        return result;
    }
    
    template <typename T>
    void Deque<T>::sort()
    {
        if(top == nullptr || top == buttom)
        {
            return;
        }
        
        bool swapped;
        do
        {
            swapped = false;
            for (Iterator current = begin(); current != end(); ++current)
            {
                Iterator next = current;
                ++next;
                if (next == end())
                {
                    break;
                }

                if(**next < **current)
                {
                    T temp = *current;
                    *current = *next;
                    *next = temp;
                    swapped = true;
                }
            }
        } while(swapped);
    }
    
    template <typename T>
    void Deque<T>::clear()
    {
        for (Iterator it = begin(); it != end(); )
        {
            Iterator current = it;
            ++it;
            delete current.getNode();
        }
        buttom = nullptr;
        top = nullptr;
    }
    
    template <typename T>
    Node<T>* Deque<T>::getTop() const
    {
        return top;
    }
