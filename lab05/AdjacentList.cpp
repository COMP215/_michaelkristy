//
//  AdjacentList.cpp
//  lab05
//
//  Created by Michael Kristy on 9/27/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include "AdjacentList.hpp"
using namespace std;

AdjacentList::AdjacentList(){
    
}

void AdjacentList::InsertData(string vertex){
    Node *createVertex = new Node;
    createVertex->CreateNode(vertex);
    nodeVector.push_back(*createVertex);
}

void AdjacentList::MakeEdge(int vec_Posistion_Representation1, int vec_Posistion_Representation2){
    nodeVector[vec_Posistion_Representation1].AssignPointer(nodeVector[vec_Posistion_Representation2]);
}

bool AdjacentList::IsBipartite(){
    int temp_set;
    cout << "What is your first set?" << endl << "(Enter number, press enter to add a new one, type -1 then enter to end)" << endl;
    while(temp_set != -1){
        cin >> temp_set;
        if (temp_set != -1){
            set_one.push_back(temp_set);
        }
        else{
            cout << "Done." << endl;
        }
    }
    
    temp_set = 0;
    
    cout << "What is your second set?" << endl << "(Enter number, press enter to add a new one, type -1 then enter to end)" << endl;
    while(temp_set != -1){
        cin >> temp_set;
        if (temp_set != -1){
            set_two.push_back(temp_set);
        }
        else{
            cout << "Done." << endl;
        }
    }
    
    for(int i = 0; i < set_one.size(); i++){
        for(int j = 0; j < nodeVector[set_one[i+1]].nodePointerVector.size(); j++){
            if(nodeVector[set_one[i+1]].vertex == nodeVector[set_one[i+1]].nodePointerVector[j+1].vertex){
                cout << "This graph is not bipartite." << endl;
                return false;
            }

        }
        for(int j = 0; j < nodeVector[set_two[i+1]].nodePointerVector.size(); j++){
            if(nodeVector[set_two[i+1]].vertex == nodeVector[set_two[i+1]].nodePointerVector[j+1].vertex){
                cout << "This graph is not bipartite." << endl;
                return false;
            }
        }

}
    cout << "This graph is bipartite!" << endl;
        return false;
}
