#ifdef Question_5
#endif // Question_5
// https://www.learncpp.com/cpp-tutorial/chapter-12-summary-and-quiz/
/*
12.x — Chapter 12 summary and quiz
Alex  April 30, 2024
*/
#include <algorithm> // for std::swap
#include <iostream>

void sort2(int& lesser, int& greater);

int main()
{
	int x {7};
	int y {5};

	std::cout << x << ' ' << y << '\n';

	sort2(x, y);
	std::cout << x << ' ' << y << '\n';

	sort2(x, y);
	std::cout << x << ' ' << y << '\n';
}

void sort2(int& lesser, int& greater)
{
	// If the values are already sorted, we have nothing to do
	if (lesser <= greater)
		return;

	// Otherwise we need to swap the values
	std::swap(lesser, greater);
}