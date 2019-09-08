#ifndef TESTGRAPHALGORITHMS_H
#define TESTGRAPHALGORITHMS_H

#include "../graphs/graph_algorithms.h"

#include <assert.h>

#ifndef ASSERT_RAISES
#define ASSERT_RAISES

template <class Type>
void assertRaises(Type &&f)
{
	try
	{
		f();
		assert(false);
	}
	catch (exception &)
	{
		assert(true);
	}
}

#endif

class GraphAlgorithmsTest
{
	Graph<string> gr;
	//DiGraph<string> digr;

public:

	GraphAlgorithmsTest()
	{
	}

	void setUp()
	{
		gr = Graph<string>();
		gr.add_nodes({ "s", "a", "b", "c", "d", "e", "f", "g", "h", "j", "k", "l" });
		gr.add_edges({ {"s", "a"}, {"s", "b"}, {"a", "c"}, {"c", "e"} });
		gr.add_edges({ {"e", "d" }, { "d", "b" }, { "a", "b" }, { "c", "d" } });
		gr.add_edges({ {"g", "h"}, {"f", "g" } });
		gr.add_edges({ {"j", "k"}, {"j", "l" } });
	}

	void test_bfs_undirected_graph()
	{
		setUp();
		assert(GraphAlgorithms<string>::BFS(gr, "s").size() == 6);
		assert(GraphAlgorithms<string>::BFS(gr, "j").size() == 3);
		assert(GraphAlgorithms<string>::BFS(gr, "g").size() == 3);
	}

	void test_dfs_undirected_graph()
	{
		setUp();
		assert(GraphAlgorithms<string>::DFS(gr, "s").size() == 6);
		assert(GraphAlgorithms<string>::DFS(gr, "j").size() == 3);
		assert(GraphAlgorithms<string>::DFS(gr, "g").size() == 3);
	}
};


void RunGraphAlgorithmsTest()
{
	GraphAlgorithmsTest gr_test;

	gr_test.test_bfs_undirected_graph();
	gr_test.test_dfs_undirected_graph();
}

#endif