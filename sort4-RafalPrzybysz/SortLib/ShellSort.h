#pragma once
#include <array>
#include <algorithm>
#include <cstddef>

template <typename Iterator>
void insertionSort(Iterator first, Iterator last, size_t gap)
{
	auto i = first;
	while (static_cast<size_t>(std::distance(i, last)) > gap)
	{
		i += gap;
		auto j = i;
		auto v = *j;
		for (; j != first && *(j - gap) > v; j -= gap)
			*j = *(j - gap);
		*j = v;
	}
}

template <typename Iterator>
void shellSort(Iterator first, Iterator last)
{
	static std::array<size_t, 8> gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };

	for (auto gap : gaps)
		insertionSort(first, last, gap);
}