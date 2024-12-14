#ifdef Question222
#include <iostream>

class Fraction
{
private:
	int m_numerator{0};
	int m_denominator{1};

public:
	explicit Fraction(int numerator=0, int denominator=1)
	: m_numerator{numerator}, m_denominator{denominator}
	{

	}

	void getFraction()
	{
		std::cout << "Enter a value for numerator: ";
		std::cin >> m_numerator; // this is a member function, so we can access members directly
		std::cout << "Enter a value for denominator: ";
		std::cin >> m_denominator;
		std::cout << '\n';
	}

	Fraction multiply(const Fraction& f) const
	{
		return Fraction{m_numerator * f.m_numerator, m_denominator * f.m_denominator};
	}

	void printFraction() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

int main()
{
	Fraction f1{};
	f1.getFraction();

	Fraction f2{};
	f2.getFraction();

	std::cout << "Your fraction multiplied together: ";

	f1.multiply(f2).printFraction();

	return 0;
}
#endif // Qeustion222



#ifdef Question_1
#include <cmath>
#include <iostream>

class Point2d
{
private:
	double m_x{0.0};
	double m_y{0.0};

public:
	Point2d() = default;

	Point2d(double x, double y)
	: m_x{x}, m_y{y}
	{}

	void print() const
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	double distanceTo(const Point2d& other) const
	{
		return std::sqrt(
			(m_x - other.m_x)*(m_x - other.m_x) +
			(m_y - other.m_y)*(m_y - other.m_y)
			);
	}
};



int main()
{
	Point2d first{};
	Point2d second{3.0, 4.0};

	Point2d third{4.0}; // should error if uncomented

	first.print();
	second.print();

	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	return 0;
}
#endif // Question_1



#ifdef Question_2
#include <iostream>

class Fraction
{
private:
	int m_numerator{0};
	int m_denominator{1};

public:
	explicit Fraction(int numerator=0, int denominator=1)
		: m_numerator{numerator}, m_denominator{denominator}
		{}

	void getFraction()
	{
		std::cout << "Enter a value for numerator: ";
		std::cin >> m_numerator; // this is a member function, so we can access members directly
		std::cout << "Enter a value for denominator: ";
		std::cin >> m_denominator;
		std::cout << '\n';
	}

	Fraction multiply(const Fraction& f) const
	{
		return Fraction{m_numerator * f.m_numerator, m_denominator * f.m_denominator};
	}

	void printFraction() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

int main()
{
	Fraction f1{};
	f1.getFraction();

	Fraction f2{};
	f2.getFraction();

	std::cout << "Your fractions multiplied together: ";

	f1.multiply(f2).printFraction();

	return 0;
}
#endif // Question_2
	





