#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

class Node {
public:
	std::string vertex;
	std::vector<Node>edgeStore;
  std::vector<Node>tempEdgeHolder;
	std::vector<int>edgeWeight;
  std::vector<int>tempEdgeWeightHolder;

	Node();
	void addNode(std::string notVertex);
	void addEdge(Node passedNode, double weight);
	void printVertex(std::ostream& myfile);
	void printEdges(Node passedNode, int move, std::ostream& myfile);
	std::string searchSmallestVertex();
	int findWeight();
	std::string returnName();
	void removeReconnectingEdge(int removeVal);
};

class Graph {
public:
	std::vector<Node>MASTER;

	Graph();
	void createVertex(std::string vertex);
	void createEdge(std::string first, std::string second, double weight);
	void ToGraphViz(std::string graphName);
	void printVertexName(Node vertexNode, std::ostream& myfile);
	void PrimMSTGen(Graph PrimMST);

};
