

#include "linkedlist.hpp"
using namespace std;

//Constructor for linked list node creates a data point and a single pointer to next object
linkNode::linkNode(string data){
    data_ = data;
    nextNode_ = NULL;
}

//Constructor for a linked list class creates a root node and a tail node
LinkedList:: LinkedList(){
    root_ = NULL;
    tail_ = NULL;
}

//Inserts a new node to the end of a linked list
bool LinkedList:: Insert(string data){
    //empty list make root the start
    if(root_ == NULL){
        root_ = new linkNode(data);
        tail_ = root_;
        return true;
    }
    //tack on a value to the end of the list
    else{
        tail_->nextNode_ = new linkNode(data);
        tail_ = tail_->nextNode_;
        return true;
    }
    return false;
}


//Searches through the list to find a value
bool LinkedList::Search(string data){
    
    bool checkTF = false;
    
    //make sure we start at beginning of the list
    tail_ = root_;
    
    
    while(checkTF != true){
        if(data == tail_->data_){
            cout << "Located: " << data << endl;
            checkTF = true;
            return true;
        }
        else if(tail_->data_ != data && tail_->nextNode_ != NULL){
            
            tail_ = tail_->nextNode_;
            checkTF = false;
        }
    }
    
    cout << "There is no data entry matching: " << data << endl;
    
    return false;
}


//Calls inOrder with a variable passed to it to make it more user friendly
void LinkedList::PrintList(){
    if(root_ != NULL){
        PrintList(tail_);
    }
}


//Prints out all values in linked list
void LinkedList::PrintList(linkNode* tail_){
    cout << tail_->data_ << endl;
    if(tail_->nextNode_ != NULL){
        PrintList(tail_->nextNode_);
    }
}













