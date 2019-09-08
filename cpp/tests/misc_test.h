#include "../misc/shuffle.h"

#ifndef MISCTEST_H
#define MISCTEST_H

#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

class ShuffleTest
{
	vector<int> arr;

public:

	ShuffleTest()
	{
	}

	void setUp()
	{
		arr = {1,2,3,4,5,6};
	}

	void test_shuffle_method()
	{
		setUp();
		shuffle(arr);
        assert(arr.size() == 6); // shuffle is random, difficult to test
    }
};


void RunShuffleTest()
{
	ShuffleTest shuffle_test;

	srand(time(NULL));

	shuffle_test.test_shuffle_method();
}


void RunMiscTest()
{
	RunShuffleTest();
}


#endif