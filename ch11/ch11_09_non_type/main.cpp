//11.9 — Non-type template parameters
//https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/
#ifdef Defining_our_own__non_type__template_parameters
#include <iostream>

template <int N> // declare a non-type template parameter of type int named	N
void print()
{
	std::cout << N << '\n'; // use value of N here
}

int main()
{
	print<5>(); // 5 is our non-type template argument

	return 0;
}
#endif // Defining_our_own__non_type__template_parameters



#ifdef What_are__non_type__template_parameters_useful_for
#include <cassert>
#include <cmath> // for std::sqrt
#include <iostream>

double getSqrt(double d)
{
	assert( d >= 0.0 && "getSqrt(): d must be non-negative");

	// The assert above will probably be compiled out in non-debug builds
	if (d >= 0)
		return std::sqrt(d);

	return 0.0;
}

int main()
{
	std::cout << getSqrt(5.0) << '\n';
	std::cout << getSqrt(-5.0) << '\n';
}
#endif // What_are__non_type__template_parameters_useful_for



#ifdef What_are_part2
#include <cmath> // for std::sqrt
#include <iostream>

template <double D> // requires C++20 for floating point non-type parameters
double getSqrt()
{
	static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

	if constexpr( D >= 0 ) // ignore the constexpr here for this example
		return std::sqrt(D);

	return 0.0;
}

int main()
{
	std::cout << getSqrt<5.0>() << '\n';
	std::cout << getSqrt<-5.0>() << '\n';

	return 0;
}
#endif // What_are_part2



#ifdef Implicit_conversions_for__non_type__template_arguments
#include <iostream>

template <int N> // int non-type template parameter
void print()
{
	std::cout << N << '\n';
}

int main()
{
	print<5>(); // no conversion necessary
	print<'c'>(); // 'c' converted to type int, prints 99

	return 0;
}
#endif // Implicit_conversions_for__non_type__template_arguments



#ifdef Type_deduction_for__non_type__template_parameters_using_auto // C++17
#include <iostream>

template <auto N> // deduce non-type template parameter from template argument
void print()
{
	std::cout << N << '\n';
}

int main()
{
	print<5>(); // N deduced as int `5`
	print<'c'>(); // N deduced as char `c`

	return 0;
}
#endif // Type_deduction_for__non_type__template_parameters_using_auto



#ifdef Question_1
#endif // Question_1
// define your factorial() function template here
template <int N>
constexpr int factorial()
{
	static_assert(N >= 0);

	int product{1};

	for (int i{2}; i <= N; ++i)
		product *= i;

	return product;
}

int main()
{
	static_assert(factorial<0>() == 1);
	static_assert(factorial<1>() == 1);
	static_assert(factorial<2>() == 1);
	static_assert(factorial<3>() == 1);


	static_assert(factorial<3>() == 6);
	static_assert(factorial<5>() == 120);
}


