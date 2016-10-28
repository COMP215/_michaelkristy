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

string Node::searchSmallestVertex(vector<Node>ignoreVector){
	int new_Val, vector_Location = 0, smallest_value_initialize_counter = 0, smallest_Val, used_edge = 0;
	if(ignoreVector.size() > 0){
		for(int i = 0; i < edgeWeight.size(); i++){
			used_edge = 0;
			for(int j = 0; j < ignoreVector.size(); j++){
				if(edgeStore[i].vertex == ignoreVector[j].vertex){
					used_edge++;
				}
			}
			if(used_edge == 0 && smallest_value_initialize_counter == 0){
				smallest_Val = edgeWeight[i];
				new_Val = edgeWeight[i];
				smallest_value_initialize_counter++;
			}
			if(used_edge == 0 && smallest_value_initialize_counter != 0){
				new_Val = edgeWeight[i];
				if(new_Val <= smallest_Val){
					smallest_Val = new_Val;
					vector_Location = i;
				}
			}
		}
	}
	else{
		for(int i = 0; i < edgeWeight.size(); i++){
			if(smallest_value_initialize_counter == 0){
				smallest_Val = edgeWeight[i];
			}
			new_Val = edgeWeight[i];
			smallest_value_initialize_counter++;
			if(new_Val <= smallest_Val){
				smallest_Val = new_Val;
				vector_Location = i;
			}
		}
			smallest_value_initialize_counter = 0;
	}
    string hold_Name = edgeStore[vector_Location].vertex;
return hold_Name;
}

int Node::findWeight(vector<Node>ignoreVector){
	int new_Val, vector_Location = 0, smallest_value_initialize_counter = 0, smallest_Val, used_edge = 0, noEdgeLeft = 0;
	if(ignoreVector.size() > 0){
		for(int i = 0; i < edgeWeight.size(); i++){
			used_edge = 0;
			for(int j = 0; j < ignoreVector.size(); j++){
				if(edgeStore[i].vertex == ignoreVector[j].vertex){
					used_edge++;
				}
			}
			if(used_edge == 0 && smallest_value_initialize_counter == 0){
				smallest_Val = edgeWeight[i];
				new_Val = edgeWeight[i];
				smallest_value_initialize_counter++;
				noEdgeLeft++;
			}
			if(used_edge == 0 && smallest_value_initialize_counter != 0){
				new_Val = edgeWeight[i];
				if(new_Val <= smallest_Val){
					smallest_Val = new_Val;
					vector_Location = i;
					noEdgeLeft++;
				}
			}
		}
	}
	else{
		for(int i = 0; i < edgeWeight.size(); i++){
			if(smallest_value_initialize_counter == 0){
				smallest_Val = edgeWeight[i];
				noEdgeLeft++;
			}
			new_Val = edgeWeight[i];
			smallest_value_initialize_counter++;
			if(new_Val <= smallest_Val){
				smallest_Val = new_Val;
				vector_Location = i;
				noEdgeLeft++;
			}
		}
		smallest_value_initialize_counter = 0;
	}
	if(noEdgeLeft == 0){
		smallest_Val = 100000000;
	}
	return smallest_Val;
}
