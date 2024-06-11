#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "benchmark.h"
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"
#include "../SortLib/ShellSort.h"
#include "../SortLib/CountingSort.h"
#include "../SortLib/QuickSortNoRecursion.h"

int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<size_t> s = { 1000, 2000, 3000, 30000 };
	//std::vector<size_t> s = { 200000, 300000, 500000, 1000000, 2000000, 4000000, 6000000, 8000000, 10000000, 20000000 };
	for (auto n : s)
	{
		std::vector<unsigned int> v;

		// wygenerowanie losowej zawartoœci kolekcji
		auto seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator((unsigned int)seed);

		for (size_t i = 0; i < n; i++)
			v.push_back(generator());
		std::sort(v.begin(), v.end());


		Benchmark<std::chrono::nanoseconds> b;
		quickSort(v.begin(), v.end());
		//quickSortNoRecursion(v.begin(), v.end());
		auto t = b.elapsed();

		std::cout << t << std::endl;
	}
}
