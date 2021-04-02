//
// Created by Erica on 3/19/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_CPP
#define LINKEDLIST_LINKEDLIST_CPP

#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
void LinkedList<T>::insertTail(T item)
{
    Node<T>* temp = createNode(item);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

template<class T>
void LinkedList<T>::insertHead(T item)
{
    Node<T>* temp = createNode(item);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head = temp;
    }
}

template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;

    return n;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
    for (Node<T>* walk = list.head; walk != nullptr; walk = walk->next)
    {
        out.width(5);
        out << walk->data;
    }

    return out;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+=(const T& item)
{
    insertTail(item);
    return *this;
}

template<class T>
void LinkedList<T>::insertBefore(T insertThis, Node<T>* beforeThat)
{
 if(beforeThat != nullptr)
    {
        if(head == tail || beforeThat == head)
        {
            insertHead(insertThis);
        }
        else
        {
            Node<T>* node = createNode(insertThis);
            node->next = beforeThat;
            node->prev = beforeThat->prev;
            (beforeThat->prev)->next = node;
            beforeThat->prev = node;
        }
    }



}
//Author: Erica Carballo
template<class T>
void LinkedList<T>::insertAfter(T insertThis, T afterThat)
{
    Node<T>* temp =  find(afterThat);
    if(temp == tail)
    {
        insertTail(insertThis);
    }
   else if(temp != nullptr && temp->next != nullptr)
    {
        insertBefore(insertThis, temp->next);
    }
}

template<class T>
void LinkedList<T>::insertBefore(T insertThis, T beforeThat)
{
        Node<T>* target = find(beforeThat);
        insertBefore(insertThis, target);
}

template<class T>
Node<T>* LinkedList<T>::find(T target)
{
    Node<T>* walker = head;

    while((walker != nullptr) && walker->data != target)
    {
        walker = walker ->next;
    }

    return walker;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    if((head == nullptr) && (tail == nullptr))
    {
        return true;
    }

    return false;
}

template<class T>
int LinkedList<T>::checkSize(const LinkedList<T>& list)
{
    int countItems;

    for (Node<T>* walk = list.head; walk != nullptr; walk = walk->next)
    {
        countItems++;
    }

    return countItems;
}

template<class T>
LinkedList<T>::~LinkedList()
{

    clear();
};

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : LinkedList()
{
    *this = list;

}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
    clear();

    Node<T>* walker = list.head;

    _size = 0;

    while(walker != nullptr)
    {
        insertTail(walker->data);
        walker = walker->next;
    }

    return *this;
}

template<class T>
void LinkedList<T>::clear()
{
    Node<T>* walker = head;
    Node<T>* previous;

    while(walker != nullptr)
    {
        previous = walker;
        walker = walker->next;
        delete previous;
    }

    head = nullptr;
    tail = nullptr;
}

template<class T>
void LinkedList<T>::remove(T removeThis)
{
   // Node<T>* temp =  find(removeThis);

    remove(find(removeThis));


//    if(temp != nullptr)
//    {
//        if(temp == head)
//        {
//            temp->next->prev = nullptr;
//            head = head->next;
//        }
//        else if(temp == tail)
//        {
//            temp->prev->next = nullptr;
//            tail = tail->prev;
//        }
//        else
//        {
//            temp->next->prev = temp->prev;
//            temp->prev->next = temp->next;
//        }
//
//        delete temp;
//    }

}

template<class T>
void LinkedList<T>::remove(Node<T>* target)
{
    if(target != nullptr)
    {
        Node<T>* tprev = target->prev;
        Node<T>* tnext = target->next;
        if(tail == head)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if(target == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
       else if(target == tail)
        {
            tprev->next = nullptr;
            tail = tprev;
        }
        else
        {
            tprev->next = tnext;
            tnext->prev = tprev;


        }
        delete target;
    }
}


#endif //LINKEDLIST_LINKEDLIST_CPP
