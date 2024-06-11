#pragma once
#include <algorithm>
#include <vector>

template <typename Iterator>
Iterator partition2(Iterator const& first, Iterator const& last)
{
	auto middle = first +((last - first) / 2);
	//auto middle = first;
	//auto middle = last - 1;

	std::swap(*middle, *first);

	auto i = last - 1;
	for (Iterator j = last - 1; j > first; --j)
		if (*j > *first)
			std::swap(*j, *(i--));
	std::swap(*i, *first);
	return i;
}

template <typename Iterator>
void quickSortNoRecursion(Iterator first, Iterator last)
{
	//size_t max_stack = 1;
	std::vector<std::pair<Iterator, Iterator>> stack;
	stack.push_back({ first, last });
	while (!stack.empty())
	{
		auto p = stack.back();
		auto from = p.first, to = p.second;
		stack.pop_back();

		while (std::distance(from, to) > 1)
		{
			auto pivot = partition2(from, to);
			if (std::distance(from, pivot) > std::distance(pivot + 1, to))
			{
				stack.push_back({ from, pivot });
				//max_stack = std::max(max_stack, stack.size());
				from = pivot + 1;
			}
			else
			{
				stack.push_back({ pivot + 1, to });
				//max_stack = std::max(max_stack, stack.size());
				to = pivot;
			}
		}
	}
	//std::cout << " Max stack: " << max_stack << " ";
}