// 10.7 — Typedefs and type aliases
// https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
#ifdef _10_7__Using_type_aliases
#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type


bool hasDuplicates(VectPairSI pairlist)
{
	// some code here
	return false;
}

int main()
{
	VectPairSIc pairlist;

	return 0;
}
#endif // _10.7__Using_type_aliases



#include <iostream>

namespace constants
{
	constexpr double pi{ 3.14159 };
}

using Degrees = double;
using Radians = double;

Radians convertToRadians(Degrees degrees)
{
	return degrees * constants::pi / 180;
}

int main()
{
	std::cout << "Enter a number of degrees: ";
	Degrees degrees{};
	std::cin >> degrees;

	Radians radians{convertToRadians(degrees)};
	std::cout << degrees << " degrees is " << radians << " radians.\n";

	return 0;
}


