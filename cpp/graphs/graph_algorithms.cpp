#include "graph_algorithms.h"

#include <queue>

template<class Node>
vector<Node> GraphAlgorithms<Node>::BFS(Graph<Node> gr, Node s)
{
	/*Breadth first search
	Returns a list of nodes that are "findable" from s*/

	if (!gr.has_node(s))
	{
		throw exception("Node not in graph");
	}

	vector<Node> nodes_explored({ s });
	queue<Node> q({ s });

	while (q.size() > 0)
	{
		auto node = q.front();
		q.pop();

		for (auto neighbor : gr.get_neighbors(node))
		{
			if (find(nodes_explored.begin(), nodes_explored.end(), neighbor) == nodes_explored.end())
			{
				nodes_explored.push_back(neighbor);
				q.push(neighbor);
			}
		}
	}

	return nodes_explored;
}

template<class Node>
void depth_first_search(Graph<Node> gr, Node s, vector<Node> &path)
{
	if (find(path.begin(), path.end(), s) != path.end())
	{
		return;
	}

	path.push_back(s);

	for (auto neighbor : gr.get_neighbors(s))
	{
		if (find(path.begin(), path.end(), neighbor) == path.end())
		{
			depth_first_search(gr, neighbor, path);
		}
	}
}

template<class Node>
vector<Node> GraphAlgorithms<Node>::DFS(Graph<Node> gr, Node s)
{
	vector<Node> path;

	depth_first_search(gr, s, path);
	return path;
}

template<class Node>
int GraphAlgorithms<Node>::kruskal_MST(Graph<Node> gr)
{
	//todo
	return 0;
}

template GraphAlgorithms<string>;
template GraphAlgorithms<int>;