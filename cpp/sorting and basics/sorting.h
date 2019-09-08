#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

using namespace std;

namespace sorting
{
	template<class Type>
	vector<Type> mergesort(const vector<Type> &arr);

	template<class Type>
	vector<Type> merge(vector<Type> arr1, vector<Type> arr2);

	template<class Type>
	vector<Type> quicksort(vector<Type> arr);
}

#endif