// https://www.learncpp.com/cpp-tutorial/static-local-variables/
// 7.10 — Static local variables
#ifdef _7_10__Static_local_variables
#endif // _7_10__Static_local_variable

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