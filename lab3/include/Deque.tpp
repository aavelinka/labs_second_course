#pragma once

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& otherDeque)
    {
        if(this != &otherDeque)
        {
            while(top != nullptr)
            {
                Node<T>* tmp = top;
                top = top->next;
                delete tmp;
            }
            top = nullptr;
            buttom = nullptr;
            Node<T>* tmp = otherDeque.top;
            while(tmp != nullptr)
            {
                pushBack(tmp->item);
                tmp = tmp->next;
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
        Node<T>* tmp = top;
        while(tmp != nullptr)
        {
            count++;
            tmp = tmp->next;
        }

        return count;
    }

    template <typename T>
    Deque<T> Deque<T>::search(T key)
    {
        Deque<T> result;
        Node<T>* tmp = top;
        while(tmp != nullptr)
        {
            if(*tmp->item == *key)
            {
                result.pushBack(tmp->item);
            }
            tmp = tmp->next;
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
            Node<T>* current = top;
            while(current != nullptr && current->next != nullptr)
            {
                if(*current->next->item < *current->item)
                {
                    T temp = current->item;
                    current->item = current->next->item;
                    current->next->item = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while(swapped);
    }
    
    template <typename T>
    void Deque<T>::clear()
    {
        while(top != nullptr)
        {
            Node<T>* tmp = top;
            top = top->next;
            delete tmp;
        }
        buttom = nullptr;
    }
    
    template <typename T>
    Node<T>* Deque<T>::getTop() const
    {
        return top;
    }