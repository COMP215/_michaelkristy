
#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
	Graph basicGraph;
	basicGraph.createVertex("max");
	basicGraph.createVertex("michael");
	basicGraph.createVertex("Armweak");
	basicGraph.createVertex("LeblancyBlancDaDankyDank");
	basicGraph.createVertex("DifficultProject");
	basicGraph.createEdge("max","michael", 3);
	basicGraph.createEdge("Armweak", "LeblancyBlancDaDankyDank", 5);
	basicGraph.createEdge("Armweak", "michael", 20);
	basicGraph.createEdge("max", "LeblancyBlancDaDankyDank", 23);
	basicGraph.createEdge("max", "Armweak", 456);
	basicGraph.createEdge("DifficultProject", "michael", 54);
	basicGraph.ToGraphViz("originalGraph.dot");

	Graph PrimMST;
	PrimMST.PrimMSTGen(basicGraph);
	PrimMST.ToGraphViz("primMST.dot");

	cout << "I'm done!" << endl;

	return 0;
}
