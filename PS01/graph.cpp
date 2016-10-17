#include <iostream>
#include <fstream>
#include "graph.hpp"

using namespace std;

Graph::Graph(){}

void Graph::createVertex(string notVertex){
	Node *pushnode = new Node;
	pushnode->addNode(notVertex);
	MASTER.push_back(*pushnode);
}

void Graph::createEdge(string first, string second, double weight){
	int counter = 0;
	for(int i = 0; i < MASTER.size(); i++){
		if( first == MASTER[i].returnName()){
			counter = i;
		}
	}
	int counter2 = 0;
	for(int i = 0; i < MASTER.size(); i++){
		if( second == MASTER[i].returnName()){
			counter2 = i;
		}
	}
	MASTER[counter].addEdge(MASTER[counter2], weight);
	MASTER[counter2].addEdge(MASTER[counter], weight);
}

void Graph::ToGraphViz(string fileName){
	ofstream myfile;
	myfile.open(fileName);
	myfile << "strict graph {" << endl;
	for(int i = 0; i < MASTER.size(); i++){
		for(int j = 0; j < MASTER[i].edgeStore.size(); j++){
			printVertexName(MASTER[i], myfile);
			MASTER[i].printEdges(MASTER[i], j, myfile);
			myfile << endl;
		}
	}
	myfile << "}" << endl;
	myfile.close();
}

void Graph::printVertexName(Node vertexNode, ostream& myfile){
	vertexNode.printVertex(myfile);
}

void Graph::PrimMSTGen(Graph PrimMST){
	string connectingVertex;
	int weightOfConnected, counter = 0;
	connectingVertex = PrimMST.MASTER[0].searchSmallestVertex();
	weightOfConnected = PrimMST.MASTER[0].findWeight();
	createVertex(PrimMST.MASTER[0].vertex);
	createVertex(connectingVertex);
	createEdge(PrimMST.MASTER[0].vertex, connectingVertex, weightOfConnected);

	while(MASTER.size() != PrimMST.MASTER.size()){
		for(int i = 0; i < MASTER.size(); i++){
			for(int j = 0; j < PrimMST.MASTER.size(); j++){
				if(MASTER[i].vertex == PrimMST.MASTER[j].vertex){
						for(int l = 0; l < PrimMST.MASTER[j].edgeStore.size(); l++){
							if(PrimMST.MASTER[j].edgeStore[l].vertex == MASTER[i].vertex){
								PrimMST.MASTER[j].removeReconnectingEdge(l);
							}
						}
					}
				}
			}

		int currentWeight;
		int smallestWeight;
		int secondcounter = 0;
		string nextVertex;
		int connectingEdge;
		for(int i = 0; i < MASTER.size(); i++){
			for(int j = 0; j < PrimMST.MASTER.size(); j++){
				if(MASTER[i].vertex == PrimMST.MASTER[j].vertex){
					connectingVertex = PrimMST.MASTER[j].searchSmallestVertex();
					weightOfConnected = PrimMST.MASTER[j].findWeight();
					currentWeight = weightOfConnected;
					if(secondcounter < 1){
					smallestWeight = weightOfConnected;
					}
					secondcounter++;
				}
			if(currentWeight <= smallestWeight){
				smallestWeight = currentWeight;
				nextVertex = connectingVertex;
				connectingEdge = i;
			}
			}
		}
		createVertex(nextVertex);
		createEdge(MASTER[connectingEdge].vertex, nextVertex, smallestWeight);
		}
}
