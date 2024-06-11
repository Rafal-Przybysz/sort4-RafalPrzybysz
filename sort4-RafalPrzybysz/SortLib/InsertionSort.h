#pragma once

template <typename Iterator>
void insertionSort(Iterator first, Iterator last)
{
	if (first == last)
		return;
	for (Iterator i = first + 1; i != last; ++i)
	{
		auto j = i;
		auto v = *j;
		for (; j != first && *(j - 1) > v; --j)
			*j = *(j - 1);
		*j = v;
	}
}
