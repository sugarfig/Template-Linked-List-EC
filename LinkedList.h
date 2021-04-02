//
// Created by Erica on 3/19/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(T item);
    void insertBefore(T insertThis, Node<T>* beforeThat);
    int _size = 0;
    Node<T>* find(T target);
    void remove(Node<T>* target);

public:
    LinkedList();
    void insertTail(T item);//inserts at end of list
    void insertHead(T item);//inserts at beginning of list
    template <class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);//overloaded insertion operator
    LinkedList<T>& operator+=(const T& item);//overloaded +=
    //Author: Erica Carballo
    void insertBefore(T insertThis, T beforeThat);//insert in middle
    void insertAfter(T insertThis, T afterThat);//insert in middle
    bool isEmpty();//checks empty
    int checkSize(const LinkedList<T>& list);//checks size
    ~LinkedList();//destructor
    LinkedList(const LinkedList<T>& list);
    LinkedList<T>& operator=(const LinkedList<T>& list);//assignment operator
    void clear();//clear list
    void remove(T removeThis);//removes an item

};

#include "LinkedList.cpp"
#endif //LINKEDLIST_LINKEDLIST_H
