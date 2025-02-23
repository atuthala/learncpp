#ifdef use__static_cast__to__convert__the__arguments
#include <iostream>

template <typename T>
T max(T x, T y)
{
	return (x < y) ? y : x;
}

#ifdef overload
double max(int x, int y)
{
	return x + y;
}
#endif

int main()
{
	// std::cout << max(1, 2) << '\n'; // will instantiate max(int, int)
	// std::cout << max(1.5, 2.5) << '\n'; // will instantiate max(double, double)
	#ifdef overload
		std::cout << max(2, 3.5) << '\n';
	#endif

	#ifdef static_cast
		std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)
	#endif

	return 0;
}
#endif // use__static_cast__to__convert__the_arguments



#ifdef provide__an__explicit__template__argument
#include <iostream>

template <typename T>
T max(T x, T y)
{
	return (x < y) ? y : x;
}

int main()
{
	// we've explicitly specified type double, so the compiler won't use template argument deduction
	std::cout << max<double>(2, 3.5) << '\n';

	return 0;
}
#endif // provide__an__explicit__template__argument



#ifdef function__templates__with__multiple__template__type
#include <iostream>

template <typename T, typename U> // We're using two template type parameters named	T and U
// x can resolve to type T, and y can resolve to type U
auto max(T x, U y) -> std::common_type_t<T, U>; // returns the common type of T and U

int main()
{
	std::cout << max(3, 7.8) << '\n'; // resolves to max<int, double>

	return 0;
}

template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
	return (x < y) ? y : x;
}
#endif // function__templates__with__multiple__template__type__parameters



#ifdef Abbreviated__function__templates__Cpp20
#include <iostream>
auto max(auto x, auto y)
{
	return (x < y) ? y : x;
}

int main()
{
	std::cout << max(8.3, 7) << '\n'; // resolves to max<int, double>

	return 0;
}
#endif // Abbreviated__function__templates__Cpp20



#ifdef function__templates__may__be__overloaded
#endif // function__templates__may__be__overloaded
#include <iostream>

// Add two values with matching types
template <typename T>
auto add(T x, T y)
{
	return x + y;
}

// Add two values with non-matching types
// As of C++20 we could also use auto add(auto x, auto y)
template <typename T, typename U>
auto add(T x, U y)
{
	return x + y;
}

// Add three values with any type
// As of C++20 we could also use auto add(auto x, auto y, auto z)
template<typename T, typename U, typename V>
auto add(T x, U y, V z)
{
	return x + y + z;
}

int main()
{
	std::cout << add(1.2, 3.4) << '\n'; // instantiates and calls add<dobule>()
	std::cout << add(5.6, 7) << '\n'; // instantiates and calls add<double,int>()
	std::cout << add(8, 9, 10) << '\n'; // instantiates and calls add<int, int, int>()
}




