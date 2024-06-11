#include <iostream>
#include <ostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "../SortLib/BubbleSort.h"
#include "../SortLib/InsertionSort.h"
#include "../SortLib/SelectionSort.h"
#include "../SortLib/MergeSort.h"
#include "../SortLib/QuickSort.h"
#include "../SortLib/ShellSort.h"

class Number
{
private:
	unsigned int value;
	size_t index;
public:
	Number(unsigned int value, size_t index) : value(value), index(index)
	{
	}
	bool operator<(Number const& n)
	{
		return value < n.value;
	}
	bool operator>(Number const& n)
	{
		return value > n.value;
	}
	bool operator<=(Number const& n)
	{
		return value <= n.value;
	}
	bool operator>=(Number const& n)
	{
		return value >= n.value;
	}
	bool operator==(Number const& n)
	{
		return value == n.value;
	}
	bool operator!=(Number const& n)
	{
		return value != n.value;
	}
	friend std::ostream& operator<<(std::ostream& stream, Number const& n);
};

std::ostream& operator<<(std::ostream& stream, Number const& n)
{
	stream << n.value << " (" << n.index << ")";
	return stream;
}

int main()
{
	setlocale(LC_ALL, "pl-pl");
	std::vector<Number> v;

	// wype³nienie wektora konkretnymi wartoœciami
	v = { {10,0}, {5,1}, {7,2}, {2,3}, {3,4}, {1,5} };

	// wyœwietlenie zawartoœci kolekcji przed sortowaniem
	std::cout << "Kolekcja nieposortowana:" << std::endl;
	for (auto value : v)
		std::cout << value << std::endl;
	std::cout << std::endl;

	shellSort(v.begin(), v.end());

	// wyœwietlenie zawartoœci kolekcji po posortowaniu
	std::cout << "Kolekcja posortowana:" << std::endl;
	for (auto value : v)
		std::cout << value << std::endl;
	std::cout << std::endl;
}
