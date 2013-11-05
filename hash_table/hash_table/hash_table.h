//
//  hash_table.h
//  hash_table
//
//  Created by John Lukasiewicz on 11/3/13.
//  Copyright (c) 2013 John Lukasiewicz. All rights reserved.
//

#ifndef hash_table_hash_table_h
#define hash_table_hash_table_h

#include <utility>
#include "linked_list.h"

using namespace algorithms;

template <typename K, typename V>
class hash_table
{
public:
    hash_table(int size);
    int hash(V value);
private:
    linked_list<std::pair<K,V> > *hash_lists;
};

#endif

template<typename K, typename V> hash_table<K,V>::hash_table(int size)
{
    hash_lists = new linked_list< std::pair<K,V> >[size];
}

template<typename K, typename V> int hash_table<K, V>::hash(V value)
{
    int sum = 0;
    int result = 0;
    char *ptr = static_cast<char *>(value);
    return result;
}