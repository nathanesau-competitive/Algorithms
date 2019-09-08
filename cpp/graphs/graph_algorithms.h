#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

#include "graph.h"

template <class Node>
class GraphAlgorithms
{
public:

	static vector<Node> BFS(Graph<Node> gr, Node s);
	static vector<Node> DFS(Graph<Node> gr, Node s);

	static int kruskal_MST(Graph<Node> gr);
};

#endif