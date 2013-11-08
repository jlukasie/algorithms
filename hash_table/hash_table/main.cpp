//
//  main.cpp
//  hash_table
//
//  Created by John Lukasiewicz on 11/2/13.
//  Copyright (c) 2013 John Lukasiewicz. All rights reserved.
//

#include <iostream>
#include "hash_table.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    linked_list<int> my_list;
    my_list.insert(10);
    my_list.insert(20);
    my_list.insert(30);
    my_list.insert(40);
    my_list.insert(50);
    my_list.insert(60);
    my_list.insert(70);
    
    linked_list<int>::list_iterator iter = my_list.begin();
    iter++;
    
    for (auto &iter : my_list)
    {
        cout <<iter <<endl;
    }

    hash_table<int, int> *babbys_first_hash_table = new hash_table<int, int>();
    
    for (int i = 0; i < 10; ++i)
    {
        int random = rand();
        cout << babbys_first_hash_table->hash(random) <<endl;
    }
    
    
    return 0;
}

