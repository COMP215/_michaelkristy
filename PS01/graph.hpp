#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

class Node {
public:
	std::string vertex;
	std::vector<Node>edgeStore;
	std::vector<int>edgeWeight;
	std::vector<Node>ignoreVector;

	Node();
	void addNode(std::string notVertex);
	void addEdge(Node passedNode, double weight);
	void printVertex(std::ostream& myfile);
	void printEdges(Node passedNode, int move, std::ostream& myfile);
	std::string searchSmallestVertex(std::vector<Node>ignoreVector);
	int findWeight(std::vector<Node>ignoreVector);
	std::string returnName();
};

class Graph {
public:
	std::vector<Node>verticies_in_graph;

	Graph();
	void createVertex(std::string vertex);
	void createEdge(std::string first, std::string second, double weight);
	void ToGraphViz(std::string graphName);
	void printVertexName(Node vertexNode, std::ostream& myfile);
	void PrimMSTGen(Graph PrimMST);
};
