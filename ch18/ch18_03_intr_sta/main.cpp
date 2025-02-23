/*
https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
18.3 — Introduction to standard library algorithms
*/

#ifdef begin
#endif // begin


#ifdef ufind
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
	std::array arr{13, 90, 99, 5, 40, 80};

	std::cout << "Enter a value to search for and replace with: ";
	int search{};
	int replace{};
	std::cin >> search >> replace;

	// Input validation omitted

	// std::find returns an iterator pointing to the found element (or the end of the container)
	// we'll store it in a variable, using type inference to deduce the type of
	// the iterator (since we don't care)
	auto found{std::find(arr.begin(), arr.end(), search) };

	// Algorithms that don't find what they were looking for return the end iterator.
	// We can access it by using the end() member function.
	if (found == arr.end())
	{
		std::cout << "Could not find " << search << '\n';
	}
	else
	{
		// Override the found element.
		*found = replace;
	}

	for (int i : arr)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}
#endif // ufind



#ifdef ufindif
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
	// std::string_view::find returns std::string_view::npos if it doesn't find
	// the substring. Otherwise it returns the index where the substring occurs
	// in str.
	return str.find("nut") != std::string_view::npos;
}

int main()
{
	std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

	// Scan our array to see if any elements contain the "nut" substring
	auto found{std::find_if(arr.begin(), arr.end(), containsNut)};

	if (found == arr.end())
	{
		std::cout << "No nuts\n";
	}
	else
	{
		std::cout << "Found " << *found << '\n';
	}

	return 0;
}
#endif // ufindif



#ifdef uCOUNT
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool containsNut(std::string_view str)
{
	return str.find("nut") != std::string_view::npos;
}

int main()
{
	std::array<std::string_view, 5> arr{"apple", "banana", "walnut", "lemon", "peanut"};

	auto nuts{std::count_if(arr.begin(), arr.end(), containsNut)};

	std::cout << "Counted " << nuts << " nuts(s)\n";

	return 0;
}
#endif // uCOUNT



#ifdef usstcs // Using std::sort to custom sort
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <functional>
#include <utility>

bool greater(int a, int b)
{
	// order @a before @b if @a is greater than @b
	return (a > b);
}

// sort accepts a comparison function
void sort(int* begin, int* end, std::function<bool(int, int)> compare)
{
	for (auto startElement{begin}; startElement != end - 1; ++startElement)
	{
		auto smallestElement{startElement};

		// std::next returns a pointer to the next element, just like (startElement + 1) would.
		for (auto currentElement{std::next(startElement)}; currentElement != end; ++currentElement)
		{
			#ifdef usstcs_inner
			if (*currentElement < *smallestElement)
			{
				smallestElement = currentElement;
			}
			#else
			#endif // usstcs_inner
			// the comparison function is used to check if the current element should bo ordered
			// before the currently "smallest" element.
			if (compare(*currentElement, *smallestElement))
			{
				smallestElement = currentElement;
			}
		}

		std::swap(*startElement, *smallestElement);
	}
}

int main()
{
	std::array array{13, 0, 90, 99, -5, 5, 40, 80};

	// Pass greater to std::sort
	::sort(array.begin(), array.end(), std::greater{});

	// sort(std::begin(array), std::end(array));

	for (int i : array)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}
#endif // usstcs



#ifdef ufe // Using std::for_each to do something to all elements of a container
#endif // ufe
#include <algorithm>
#include <array>
#include <iostream>

void doubleNumber(int& i)
{
	i *= 2;
}

int main()
{
	std::array arr{1, 2, 3, 4};

	// std::for_each(arr.begin() + 1, arr.end(), doubleNumber);
	// std::ranges::for_each(arr, doubleNumber); // Since C++20, we don't have to use begin() and end().
	std::for_each(std::next(arr.begin()), arr.end(), doubleNumber);	 // Before C++20

	for (int i : arr)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	return 0;
}