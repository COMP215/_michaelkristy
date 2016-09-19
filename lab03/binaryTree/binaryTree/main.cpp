//
//  main.cpp
//  binaryTree
//
//  Created by Michael Kristy on 9/14/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include <iostream>

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
    double num_data_entry;        //value in node
    node *pointer_to_greater;     //pointer to a greater value than the node
    node *pointer_to_lesser;      //pointer ot a lesser value than the node
    
};

node :: node (){
    this->num_data_entry = NULL;         //setting value in node to NULL
    this->pointer_to_greater = NULL;      //setting the pointer value to NULL
    this->pointer_to_lesser = NULL;       //setting the pointer value to NULL
}

class linkedList
{
public:
    linkedList();       //constructor
    node *head;        //start of a tree
    node base_node;     //first node to head
    node *last_posistion;     //hold previous posistion
    node *curr_posistion;      //keep current posisiton
    void printTree(node &head);   //print out tree
    void startPrintTree();       //start the print tree
    void addNode (int passed_var);    //add node to end of the tree
    bool checkTree_value;        //used to cut while loop
    bool checkTree(int passed_var, node* alpha_node);       //finds end of tree
    int counter = 0;
};

linkedList :: linkedList (){
    head = &base_node;
    last_posistion = &base_node;
    curr_posistion = &base_node;
}

void linkedList :: addNode (int passed_var){
    node *alpha_node = new node;
    alpha_node->num_data_entry = passed_var;
    
    if(base_node.pointer_to_lesser == NULL && base_node.pointer_to_greater == NULL){
        base_node.num_data_entry = 0;
    }
    
    while(checkTree_value == false)  //While the value passed is smaller then the one in curr_position
    {
        checkTree_value = checkTree(passed_var, alpha_node);
}
    
}

bool linkedList :: checkTree(int passed_var, node *alpha_node){
    
    alpha_node->num_data_entry = passed_var;
    
    if(passed_var < last_posistion->num_data_entry)
        {
            if(curr_posistion->pointer_to_lesser == NULL){
                cout << "HI1" << endl;
                curr_posistion->pointer_to_lesser = alpha_node;
                return true;
            }
            else
                curr_posistion = curr_posistion->pointer_to_lesser;
                return false;
        }
        
        else if(passed_var > last_posistion->num_data_entry){
            if(curr_posistion->pointer_to_greater == NULL){
                curr_posistion->pointer_to_greater = alpha_node;
                return true;
            }
            else
                curr_posistion = curr_posistion->pointer_to_greater;
                return false;
        }
    else
        cout << "HI6" << endl;
        return false;
}

void linkedList :: printTree(node &head)    //Danny helped with this code
{
    if(head.num_data_entry == 0){
        cout << "The tree is empty."  << endl;
    }
    else if(head.pointer_to_greater == NULL && head.pointer_to_lesser == NULL){
        cout << head.num_data_entry << endl;
        }
    else
    {
        if (head.pointer_to_lesser != NULL)
        {
            printTree(*head.pointer_to_lesser);
            cout << head.pointer_to_lesser << endl;
        }
        else {
            cout << head.num_data_entry << endl;
        }
        if(head.pointer_to_greater != NULL){
            printTree(*head.pointer_to_greater);
        }
    }
}


void linkedList :: startPrintTree(){
    node *start = new node();
    start = head;
    printTree(*head);
}

int main(int argc, const char * argv[]) {
    linkedList test;
    int randNum;
    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        randNum = rand() % 25;
        test.addNode(randNum);
    }
    
    test.startPrintTree();

}

