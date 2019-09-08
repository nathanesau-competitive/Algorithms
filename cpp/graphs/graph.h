#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

template <class Node>
class Graph
{
    typedef pair<Node, Node> Edge;
    typedef unordered_map<Node, int> WeightMap;

    unordered_map<Node, WeightMap> node_neighbors;

public:

	void add_node(const Node &node);

	void add_nodes(const vector<Node> &nodes);

	void del_node(const Node &node);

	bool has_node(const Node &node);

	vector<Node> get_nodes();

	vector<Node> get_neighbors(const Node &node);

	void add_edge(const Edge &edge, const int wt = 1);

	void add_edges(const vector<Edge> &edges);

	void del_edge(const Edge &edge);

	bool has_edge(const Edge &edge);

	vector<pair<Node, Node>> get_edges();

	void set_edge_weight(const Edge &edge, int wt);

	int get_edge_weight(const Edge &edge);

	vector<pair<Edge, int>> get_edge_weights();
};

#endif