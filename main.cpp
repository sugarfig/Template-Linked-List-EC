//Author: Erica Carballo
//Project name: Template Linked List
//Description: Program that creates a linked list, where you can add or remove items.
//Last Changed: March 21, 2021

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> l;

    for (int i = 0; i < 10; i++)
    {
        l+=i;
    }
    std::cout << "This is the linked list:" << std::endl << l <<std::endl;

    l.insertAfter(65, 5);
    std::cout << "This is the linked list after inserting a 65 after 5: " << std::endl << l << std::endl;

    l.insertBefore(32, 8);
    std::cout << "This is the linked list after inserting a 32 before 8: " << std::endl << l << std::endl;

    l.remove(6);
    std::cout << "This is the linked list after removing 6 from the list: " << std::endl << l <<std::endl;

    l.insertHead(28);
    std::cout << "This is the linked list after adding 28 to the head: " << std::endl << l << std::endl;

    l.insertTail(26);
    std::cout << "This is the linked list after adding 26 to the tail: " << std::endl << l << std::endl;
//Author: Erica Carballo
    l.insertAfter(10, 26);
    std::cout << "This is the linked list after adding 10 after the last number in the list: " << std::endl << l << std::endl;

    l.insertBefore(81, 28);
    std::cout << "This is the linked list after adding 81 before the first number in the list: " << std::endl << l << std::endl;

//more testing:
//    LinkedList<int> list;
//    list.insertTail(2); // list = 2
//
//    list += 3; // list = 2 3
//
//    list.insertHead(4); // list = 4 2 3
//
//    std::cout << list; // prints 4 2 3

//    LinkedList<int> l;
//    l.insertTail(5);
//    l.insertTail(8);
//    l.insertTail(9);
//
//    std::cout << l << std::endl;

    return 0;
}