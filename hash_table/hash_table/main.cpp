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

    hash_table<int, int> *babbys_first_hash_table = new hash_table<int, int>();
    
    for (int i = 0; i < 10; ++i)
    {
        int random = rand();
        cout << babbys_first_hash_table->hash(random) <<endl;
    }
    
    
    return 0;
}

