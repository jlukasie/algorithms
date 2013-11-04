//
//  main.cpp
//  list
//
//  Created by John Lukasiewicz on 11/2/13.
//  Copyright (c) 2013 John Lukasiewicz. All rights reserved.
//

#include <iostream>
#include "linked_list.h"

using namespace algorithms;
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
    
    my_list.remove(40);
    my_list.remove(10);
    my_list.remove(34);
    return 0;
}

