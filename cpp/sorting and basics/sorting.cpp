#include "sorting.h"

#include <random>

namespace sorting
{
	template<class Type>
	vector<Type> mergesort(const vector<Type> &arr)
	{
		auto n = (int) arr.size();

		if (n <= 1)
		{
			return arr;
		}

		auto a1 = mergesort(vector<Type>(arr.begin(), arr.begin() + n / 2));
		auto a2 = mergesort(vector<Type>(arr.begin() + n / 2, arr.end()));

		return merge(a1, a2);
	}

	template <class Type>
	vector<Type> merge(vector<Type> arr1, vector<Type> arr2)
	{
		vector<Type> arr3;
		
		unsigned int i = 0;
		unsigned int j = 0;

		while (i < arr1.size() && j < arr2.size())
		{
			if (arr1[i] <= arr2[j])
			{
				arr3.push_back(arr1[i]);
				i += 1;
			}
			else
			{
				arr3.push_back(arr2[j]);
				j += 1;
			}
		}

		if (arr1.size() > i)
		{
			arr3.insert(arr3.end(), arr1.begin() + i, arr1.end());
		}

		if (arr2.size() > j)
		{
			arr3.insert(arr3.end(), arr2.begin() + j, arr2.end());
		}

		return arr3;
	}

	template<class Type>
	vector<Type> quicksort(vector<Type> arr)
	{
		/*quicksort implementation
		NOTE: This algo uses O(n) extra space to compute quicksort.*/

		auto n = (int) arr.size();
		
		if (n <= 1)
		{
			return arr;
		}
		else
		{
			int r = rand() % n;
			Type pivot = arr[r];
			arr.erase(arr.begin() + r);

			vector<Type> lesser;
			vector<Type> greater;
			for (auto x : arr)
			{
				if (x < pivot)
				{
					lesser.push_back(x);
				}
				else // x >= pivot
				{
					greater.push_back(x);
				}
			}

			lesser = quicksort(lesser);
			greater = quicksort(greater);

			vector<Type> arr_sorted;
			arr_sorted.insert(arr_sorted.end(), lesser.begin(), lesser.end());
			arr_sorted.push_back(pivot);
			arr_sorted.insert(arr_sorted.end(), greater.begin(), greater.end());

			return arr_sorted;
		}
	}

	template vector<string> mergesort(const vector<string> &arr);
	template vector<int> mergesort(const vector<int> &arr);

	template vector<string> merge(vector<string> arr1, vector<string> arr2);
	template vector<int> merge(vector<int> arr1, vector<int> arr2);

	template vector<string> quicksort(vector<string> arr);
	template vector<int> quicksort(vector<int> arr);
}