#ifndef SORTINGTEST_H
#define SORTINGTEST_H

#include <algorithm>
#include <assert.h>

#include "../sorting and basics/sorting.h"

class SortingTest
{
	vector<int> arr;

public:

	SortingTest()
	{
	}

	void setUp()
	{
		arr = { 5, 3, 8, 1, 7, 10, 9, 2, 13, 0, 6};
	}

	void test_mergesort_method()
	{
		setUp();

		vector<int> arr1 = arr;
		sort(arr1.begin(), arr1.end()); // std::sort

		vector<int> arr2 = arr;
		arr2 = sorting::mergesort(arr2);

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr1[i] != arr2[i])
			{
				assert(false);
			}
		}
	}

	void test_quicksort_method()
	{
		setUp();

		vector<int> arr1 = arr;
		sort(arr1.begin(), arr1.end()); // std::sort

		vector<int> arr2 = arr;
		arr2 = sorting::quicksort(arr2);

		for (int i = 0; i < arr.size(); i++)
		{
			if (arr1[i] != arr2[i])
			{
				assert(false);
			}
		}
	}
};


void RunSortingTest()
{
	SortingTest sort_test;

	sort_test.test_mergesort_method();
	sort_test.test_quicksort_method();
}

#endif