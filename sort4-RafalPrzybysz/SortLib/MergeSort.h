#pragma once
#include <algorithm>

template <typename Iterator>
void merge(Iterator const& first, Iterator const& middle, Iterator const& last)
{
	std::vector<Iterator::value_type> v;
	auto i = first, j = middle;
	while (i < middle && j < last)
	{
		if (*i <= *j)
			v.push_back(*(i++));
		else
			v.push_back(*(j++));
	}
	if (i < middle)
	{
		for (; i < middle; ++i)
			v.push_back(*i);
	}
	else
		for (; j < last; ++j)
			v.push_back(*j);
	for (i = v.begin(), j = first; i != v.end(); ++i, ++j)
		*j = *i;
}

template <typename Iterator>
void mergeSort(Iterator first, Iterator last)
{
	if (last - first > 1)
	{
		auto middle = first + ((last - first) / 2);
		mergeSort(first, middle);
		mergeSort(middle, last);
		merge(first, middle, last);
	}
}