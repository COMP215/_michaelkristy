//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include "binarysearchtree.hpp"
#include "linkedlist.hpp"
#include <fstream>
using namespace std;


int main() {
    
    ifstream myRandomFile ("foowords.txt");
    
    BinarySearchTree* people_names = new BinarySearchTree();
    LinkedList* linked_people_names = new LinkedList();
    
    string line;
    
    cout << "LOADING NAMES INTO BINARY TREE AND LINKED LIST." << endl;
    
    while(getline(myRandomFile, line)){
        people_names->Insert(line);
        linked_people_names->Insert(line);
    }
    
    cout << "DONE." << endl;
    
    myRandomFile.close();
    
    ifstream mySortedFile("words.txt");
    
    cout << "SEARCHING THROUGH BINARY LIST AND LINKED LIST" << endl;
    
    int i = 0;
    
    while(getline(mySortedFile, line)){
        i++;
        people_names->Search(line);
        linked_people_names->Search(line);
    }
    
    cout << "DONE" << endl;
    
    return 0;
}
