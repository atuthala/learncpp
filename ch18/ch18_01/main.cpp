/*
https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
18.1 — Sorting an array using selection sort
*/

#ifdef ss // Selection sort
#include <iostream>
#include <utility>

int main()
{
	int x{2};
	int y{4};
	std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
	std::swap(x, y); // swap the values of x and y
	std::cout << "After swap: x = " << x << ", y = " << y << '\n';
}
#endif // ss Selection sort



#ifdef ssicpp // Selection sort in C++
#include <iostream>
#include <iterator>
#include <utility>

int main()
{
	int array[]{30, 50, 20, 10, 40};
	constexpr int length{static_cast<int>(std::size(array))};

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex{0}; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex if the index of the smallest element we've encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex{startIndex};

		// Then look for a smaller element in the rest of the array
		for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the index of the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	} 

	// Now that the value array is sorted, print our sorted array as proof it works
	for (int index{0}; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	return 0;
}
#endif // ssicpp Selection sort in C++



#ifdef ssicppstr
#include <iostream>
#include <iterator>
#include <string>
#include <utility>


int main()
{
	std::string array[]{ "may", "cat", "alpha", "beta", "every", "echa" };
	constexpr int length{ static_cast<int>(std::size(array)) };

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex{ startIndex };

		// Then look for a smaller element in the rest of the array
		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the index of the smallest element in the remaining array
                // swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}

	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	return 0;
}
#endif // ssicppstr



#ifdef std_sort
#include <algorithm> // for std::sort
#include <iostream>
//#include <iterator> // for std::size
#include <string>

int main()
{
	int array1[]{30, 50, 20, 10, 40};

	std::string array[]{"B", "Z", "W", "V", "Y", "S", "A", "T", "Kat"};

	std::sort(std::begin(array), std::end(array));

	for (int i{0}; i < static_cast<int>(std::size(array)); ++i)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << '\n';

	return 0;
}
#endif // std_sort



#ifdef Q3
#include <iostream>
#include <iterator> // for std::size
#include <utility>

int main()
{
	int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
	constexpr int length{static_cast<int>(std::size(array))}; // C++17

	// Step through each lement of the array (except the last, which will already be sorted by the time we get to it)
	for (int iteration{0}; iteration < length-1; ++iteration)
	{
		// Search through all elements up to the end of the array - 1
		// The last element has no pair to compare against
		for (int currentIndex{0}; currentIndex < length - 1; ++currentIndex)
		{
			if (array[currentIndex] > array[currentIndex+1])
				std::swap(array[currentIndex], array[currentIndex + 1]);
		}
	}

	// Now print our sorted array as proof it works
	for (int index{0}; index < length; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	return 0;
}
#endif // Q3



#ifdef Q4
#endif //Q4
#include <iostream>
#include <iterator> // for std::size
#include <utility>

void printarr(int* array, int length){
	for (int index{0}; index < length; ++index)
	{
		std::cout << array[index] << ' ';
	}
	std::cout << '\n';
}

int main()
{
	int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
	constexpr int length{static_cast<int>(std::size(array))}; // C++17
	printarr(array, length);

	// Step through each element of the array except the last
	for (int iteration{0}; iteration < length - 1; ++iteration)
	{
		// Account for the fact that the last element
		// so our array "ends" one element sooner
		int endOfArrayIndex{length - iteration};

		bool swapped{false}; // Keep track of whether any elements were swapped this iteration

		// Search through all elements up to the end of the array - 1
		// The last element has no pair to compare against
		for (int currentIndex{0}; currentIndex < endOfArrayIndex - 1; ++currentIndex)
		{
			// If the current element is larger than the element after it
			if (array[currentIndex] > array[currentIndex + 1])
			{
				// Swap them
				std::swap(array[currentIndex], array[currentIndex + 1]);
				swapped = true;
			}
		}

		// If we haven't swapped any elements this iteration, we're done early
		if (!swapped)
		{
			// iteration is 0 based, but counting iteration is 1-based. So add 1 here to adjust.
			std::cout << "Early termination on iteration: " << iteration+1 << '\n';
			break;
		}
	}

	// Now print our sorted array as proof it works
	printarr(array, length);

	std::string entry{};
	std::cin >> entry;

}