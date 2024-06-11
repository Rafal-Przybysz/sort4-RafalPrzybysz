#pragma once
#include <array>

template <typename Iterator>
void countingSort(Iterator first, Iterator last, typename size_t maxKey)
{
	std::vector<Iterator::value_type> count;
	count.resize(maxKey + size_t{ 1 }, typename Iterator::value_type{ 0 });

	for (auto i = first; i != last; ++i)
		++count[*i];

	auto j = size_t{ 0 };
	for (auto i = first; i != last; ++i)
	{
		while (count[j] == 0)
			++j;
		--count[j];
		*i = static_cast<typename Iterator::value_type>( j );
	} 
}
