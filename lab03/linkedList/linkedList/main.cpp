//
//  main.cpp
//  linkedList
//
//  Created by Michael Kristy on 9/12/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include <iostream>
#include <random>
#include <time.h>
using namespace std;


class node
{
public:
    node();
    double num_data_entry;
    node *pointer_to_next;
};

node :: node (){
    num_data_entry = 0;
    pointer_to_next = 0;
}

class linkedList
{
public:
    linkedList();
    void addNode ();
    void printList();
    node buffer;
    node *last_posistion;
    int counter = 0;
};

linkedList :: linkedList (){
    node *head;
    head = &buffer;
    last_posistion = &buffer;
}

void linkedList :: addNode (){
    
    node *added_node = new node;
    this->last_posistion->pointer_to_next = added_node;
    added_node->num_data_entry = rand() % 10;
    this->last_posistion = added_node;
    counter++;
}

void linkedList :: printList (){
    node *working_pos;
    working_pos = buffer.pointer_to_next;
    for(int i = 0; i < counter; i++){
        cout << working_pos->num_data_entry << endl;;
        working_pos = working_pos->pointer_to_next;
    }
}

int main(int argc, const char * argv[]) {
    srand (time(NULL));
    linkedList test;
    
    for(int i = 0; i < 1000; i++)
    {
        test.addNode();
    }
    
    test.printList();
    
    return 0;
}