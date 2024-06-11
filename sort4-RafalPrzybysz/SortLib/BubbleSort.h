#pragma once
#include <algorithm>


template <typename Iterator>
void bubbleSort(Iterator first, Iterator last)
{
	if (first == last)
		return;
	for (Iterator i = first + 1; i < last; ++i)
	{
		bool sorted = true;
		for (Iterator j = last - 1; j >= i; --j)
			if (*j < *(j - 1))
			{
				std::swap(*j, *(j - 1));
				sorted = false;
			}
		if (sorted)
			return;
	}
}