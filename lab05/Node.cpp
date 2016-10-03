//
//  Node.cpp
//  lab05
//
//  Created by Michael Kristy on 9/27/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include "AdjacentList.hpp"
using namespace std;

Node::Node(){

}

void Node::CreateNode(string addedVertex){
    vertex = addedVertex;
}

void Node::AssignPointer(Node newVector){
    nodePointerVector.push_back(newVector);
}

//void Node::PrintVector(){
//    cout << nodePointerVector[1].vertex << endl;
//}
