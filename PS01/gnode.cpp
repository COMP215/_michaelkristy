#include <fstream>
#include "graph.hpp"

using namespace std;

Node::Node(){}

void Node::addNode(string VertexVal) {
	vertex = VertexVal;
}

void Node::addEdge(Node passedNode,double weight) {
	edgeStore.push_back(passedNode);
	edgeWeight.push_back(weight);
}

void Node::printVertex(ostream& myfile){
	myfile << "	" << vertex << " -- ";
}

void Node::printEdges(Node passedNode, int move, ostream& myfile){
	myfile << passedNode.edgeStore[move].vertex;
}

string Node::returnName(){
	return vertex;
}

string Node::searchSmallestVertex(){
	int newVal, counter = 0, smallestVal = edgeWeight[0];
	for(int i = 0; i < edgeWeight.size(); i++){
		newVal = edgeWeight[i];
		if(newVal <= smallestVal){
			smallestVal = newVal;
			counter = i;
		}
	}
    string holdName = edgeStore[counter].vertex;
    tempEdgeHolder.clear();
    for(int i = 0; i < edgeStore.size(); i++){
        if(i != counter){
            tempEdgeHolder.push_back(edgeStore[i]);
        }
    }
    edgeStore.swap(tempEdgeHolder);
return holdName;
}

int Node::findWeight(){
	for(int j = 0; j < edgeWeight.size(); j++){
		cout << edgeWeight[j] << endl;
	}
		int newVal, counter = 0, smallestVal = edgeWeight[0];
		for(int i = 0; i < edgeWeight.size(); i++){
			newVal = edgeWeight[i];
			if(newVal < smallestVal){
				smallestVal = newVal;
				counter = i;
			}
		}
    tempEdgeWeightHolder.clear();
    for(int i = 0; i < edgeWeight.size(); i++){
        if(i != counter){
            tempEdgeWeightHolder.push_back(edgeWeight[i]);
        }
    }
    edgeWeight.swap(tempEdgeWeightHolder);
		//cout << "SMALLEST VAL: " << smallestVal << endl;
	return smallestVal;
}

void Node::removeReconnectingEdge(int removeVal){

    tempEdgeHolder.clear();
    for(int i = 0; i < edgeStore.size(); i++){
        if(i != removeVal){
            tempEdgeHolder.push_back(edgeStore[i]);
        }
    }
    edgeStore.swap(tempEdgeHolder);

    tempEdgeWeightHolder.clear();
    for(int i = 0; i < edgeWeight.size(); i++){
        if(i != removeVal){
            tempEdgeWeightHolder.push_back(edgeWeight[i]);
        }
    }
    edgeWeight.swap(tempEdgeWeightHolder);


}
