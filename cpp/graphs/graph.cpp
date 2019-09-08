#include "graph.h"

template <class Node>
void Graph<Node>::add_node(const Node &node)
{
	if (node_neighbors.find(node) == node_neighbors.end())
	{
		node_neighbors[node] = WeightMap();
	}
	else
	{
		throw exception("Node is already in graph");
	}
}

template <class Node>
void Graph<Node>::add_nodes(const vector<Node> &nodes)
{
	for (auto node : nodes)
	{
		add_node(node);
	}

}

template<class Node>
void Graph<Node>::del_node(const Node &node)
{
	for (auto neighbor : get_neighbors(node))
	{
		if (neighbor != node)
		{
			del_edge({ neighbor, node });
		}
	}

	node_neighbors.erase(node);
}

template<class Node>
bool Graph<Node>::has_node(const Node &node)
{
	return node_neighbors.find(node) != node_neighbors.end();
}

template<class Node>
vector<Node> Graph<Node>::get_nodes()
{
	vector<Node> nodes;
	for (auto It = node_neighbors.begin(); It != node_neighbors.end(); It++)
	{
		nodes.push_back(It->first);
	}

	return nodes;
}

template<class Node>
vector<Node> Graph<Node>::get_neighbors(const Node &node)
{
	if (!has_node(node))
	{
		throw exception("Node not in graph");
	}
	else
	{
		vector<Node> neighbors;
		for (auto It = node_neighbors[node].begin(); It != node_neighbors[node].end(); It++)
		{
			neighbors.push_back(It->first);
		}

		return neighbors;
	}
}

template <class Node>
void Graph<Node>::add_edge(const Edge &edge, const int wt)
{
	auto u = edge.first;
	auto v = edge.second;

	if (node_neighbors.find(u) == node_neighbors.end() ||
		node_neighbors.find(v) == node_neighbors.end())
	{
		throw exception("Edge nodes not in graph");
	}

	if (node_neighbors[u].find(v) == node_neighbors[u].end() &&
		node_neighbors[v].find(u) == node_neighbors[v].end())
	{
		node_neighbors[u][v] = wt;

		if (u != v)
		{
			node_neighbors[v][u] = wt;
		}
	}
	else
	{
		throw exception("Edge already added in the graph");
	}
}

template <class Node>
void Graph<Node>::add_edges(const vector<Edge> &edges)
{
	for (auto edge : edges)
	{
		add_edge(edge);
	}
}

template<class Node>
void Graph<Node>::del_edge(const Edge &edge)
{
	auto u = edge.first;
	auto v = edge.second;

	if (!has_edge(edge))
	{
		throw exception("Edge not an existing edge");
	}
	
	node_neighbors[u].erase(v);

	if (u != v)
	{
		node_neighbors[v].erase(u);
	}
}

template <class Node>
bool Graph<Node>::has_edge(const Edge &edge)
{
	auto u = edge.first;
	auto v = edge.second;
	return node_neighbors[u].find(v) != node_neighbors[u].end();
}

template<class Node>
vector<pair<Node, Node>> Graph<Node>::get_edges()
{
	vector<Edge> edges;
	for (auto node : get_nodes())
	{
		for (auto neighbor : get_neighbors(node))
		{
			edges.push_back(make_pair(node, neighbor));
		}
	}
	return edges;
}

template<class Node>
void Graph<Node>::set_edge_weight(const Edge &edge, int wt)
{
	auto u = edge.first;
	auto v = edge.second;

	if (!has_edge(edge))
	{
		throw exception("Edge is not an existing edge");
	}

	node_neighbors[u][v] = wt;
	
	if (u != v)
	{
		node_neighbors[v][u] = wt;
	}
}

template<class Node>
int Graph<Node>::get_edge_weight(const Edge &edge)
{
	auto u = edge.first;
	auto v = edge.second;

	if (!has_edge(edge))
	{
		throw exception("Edge is not an existing edge");
	}

	return node_neighbors[u][v];
}

template<class Node>
vector<pair<pair<Node, Node>, int>> Graph<Node>::get_edge_weights()
{
	set<Edge> uniqueEdges;
	vector<pair<Edge, int>> edgeWeights;

	for (auto u : get_nodes())
	{
		for (auto v : get_neighbors(u))
		{
			auto edge1 = make_pair(u, v);
			auto edge2 = make_pair(v, u);

			if (uniqueEdges.find(edge1) == uniqueEdges.end() &&
				uniqueEdges.find(edge2) == uniqueEdges.end())
			{
				uniqueEdges.insert(edge1);
				edgeWeights.push_back(make_pair(edge1, node_neighbors[u][v]));
			}
		}
	}

	return edgeWeights;
}

template Graph<string>;
template Graph<int>;
