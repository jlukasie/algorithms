//
//  linked_list.h
//  list
//
//  Created by John Lukasiewicz on 11/2/13.
//  Copyright (c) 2013 John Lukasiewicz. All rights reserved.
//

#ifndef __list__linked_list__
#define __list__linked_list__

#include <iostream>

namespace algorithms
{
// node for simple singly linked list
template <typename T>
class list_node
{
// less typing accessors
template <typename U> friend class linked_list;
public:
    list_node(T data);
    T getData();
private:
    T data;
    list_node *next;
};
    
template <typename T>
list_node<T>::list_node(T inData)
    : data(inData), next(NULL)
{
}
   
template <typename T>
T list_node<T>::getData()
{
    return data;
}

// simple singly linked list designed for use in a hash table
template <typename T>
class linked_list
{
public:
    linked_list();
    void insert(const T data);
    void remove(const T data);
    ~linked_list();
private:
    list_node<T> *head;
    
    // unused copy/assignment
    linked_list(const linked_list<T> &);
    linked_list &operator=(const linked_list<T> &);
};
    
template <typename T> linked_list<T>::linked_list()
    : head(NULL)
{
}
    
template <typename T> linked_list<T>::~linked_list()
{
    auto *it = head;
    
    while(it)
    {
        auto *temp = it;
        it = it->next;
        delete temp;
    }
    
    head = NULL;
}
    
template <typename T> void linked_list<T>::insert(const T data)
{
    // null case
    if (!head)
    {
        head = new list_node<T>(data);
    }
    else
    {
        auto *it = head;
        while (it->next)
        {
            it = it->next;
        }
        it->next = new list_node<T>(data);
    }
}
    
template <typename T> void linked_list<T>::remove(const T data)
{
    // find the node and delete it
    auto *it = head;
    
    // first one
    if (it->data == data)
    {
        head = it->next;
        delete it;
    }
    else
    {
        while(it->next)
        {
            if (it->next->data == data)
            {
                auto *temp = it->next;
                it->next = temp->next;
                delete temp;
                break;
            }
            else
            {
                it = it->next;
            }
        }
    }
}
    
} // namespace algorithms
#endif /* defined(__list__linked_list__) */
