#ifdef Question_1
#include <iostream>

namespace Constants
{
	constexpr double gravity{9.8};
}

//
double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

// Returns the current ball height after "seconds" seconds
double calculateBallHeight(double towerHeight, int seconds)
{
	const double fallDistance{ Constants::gravity * (seconds * seconds) / 2.0};
	const double ballHeight { towerHeight - fallDistance };

	if (ballHeight < 0.0)
		return 0.0;

	return ballHeight;
}

void printBallHeight(double ballHeight, int seconds)
{
	if (ballHeight > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";	
}


double calculateAndPrintBallHeight(double towerHeight, int seconds)
{
	double ballHeight{calculateBallHeight(towerHeight, seconds)};
	printBallHeight(ballHeight, seconds);

	return ballHeight;
}


int main()
{
	double towerHeight{getTowerHeight()};

	int seconds{0};
	while (calculateAndPrintBallHeight(towerHeight, seconds) > 0.0)
	{
		++seconds;
	}

	return 0;
}
#endif // Question_2



#ifdef Question_2
//Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert>
#include <cmath> // for std::sqrt
#include <iostream>

bool isPrime1(int x)
{
	if (x <= 1) // if x is negative, 0, or 1 then the number is not prime
		return false;

	if (x == 2)
		return true;

	for (int test{3}; test < std::sqrt(x); test+=2)
	{
		if (x % test == 0) // if x is evenly divisible
			return false;
	}

	return true; // if we didn't find any divisors, then x must be prime
}

// optimized version
bool isPrime2(int x)
{
	if (x <= 1) // if x is negative, 0, or 1 then the number is not prime
		return false;

	if (x == 2)		// the number 2 is the only even prime
		return true;

	if (x % 2 == 0) // any other even number is not prime
		return false;

	// For any number 3 or greater, test odd valus (this is why we add 2)
	// between 3 and sqrt(x) to see if they are a divisor
	// Also see 
	//https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-the-number-is
	//https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-the-number-is

	for (int test{3}; test * test < x; test+=2)
	{
		if (x % test == 0) // if x is evenly divisible
			return false; // then this number isn't prime
	}

	return true; // if we didn't find any divisors, then x must be prime
}

// optimized version
bool isPrime(int x)
{
    if (x <= 1)     // if x is negative, 0, or 1 then the number is not prime
        return false;
    if (x == 2)     // the number 2 is the only even prime
        return true;
    if (x % 2 == 0) // any other even number is not prime
        return false;

    // For any number 3 or greater, test odd values (this is why we add 2)
    // between 3 and sqrt(x) to see if they are a divisor
    // Also see https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-the-number-is
    // Since test >= 0 and x >=0, we can optimize test < std::sqrt(x) to test * text < x
    for (int test{ 3 }; test * test <= x; test += 2)
    {
        if (x % test == 0) // if x is evenly divisible
            return false;  // then this number isn't prime
    }

    return true; // if we didn't find any divisors, then x must be prime
}

int main()
{
	assert(!isPrime(0)); // terminate porgram if isPrime(0) is true
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!\n";

	return 0;
}
#endif // Question_2



#ifdef Question_3
#endif // Question_3
#include <iostream>
#include "Random.h" // https://www.learncpp.com/cpp-tutorial/global-random-numbers-random-h/

// returns true if the user won, false if they lost
bool playHiLo(int guesses, int min, int max)
{
	std::cout << "Let's play a game. I'm thinking of a number between "  
	<< min << " and " << max 
	<< ". You have " << guesses << " tries to guess what it is.\n";
	int number{Random::get(min, max)}; // this is the number the user needs to guess

	// Loop through all of the guesses
	for (int count{1}; count <= guesses; ++count)
	{
		std::cout << "Guess #" << count << ": ";

		int guess{};
		std::cin >> guess;

		if (guess > number)
			std::cout << "Your guess is too high.\n";
		else if (guess < number)
			std::cout << "Your guess is too low.\n";
		else // guess == number, so the user won
		{
			std::cout << "Correct! You win!\n";
			return true;
		}
	}

	// The user lost
	std::cout << "Sorry, you lose. The correct number was " << number << '\n';
	return false;
}

bool playAgain()
{
	// Keep asking the user if they want to play again until they pick y or n.
	while (true)
	{
		char ch{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;

		switch(ch)
		{
		case 'y': return true;
		case 'n': return false;
		}
	}
}


int main()
{
	constexpr int guesses{7}; // the user has this many	guesses
	constexpr int min {1};
	constexpr int max {100};

	do
	{
		playHiLo(guesses, min, max);
	} while (playAgain());

	std::cout << "Thank you for palying.\n";

	return 0;
}








