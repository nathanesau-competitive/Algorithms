#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include "../graphs/graph.h"

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

class GraphTest
{
	Graph<string> gr;

public:

	GraphTest()
	{
	}

	void setUp()
	{
		gr = Graph<string>();
		gr.add_nodes({ "a", "b", "c", "d", "e", "f" });
		gr.add_edge({ "a","b" });
		gr.add_edge({ "a","f" });
		gr.add_edge({ "b","c" });
		gr.add_edge({ "c","e" });
		gr.add_edge({ "c","d" });
		gr.add_edge({ "d","f" });
	}

	void test_get_nodes_method()
	{
		setUp();
		assert(gr.get_nodes().size() == 6);
	}

	void test_add_node_method()
	{
		setUp();
		gr.add_node("g");
		assert(gr.get_nodes().size() == 7);
	}

	void test_has_node_method()
	{
		setUp();
		assert(gr.has_node("a"));
	}

	void test_get_neighbors_method()
	{
		setUp();
		assert(gr.get_neighbors("a").size() == 2);
	}

	void test_del_node_method()
	{
		setUp();
		gr.del_node("a");
		assert(!gr.has_node("a"));
		assert(gr.get_edges().size() == 8);
	}

	void test_has_edge_method()
	{
		setUp();
		assert(gr.has_edge({ "a", "b" }));
		assert(!gr.has_edge({ "a","d" }));
	}

	void test_add_duplicate_node_method_throws_exception()
	{
		setUp();
		auto f = [&]()
		{
			gr.add_node("a");
		};

		assertRaises(f);
	}

	void test_del_nonexistent_node_throws_exception()
	{
		setUp();
		auto f = [&]()
		{
			gr.del_node("z");
		};

		assertRaises(f);
	}

	void test_add_duplicate_edge_throws_exception()
	{
		setUp();
		auto f = [&]()
		{
			gr.add_edge({ "a","b" });
		};

		assertRaises(f);
	}

	void test_add_edge_from_non_existing_node()
	{
		setUp();
		auto f = [&]()
		{
			gr.add_edge({ "b","z" });
		};

		assertRaises(f);
	}

	void test_adding_self_loop()
	{
		setUp();
		gr.add_edge({ "a","a" });
		assert(gr.has_edge({ "a","a" }));
	}

	void test_remove_self_loop()
	{
		setUp();
		gr.add_edge({ "a","a" });
		gr.del_edge({ "a","a" });
		assert(!gr.has_edge({ "a","a" }));
	}

	void test_get_edges_method()
	{
		setUp();
		assert(gr.get_edges().size() == 2 * 6);
	}

	void test_add_edges_method()
	{
		setUp();
		gr.add_edges({ {"a","c"},{"c","f"},{"d","e"} });
		assert(gr.has_edge({ "a","c" }));
		assert(gr.has_edge({ "c", "f" }));
		assert(gr.has_edge({ "d","e" }));
	}

	void test_node_orders_method()
	{
		setUp();
	}

	void test_del_edge_method()
	{
		setUp();
		gr.del_edge({ "a","f" });
		assert(!gr.has_edge({ "a","f" }));
	}
	
	void test_deleting_non_existent_edge_raises_exception()
	{
		setUp();
		auto f = [&]()
		{
			gr.del_edge({ "a","z" });
		};

		assertRaises(f);
	}

	void test_get_default_weight()
	{
		setUp();
		assert(gr.get_edge_weight({ "a","b" }) == 1);
	}

	void test_set_weight_on_existing_edge()
	{
		setUp();
		gr.set_edge_weight({ "a","b" }, 10);
		assert(gr.get_edge_weight({ "a","b" }) == 10);
	}

	void test_weight_for_nonexisting_edge()
	{
		setUp();
		auto f = [&]()
		{
			gr.get_edge_weight({ "a","c" });
		};

		assertRaises(f);
	}

	// ADDITIONAL TESTS
	void test_get_edge_weights()
	{
		setUp();

		auto edgeWeights = gr.get_edge_weights();
		assert(edgeWeights.size() == 6);
	}
};


void RunGraphTest ()
{
	GraphTest gr_test;

	gr_test.test_get_nodes_method();
	gr_test.test_add_node_method();
	gr_test.test_has_node_method();
	gr_test.test_get_neighbors_method();
	gr_test.test_del_node_method();
	gr_test.test_has_edge_method();
	gr_test.test_add_duplicate_node_method_throws_exception();
	gr_test.test_del_nonexistent_node_throws_exception();
	gr_test.test_add_duplicate_edge_throws_exception();
	gr_test.test_add_edge_from_non_existing_node();
	gr_test.test_adding_self_loop();
	gr_test.test_remove_self_loop();
	gr_test.test_get_edges_method();
	gr_test.test_add_edges_method();
	gr_test.test_node_orders_method();
	gr_test.test_del_edge_method();
	gr_test.test_deleting_non_existent_edge_raises_exception();
	gr_test.test_get_default_weight();
	gr_test.test_set_weight_on_existing_edge();
	gr_test.test_weight_for_nonexisting_edge();
	gr_test.test_get_edge_weights();
}

#endif