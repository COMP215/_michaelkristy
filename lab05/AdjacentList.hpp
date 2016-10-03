//
//  AdjacentList.hpp
//  lab05
//
//  Created by Michael Kristy on 9/27/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#ifndef AdjacentList_hpp
#define AdjacentList_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

class Node {

protected:
    
public:
    Node();
    std::vector<Node> nodePointerVector;
    void CreateNode(std::string addVertex);
    void AssignPointer(Node newVector);
    void PrintVector();
    std::string vertex;
};

class AdjacentList {
protected:
    std::vector<int> set_one;
    std::vector<int> set_two;
    std::vector<Node> nodeVector;
    
public:
    AdjacentList();
    void InsertData(std::string vertexName);
    void MakeEdge(int vec_Posistion_Representation1, int vec_Posistion_Representation2);
    bool IsBipartite();
};

#endif /* AdjacentList_hpp */
