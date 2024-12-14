// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
#ifdef Question2_step2
#include <cassert>
#include <iostream>
#include <string_view>
#include <type_traits> // for std::is_integral and std::is_enum
#include <vector>

namespace Items
{
	enum Type: int
	{
		health_potion,
		torch,
		arrow,
		max_items
	};
}

std::string_view getItemNamePlural(Items::Type type)
{
	switch(type)
	{
		case Items::health_potion: return "health potions";
		case Items::torch: return "torches";
		case Items::arrow: return "arrows";

		default: return "???getItemNamePlural???";
	}
}

std::string_view getItemNameSingular(Items::Type type)
{
	switch(type)
	{
	case Items::health_potion: return "health potion";
	case Items::torch: return "torch";
	case Items::arrow: return "arrow";

	default: return "???getItemNameSingular???";
	}
}

// Helper function to convert `value` into an object of type std::size_t
// UZ is the suffix for literals of type std::size_t.
template <typename T>
constexpr std::size_t toUZ(T value)
{
	// make sure T is an integral type
	static_assert(std::is_integral<T>() || std::is_enum<T>());

	return static_cast<std::size_t>(value);
}

void printInventoryItem(const std::vector<int>& inventory, Items::Type type)
{
	bool plural { inventory[toUZ(type)] != 1};
	std::cout << "You have " << inventory[toUZ(type)] << ' ';
	std::cout << (plural ? getItemNamePlural(type) : 
		getItemNameSingular(type)) << '\n';
}

// Inventory items should have integral quantities, so we don't need a function template here
int countTotalItems(const std::vector<int>& inventory)
{
	int sum{0};
	for (auto e: inventory)
		sum += e;
	return sum;
}

int main()
{
	std::vector inventory{1, 5, 10};
	assert(std::size(inventory) == Items::max_items); // make sure our inventory has the correct number of initializers


	// Sice we can't iterate over an enumerated type using a range-for, we'll need to use a traditional for-loop here
	for (int i=0; i < Items::max_items; ++i)
	{
		auto item{static_cast<Items::Type>(i)};
		printInventoryItem(inventory, item);
	}

	std::cout << "You have " << countTotalItems(inventory) << " total items\n";

	return 0;
}
#endif // Question2_step2



#ifdef Question3
#include <iostream>
#include <vector>

template<typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
	std::size_t min{0};
	std::size_t max{0};
	for (std::size_t index{0}; index < v.size(); ++index)
	{
		if (v[index] < v[min])
			min = index;
		if (v[index] > v[max])
			max = index;
	}

	return {min, max};
}

template <typename T>
void printArray(const std::vector<T>& v)
{
	bool comma{false};
	std::cout << "With array ( ";
	for (const auto& e: v)
	{
		if (comma)
			std::cout << ", ";

		std::cout << e;
		comma = true;
	}
	std::cout << " ):\n";
}

int main()
{
	std::vector v1{3, 8, 2, 5, 7, 8, 3};
	printArray(v1);

	auto m1{findMinMaxIndices(v1)};
	std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
	std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';

	std::cout << '\n';

	std::vector v2 {5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
	printArray(v2);

	auto m2{findMinMaxIndices(v2)};
	std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
	std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n';
}
#endif // Question3



#ifdef Question4
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
	std::size_t min{0};
	std::size_t max{0};
	for (std::size_t index{0}; index < v.size(); ++index)
	{
		if (v[index] < v[min])
			min = index;
		if (v[index] > v[max])
			max = index;
	}

	return {min, max};
}

template <typename T>
void printArray(const std::vector<T>& v)
{
	bool comma{false};
	std::cout << "With array ( ";
	for (const auto& e: v)
	{
		if (comma)
			std::cout << ", ";

		std::cout << e;
		comma = true;
	}
	std::cout << " ):\n";
}

int main()
{
	std::vector<int> v1{};
	std::cout << "Enter numbers to add (use -1 to stop): ";

	while(true)
	{
		int input{};
		std::cin >> input;
		if (input == -1)
			break;

		if (!std::cin) // if the previous extraction failed
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
			continue;
		}

		v1.push_back(input);
	}

	// If the array is empty
	if (v1.size() == 0)
	{
		std::cout << "The array has no elements\n";
	}
	else
	{
		printArray(v1);

		auto m1{findMinMaxIndices(v1)};
		std::cout << "The min elements has index " << m1.first << " and value " << v1[m1.first] << '\n';
		std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';
	}

	return 0;
}
#endif // Question4



#ifdef Question5
#include <iostream>
#include <string_view>
#include <vector>
#include "Random.h"

namespace Settings
{
	constexpr int wrongGuessesAllowed{6};
}

namespace WorldList
{
	// Define your list of words here
	std::vector<std::string_view> words{"mystery", "broccoli", "account", 
	"almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

	std::string_view getRandomWorld()
	{
		return words[Random::get<std::size_t>(0, words.size() - 1)];
	}
}

class Session
{
private:
	// Game session data
	std::string_view m_word {WorldList::getRandomWorld()};
	int m_wrongGuessesLeft{Settings::wrongGuessesAllowed};
	std::vector<bool> m_letterGuessed{std::vector<bool>(26)};

	std::size_t toIndex(char c) const 
	{
		return static_cast<std::size_t>((c%32) - 1);
	}

public:
	std::string_view getWord() const { return m_word; }

	int wrongGuessesLeft() const { return m_wrongGuessesLeft;}
	void removeGuess() {--m_wrongGuessesLeft;}

	bool isLetterGuessed(char c) const 	{return m_letterGuessed[toIndex(c)]; }
	void setLetterGuessed(char c) {m_letterGuessed[toIndex(c)] = true;}

	bool isLetterInWord(char c) const
	{
		for (auto ch: m_word) // step through each letter of word
		{
			if (ch == c)
				return true;
		}

		return false;
	}

	bool won()
	{
		for (auto c: m_word) // step through each letter of word
		{
			if (!isLetterGuessed(c))
				return false;
		}

		return true;
	}
};	

void draw(const Session& s)
{
	std::cout << '\n';

	std::cout << "The word: ";
	for (auto c: s.getWord()) // step through each letter of word
	{
		if (s.isLetterGuessed(c))
			std::cout << c;
		else
			std::cout << '_';
	}

	std::cout << "   Wrong guesses: ";
	for (int i=0; i < s.wrongGuessesLeft(); ++i)
		std::cout << '+';

	for (char c='a'; c <= 'z'; ++c)
		if (s.isLetterGuessed(c) && !s.isLetterInWord(c))
			std::cout << c;

	std::cout << '\n';
}

char getGuess(const Session& s)
{
	while (true)
	{
		std::cout << "Enter your next letter: ";

		char c{};
		std::cin >> c;

		// If user did something bad, try again
		if (!std::cin)
		{
			// Fix it
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// Clear out any extraneous input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// If the user entered an invalid char, try again
		if (c < 'a' || c > 'z')
		{
			std::cout << "That wasn't a valid input. Try again.\n";
			continue;
		}

		// If the letter was already guessed, try again
		if (s.isLetterGuessed(c))
		{
			std::cout << "You already guessed that. Try again.\n";
			continue;
		}

		return c;
	}
}

void handleGuess(Session &s, char c)
{
	s.setLetterGuessed(c);

	if (s.isLetterInWord(c))
	{
		std::cout << "Yes, '" << c << "' is in the word!\n";
		return;
	}

	std::cout << "No, '" << c << "' is not in the word!\n";
	s.removeGuess();
}

int main()
{
	std::cout << "Welcome to C++man (a variant of Hangman)\n";
	std::cout << "To win: guess the word. To lose: run out of plusses.\n";

	Session s{};

	while (s.wrongGuessesLeft() && !s.won())
	{
		draw(s);
		char c{getGuess(s) };
		handleGuess(s, c);
	}

	// Draw the final state of the game
	draw(s);	

	if (!s.wrongGuessesLeft())
		std::cout << "You lost! The word was: " << s.getWord() << '\n';
	else
		std::cout << "You won!\n";

	return 0;
}
#endif // Question5



























