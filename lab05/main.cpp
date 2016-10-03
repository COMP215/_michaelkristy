//
//  main.cpp
//  lab05
//
//  Created by Michael Kristy on 9/27/16.
//  Copyright © 2016 Michael Kristy. All rights reserved.
//

#include <iostream>
#include "AdjacentList.hpp"


//Use insert data to create vector points on the graph. When a new vector point is created it gets a numerical value
// ie. 0,1,2,3,4...etc use those numerical values to create an edge
int main() {
    
    AdjacentList graph;
    graph.InsertData("Max");
    graph.InsertData("Michael");
    graph.InsertData("Armweak");
    graph.InsertData("Flousie");
    graph.InsertData("LeDahnkyDanhnk");
    graph.InsertData("Gahbay");
    graph.MakeEdge(0,1);
    graph.MakeEdge(1,2);
    graph.MakeEdge(2,3);
    graph.MakeEdge(3,4);
    graph.MakeEdge(4,5);
    graph.MakeEdge(5,0);
    graph.MakeEdge(0,3);
    
    graph.IsBipartite();
    
    
    
    return 0;
}


//bool IsBipartitle() returns true and false depending on if graph is Bipartite
