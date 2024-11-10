// https://www.learncpp.com/cpp-tutorial/static-local-variables/
// 7.10 — Static local variables
#ifdef _7_10__Static_local_variables

#include <iostream>

void incrementAndPrint()
{
	static int s_value{1}; //
	++s_value;
	std::cout << s_value << '\n';
} // 


int main()
{
	incrementAndPrint();
	incrementAndPrint();
	incrementAndPrint();

	return 0;
}
#endif // _7_10__Static_local_variable


// Don’t use static local variables to alter flow
#ifdef _7_10__Dont_use_part1
#include <iostream>

int getInteger()
{
	static bool s_isFirstCall{ true };

	if (s_isFirstCall)
	{
		std::cout << "Enter an integer: ";
		s_isFirstCall = false;
	}
	else
	{
		std::cout << "Enter another integer: ";  
	}

	int i{};
	std::cin >> i;
	return i;
}


int main()
{
	int a{getInteger()};
	int b{getInteger()};

	std::cout << a << " + " << b << " = " << (a + b) << '\n';

	return 0;
}
#endif //_7_10__Dont_use_part1



#ifdef _7_10__Dont_use_part3
#include <iostream>

// We'll define a symbol constant with a nice name
constexpr bool g_firstCall{true};

int getInteger(bool bFirstCall)
{
	if (bFirstCall)
	{
		std::cout << "Enter an integer: ";
	}
	else
	{
		std::cout << "Enter another integer: ";
	}

	int i{};
	std::cin >> i;
	return i;
}


int main()
{
	int a{getInteger(g_firstCall)}; // so that it's clearer what the argument represents here
	int b{getInteger(!g_firstCall)};

	std::cout << a << " + " << b << " = " << (a + b) << '\n';

	return 0;
}
#endif // _7_10__Dont_use_part3