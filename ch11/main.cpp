// Chapter 11
//11.3 — Function overload resolution and ambiguous matches
//https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/

#ifdef _11_3__Matching_for_functions
#include <iostream>

void print(char, double)
{
	std::cout << 'b' << '\n';
}

void print(char, int)
{
	std::cout << 'a' << '\n';
}

void print(char, float)
{
	std::cout << 'c' << '\n';
}

int main()
{
	print('x', 'a');

	return 0;
}
#endif //_11_3__Matching_for_functions



#ifdef _11_3__Ambiguous_matches
void foo(unsigned int)
{
}

// void foo(float)
// {
// }

int main()
{
    foo(0); // int can be numerically converted to unsigned int or to float
    foo(3.14159); // double can be numerically converted to unsigned int or to float

    return 0;
}
#endif // _11_3__Ambiguous_matches



//11.4 — Deleting functions
//https://www.learncpp.com/cpp-tutorial/deleting-functions/
#ifdef _11_4__Deleting_a_function
#include <iostream>

void printInt(int x)
{
	std::cout << x << '\n';
}

// void printInt(char) = delete; // calls to this function will halt compilation
// void printInt(bool) = delete;

int main()
{
	printInt(97); // okay

	printInt('a');
	printInt(true);

	printInt(5.0);

	return 0;
}
#endif // 11_4__Deleting_a_function



#ifdef _11_4__Deleting_all_non_matching_overloads
#include <iostream>
// This function will take precedence for arguments of type int
void printInt(int x)
{
	std::cout << x << '\n';
}

template <typename T>
void printInt(T x) = delete;

int main()
{
	printInt(97); // okay
	printInt('a'); // compile error
	printInt(true); // compile error

	return 0;
}
#endif // _11_4__Deleting_all_non_matching_overloads



//11.5 — Default arguments
//https://www.learncpp.com/cpp-tutorial/default-arguments/
#ifdef _11_5__Multiple_default_arguments
#include <iostream>
#include <string_view>

void print(int x=10, int y=20, int z=30)
{
	std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

void printUser(std::string_view sv="Hello", double d=10.0);

int main()
{
	print(1, 2, 5);
	print(1, 2);
	print(1);
	print();


	std::cout << '\n';

	printUser(,37.2);

	return 0;
}


void printUser(std::string_view sv, double d)
{
	std::cout << "User name: " << sv << '\n';
	std::cout << "User number: " << d << '\n';
}
#endif // _11_5__Multiple_default_arguments



#ifdef _11_5__Default_arguments_can_not_be_redeclared
#include "foo.h"
#include <iostream>

void print(int x, int y) 
{
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
}

int main()
{
	print(3);	;

	return 0;
}
#endif // _11_5__Default_arguments_can_not_be_redeclared


//
//https://www.learncpp.com/cpp-tutorial/function-templates/#google_vignette
#ifdef _11_6__Function_templates
template <typename T> // this is template parameter declaration
T max(T x, T y)
{
	return (x < y) ? y : x;
	// Note: we use < instead of > because std::max uses <
}
#endif // _11_6__Function_templates



//https://www.learncpp.com/cpp-tutorial/function-templates/#google_vignette
//11.7 — Function template instantiation
#ifdef _11_7__Using_a_function_template
#include <iostream>

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T max(T x, T y);

template<>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
	return (x < y) ? y : x;
}


int main()
{
	std::cout << max<int>(1, 2) << '\n'; //instantiates and calls function max<int>(int, int)

	return 0;
}
#endif // _11_7__Using_a_function_template



#ifdef _11_7__Template_argument_deduction
#include <iostream>
template<typename T>
T max(T x, T y)
{
	std::cout << "called max<int>(int, int)\n";
	return (x < y) ? y : x;
}

int max(int x, int y)
{
	std::cout << "called max(int, int)\n";
	return (x < y) ? y : x;
}

//
template <typename T>
void print(T x)
{
	std::cout << x; //
}

//
//
void print(bool x)
{
	std::cout << std::boolalpha << x; //
}




int main()
{
	std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
	std::cout << max<>(1, 2) << '\n'; // deduces max<int>(int, int) (non-template functions not considered)
	std::cout << max(1, 2) << '\n';


	print<bool>(true); //
	std::cout << '\n';

	print<>(true); //
	std::cout << '\n';

	print(true); //
	std::cout << '\n';

	return 0;
}
#endif // _11_7__Template_argument_deduction



#ifdef _11_7__Function_templates_with__non_template_parameters
template <typename T>
int someFcn(T, double)
{
	return 5;
}

int main()
{
	someFcn(1, 3.4);
	someFcn(1, 3.4f);
	someFcn(1.2, 3.4);
	someFcn(1.2f, 3.4);
	someFcn(1.2f, 3.4f);

	return 5;
}
#endif // 11_7__



#ifdef _11_7__Instantiated_functions_may_not
#include <iostream>
#include <string>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
// const char* will match a string literal
template <>
const char* addOne(const char* x) = delete;

int main()
{
    std::cout << addOne("Hello, world!") << '\n'; // compile error

    return 0;
}
#endif // _11_7__


#ifdef _11_7__Function_templates_and_default_arguments_for_non_template_parameters
#include <iostream>

template <typename T>
void print(T val, int times=1)
{
	while (times--)
	{
		std::cout << val;
	}
}

int main()
{
	print(5);
	print('a', 3);

	return 0;
}
#endif // _11_7__



#ifdef c_strings
//Магистерский курс C++ (МФТИ, 2022-2023). Лекция 1. Строки.
//https://www.youtube.com/watch?v=9N_wJ7oIHDk
#include <iostream>
int main()
{
	std::cout << R"(H
	e
	l
	l
	o)" << std::endl;
}
#endif // c_strings



#ifdef _11_7__Beware_function_templates_with_modifiable_static_local_variables
#include <iostream>

// Here's a function template with a static local variable that is modified
template <typename T>
void printIDAndValue(T value)
{
	static int id{};
	std::cout << ++id << ") " << value << '\n';
}

int main()
{
	printIDAndValue(12);
	printIDAndValue(13);

	printIDAndValue(14.5);
	printIDAndValue(14.5);
	printIDAndValue(14.5);

	return 0;
}
#endif // _11_7__Beware_function_templates_with_modifiable_static_local_variables