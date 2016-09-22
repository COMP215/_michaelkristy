//
//  binarysearchtree.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "binarysearchtree.hpp"
#include <string>

using namespace std;

Node::Node(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new Node(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        Node* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new Node(data);
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new Node(data);
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;
}

bool BinarySearchTree:: Search(string data){
    
    bool cutWhile = false;
    Node* look_through_tree = root_;
    
    while(cutWhile != true){
        //if equal print out that we found the location
        if(data == look_through_tree->data_){
            cout << "We found: " << look_through_tree->data_ << endl;
            cutWhile = true;
            return true;
        }
        //advance right if the value is greater
        else if(data > look_through_tree->data_ && look_through_tree->right_ != NULL){
            look_through_tree = look_through_tree->right_;
            cutWhile = false;
        }
        //advance left if the value is less
        else if(data < look_through_tree->data_ && look_through_tree->left_ != NULL){
            look_through_tree = look_through_tree->left_;
            cutWhile = false;
        }
    }

        //uh oh
        cout << "Data Entry Not Found" << endl;
    return false;
}

void BinarySearchTree::InOrder(){
    if(root_ != NULL){
        InOrder(root_);
    }
}

void BinarySearchTree::InOrder(Node* node) {
    if(node->left_ != NULL){
        InOrder(node->left_);
    }
    cout << node->data_ << endl;
    if(node->right_ != NULL){
        InOrder(node->right_);
    }
}


































