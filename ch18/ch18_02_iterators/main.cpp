/*
18.2 — Introduction to iterators
https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/#google_vignette
*/

#ifdef iti // Introduction to iterators
#include <array>
#include <cstddef>
#include <iostream>

int main()
{
	// In C++17, the type of variable data is deduced to std::array<int,7>
	// If you get an error compiling this example, see the warning below
	std::array data{0, 1, 2, 3, 4, 5, 6};
	std::size_t length{std::size(data)};

	// while-loop with explicit index
	std::size_t index{0};
	while (index < length)
	{
		std::cout << data[index] << ' ';
		++index;
	}
	std::cout << '\n';

	// for-loop with explicit index
	for (index = 0; index < length; ++index)
	{
		std::cout << data[index] << ' ';
	}
	std::cout << '\n';

	// for-loop with pointer (Note: ptr can't be const, because we incremet it)
	for (auto ptr{&data[0]}; ptr != (&data[0] + length); ++ptr)
	{
		std::cout << *ptr << ' ';
	}
	std::cout << '\n';

	// range-based for loop
	for (int i: data)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	return 0;
}
#endif // iti



#ifdef paai // Pointer as an iterator
#include <array>
#include <iostream>

int main()
{
	std::array data{0, 1, 2, 3, 4, 5, 6};

	auto begin{&data[0]};
	// note that this points to one spot beyond the last element
	auto end{begin + std::size(data)};

	// for-loop with pointer
	for (auto ptr{begin}; ptr != end; ++ptr) // ++ to move to next element
	{
		std::cout << *ptr << ' '; // Idirection to get value of current element
	}
	std::cout << '\n';

	return 0;
}
#endif // paai



#ifdef sli // Standard library iterators
#include <array>
#include <iostream>

int main()
{
	std::array array{1, 2, 3};

	// Use std::begin and std::end to get the begin and end points
	auto begin{std::begin(array)};
	auto end{std::end(array)};

	for (auto p{begin}; p != end; ++p) // ++ to move to next element
	{
		std::cout << *p << ' '; // Indirection to get value of current element
	}
	std::cout << '\n';

	return 0;
}
#endif // sli



#ifdef iidi_1 // Iterator invalidation (dangling iterators)
#include <iostream>
#include <vector>

int main()
{
	std::vector v {0, 1, 2, 3};

	for (auto num : v) // implicitly iterates over v
	{
		if (num % 2 == 0)
			v.push_back(num + 1); // when this invalidates the iterators of v, undefined behavior will rusult
	}

	for (auto el : v)
	{
		std::cout << el << ' ';
	}
	std::cout << '\n';

	return 0;
}
#endif // iidi_1


#ifdef iidi_2
#include <iostream>
#include <vector>

int main()
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto it{v.begin()};

	++it; // move to second element
	std::cout << *it << '\n'; // ok: prints 2

	v.erase(it); // erase the element currently being iterated over

	// earas() invalidates iterators to the erased elment (and subsequent elements)
	// so iterator "it" is now invalidated

	++it; // undefined behavior
	std::cout << *it << '\n'; // undefined behavior

	for (auto el : v)
	{
		std::cout << el << ' ';
	}
	std::cout << '\n';

	return 0;
}
#endif // iidi_2



#ifdef iidi_3
#include <iostream>
#include <vector>

int main()
{
	std::vector v{1, 2, 3, 4, 5, 6, 7};

	auto it{v.begin()};

	++it; // move to second lement
	std::cout << *it << '\n';

	it = v.erase(it); // erase the element currently iterated over, set `it` to next element

	std::cout << *it << '\n'; // now ok, prints 3

	for (auto el : v)
	{
		std::cout << el << ' ';
	}
	std::cout << '\n';

	return 0;
}
#endif // iidi_3