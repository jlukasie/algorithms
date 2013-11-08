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

#define DEFAULT_HASH_SIZE 2000
#define DEFAULT_DIVISOR 701
//using namespace algorithms;

template <typename K, typename V>
class hash_table
{
public:
    hash_table();
    hash_table(int size);
    int hash(K  key);
    int hash(K* key);
    void insert(K key, V value);
    std::pair<K, V> find(K key);
    
    class proxy
    {
    public:
        proxy(hash_table<K, V> &h, K key) : h(h), key(key){}
        
        operator V() const
        {
            
        }
        
        proxy &operator=(V const &value)
        {
            h.insert(key, value);
            return *this;
        }
    private:
        hash_table<K, V> &h;
        K key;
    };
    
private:
    linked_list<std::pair<K,V> > *hash_lists;
};

#endif

template<typename K, typename V> hash_table<K,V>::hash_table()
{
    hash_lists = new linked_list< std::pair<K,V> >[DEFAULT_HASH_SIZE];
}

template<typename K, typename V> hash_table<K,V>::hash_table(int size)
{
    hash_lists = new linked_list< std::pair<K,V> >[size];
}

template<typename K, typename V> std::pair<K, V> hash_table<K,V>::find(K key)
{
    int index = hash(key);
    auto list_ptr = hash_lists[index];
}

template<typename K, typename V> int hash_table<K, V>::hash(K key)
{
    int sum = 0;
    int result = 0;
    size_t size = sizeof(K);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(&key);
    
    // sum up raw data
    for (int i = 0; i < size; ++i)
    {
        sum += *ptr;
        ptr++;
    }
    
    // divide by prime num (~3 entries per list for 2000 buckets)
    result = sum %DEFAULT_DIVISOR;
    
    return result;
}

template<typename K, typename V> int hash_table<K, V>::hash(K* key)
{
    int sum = 0;
    int result = 0;
    size_t size = sizeof(K);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(key);
    
    // sum up raw data
    for (int i = 0; i < size; ++i)
    {
        sum += *ptr;
        ptr++;
    }
    
    // divide by prime num (~3 entries per list for 2000 buckets)
    result = sum %DEFAULT_DIVISOR;
    
    return result;
}