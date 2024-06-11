#pragma once

template <typename Iterator>
Iterator findLowest(Iterator first, Iterator last)
{
	auto lowest = first;
	for (auto i = first + 1; i != last; ++i)
		if (*i < *lowest)
			lowest = i;
	return lowest;
}

template <typename Iterator>
void selectionSort(Iterator first, Iterator last)
{
	if (first == last)
		return;
	for (auto i = first; i != last - 1; ++i)
	{
		auto lowest = findLowest(i, last);
		if (lowest != i)
			std::swap(*lowest, *i);
	}
}