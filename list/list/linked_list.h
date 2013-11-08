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
#include <iterator>

//namespace algorithms
//{
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

    class list_iterator: public std::iterator<std::forward_iterator_tag, T>
    {
    public:
        
        list_iterator(list_node<T> *n) : current_node(n) { };
        list_iterator(const list_iterator &iter) : current_node(iter.current_node) {};
        list_iterator &operator++() { current_node = current_node->next; return *this; }
        list_iterator operator++(int) { list_iterator tmp(*this); operator++(); return tmp; }
        T &operator*() const { return current_node->data; }
        T *operator->() const { return &current_node->data; }
        bool operator==(const list_iterator rhs) { return (current_node->data == rhs.current_node.data); }
        bool operator!=(const list_iterator &rhs) { return (current_node->data != rhs.current_node->data); }
        
    private:
        list_node<T> *current_node;
    };
    
    linked_list();
    void insert(const T data);
    void remove(const T data);
    list_iterator begin() { return list_iterator(head); }
    list_iterator end()   { return list_iterator(tail); }
    ~linked_list();
private:
    list_node<T> *head;
    list_node<T> *tail;
    int size;
    
    // unused copy/assignment
    linked_list(const linked_list<T> &);
    linked_list &operator=(const linked_list<T> &);
};
    
template <typename T> linked_list<T>::linked_list()
    : head(NULL), tail(NULL), size(0)
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
        tail = head;
    }
    else
    {
        auto *it = head;
        while (it->next)
        {
            it = it->next;
        }
        it->next = new list_node<T>(data);
        tail = it->next;
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
                
                if (it->next == tail)
                {
                    tail = it;
                }
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

/*
template <typename T>
class list_iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:

    list_iterator(list_node<T> *n) : current_node(n) { };
    list_iterator(const list_iterator<T> &iter) : current_node(iter.current_node) {};
    list_iterator &operator++() { current_node = current_node->next; return *this; }
    list_iterator operator++(int) { list_iterator tmp(*this); operator++(); }
    T &operator*() const { return current_node->data; }
    T *operator->() const { return &current_node->data; }
    bool operator==(list_iterator rhs) const { return (current_node->data == rhs.data); }
    bool operator!=(list_iterator rhs) const {return (current_node->data != rhs.data); }
    
private:
    list_node<T> *current_node;
};
*/
    
//} // namespace algorithms
#endif /* defined(__list__linked_list__) */
