#include <iostream>
#include <fstream>
#include "graph.hpp"

using namespace std;

Graph::Graph(){}

void Graph::createVertex(string vertex_name){
	Node *new_node = new Node;
	new_node->addNode(vertex_name);
	verticies_in_graph.push_back(*new_node);
}

void Graph::createEdge(string first_vertex_name, string second_vertex_name, double weight){
	int connecting_Vertex = 0;
	for(int i = 0; i < verticies_in_graph.size(); i++){
		if(first_vertex_name == verticies_in_graph[i].returnName()){
			connecting_Vertex = i;
		}
	}
	int connecting_Vertex2 = 0;
	for(int i = 0; i < verticies_in_graph.size(); i++){
		if(second_vertex_name == verticies_in_graph[i].returnName()){
			connecting_Vertex2 = i;
		}
	}
	verticies_in_graph[connecting_Vertex].addEdge(verticies_in_graph[connecting_Vertex2], weight);
	verticies_in_graph[connecting_Vertex2].addEdge(verticies_in_graph[connecting_Vertex], weight);
}

void Graph::ToGraphViz(string fileName){
	ofstream myfile;
	myfile.open(fileName);
	myfile << "strict graph {" << endl;
	for(int i = 0; i < verticies_in_graph.size(); i++){
		for(int j = 0; j < verticies_in_graph[i].edgeStore.size(); j++){
			printVertexName(verticies_in_graph[i], myfile);
			verticies_in_graph[i].printEdges(verticies_in_graph[i], j, myfile);
			myfile << endl;
		}
	}
	myfile << "}" << endl;
	myfile.close();
}

void Graph::printVertexName(Node vertex_Node, ostream& myfile){
	vertex_Node.printVertex(myfile);
}

void Graph::PrimMSTGen(Graph PrimMST){
	string connectingVertex;
	int weightOfConnected, counter = 0;
	int findRealVertex;
	connectingVertex = PrimMST.verticies_in_graph[0].searchSmallestVertex(verticies_in_graph);
	weightOfConnected = PrimMST.verticies_in_graph[0].findWeight(verticies_in_graph);
	createVertex(PrimMST.verticies_in_graph[0].vertex);
	createVertex(connectingVertex);
	createEdge(PrimMST.verticies_in_graph[0].vertex, connectingVertex, weightOfConnected);

	while(verticies_in_graph.size() != PrimMST.verticies_in_graph.size()){
		int currentWeight;
		int smallestWeight;
		int secondcounter = 0;
		string nextVertex;
		int connectingEdge = 0;
		for(int i = 0; i < verticies_in_graph.size(); i++){
			for(int j = 0; j < PrimMST.verticies_in_graph.size(); j++){
				if(verticies_in_graph[i].vertex == PrimMST.verticies_in_graph[j].vertex){
						connectingVertex = PrimMST.verticies_in_graph[j].searchSmallestVertex(verticies_in_graph);
						weightOfConnected = PrimMST.verticies_in_graph[j].findWeight(verticies_in_graph);
						currentWeight = weightOfConnected;
						if(secondcounter < 1){
							smallestWeight = weightOfConnected;
							secondcounter++;
						}
						if(currentWeight <= smallestWeight){
							smallestWeight = currentWeight;
							nextVertex = connectingVertex;
							connectingEdge = i;
						}
					}
				}
			}
			createVertex(nextVertex);
			createEdge(verticies_in_graph[connectingEdge].vertex, nextVertex, smallestWeight);
		}
	}
