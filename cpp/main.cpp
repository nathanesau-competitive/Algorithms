#include "tests/graph_test.h"
#include "tests/graph_algorithms_test.h"
#include "tests/sorting_test.h"
#include "tests/misc_test.h"

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    RunGraphTest();
	RunGraphAlgorithmsTest();
	RunSortingTest();
    RunMiscTest();

    return 0;
}
