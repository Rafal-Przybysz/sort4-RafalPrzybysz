#pragma once
#include <algorithm>

template <typename Iterator>
Iterator partition(Iterator const& first, Iterator const& last)
{
	auto middle = first + ((last - first) / 2);
	//auto middle = first;
	//auto middle = last - 1;
	std::swap(*middle, *first);

	auto i = last - 1;
	for (Iterator j = last - 1; j > first; --j)
		if (*j > * first)
			std::swap(*j, *(i--));
	std::swap(*i, *first);
	return i;
}

template <typename Iterator>
void quickSort(Iterator first, Iterator last)
{
	if (first < last)
	{
		auto pivot = partition(first, last);
		quickSort(first, pivot);
		quickSort(pivot + 1, last);
	}
}