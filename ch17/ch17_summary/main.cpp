// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/

#ifdef Question2

#include <array>
#include <iostream>
#include <limits>
#include <string_view>
#include "../../learncppGeneral/Random.h"

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max_potions
	};

	constexpr std::array types { healing, mana, speed, invisibility}; // An array of our enumerators

	// We could put these in a struct, but since we only have two attributes we'll keep them separate for now
	// We will explicityly define the element type so we don't have to use the sv suffix
	constexpr std::array<std::string_view, max_potions> name{"healing", "mana", "speed", "invisibility"};
	constexpr std::array cost {20, 30, 12, 50};

	static_assert(std::size(types) == max_potions); // ensure 'all' contains the correct number of enumerators
	static_assert(std::size(cost) == max_potions);
	static_assert(std::size(name) == max_potions);
}

class Player
{
private:
	static constexpr int s_minStartingGold{80};
	static constexpr int s_maxStartingGold{120};

	std::string m_name{};
	int m_gold{};
	std::array<int, Potion::max_potions> m_inventory {};

public:
	explicit Player(std::string_view name):
		m_name{name},
		m_gold{Random::get(s_minStartingGold, s_maxStartingGold)}
	{
	}

	bool buy(Potion::Type type)
	{
		if (m_gold < Potion::cost[type])
			return false;

		m_gold -= Potion::cost[type];
		++m_inventory[type];
		return true;
	}

	int gold() const {return m_gold;}
	int inventory(Potion::Type p) const { return m_inventory[p]; }
};

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
	return c - '0';
}

Potion::Type whichPotion()
{
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
	char input{};
	while (true)
	{
		std::cin >> input;
		if (!std::cin)
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			ignoreLine(); // and remove the bad input
			continue;
		}

		if (input == 'q')
			return Potion::max_potions;

		// Convert the char to a number and see if it's a valid potion selection
		int val{charNumToInt(input)};
		if (val >= 0 && val < Potion::max_potions)
			return static_cast<Potion::Type>(val);

		// It wasn't a valid potion selection
		std::cout << "I didn't understand what you said. Try again: ";
		ignoreLine();
	}
}

void shop(Player &player)
{
	while (true)
	{

	std::cout << "Here is our selection for today:\n";

	for (auto p: Potion::types)
		std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';

	Potion::Type which{whichPotion()};
	if (which == Potion::max_potions)
		return;

	bool success {player.buy(which)};
	if (!success)
		std::cout << "You can not afford that.\n\n";
	else
		std::cout << "You purchased a potion of " << Potion::name[which] 
		<< ". You have " << player.gold() << " gold left.\n\n";
	}
}

void printInventory(Player& player)
{
	std::cout << "Your inventory contais: \n";

	for (auto p: Potion::types)
	{
		if (player.inventory(p) > 0)
			std::cout << player.inventory(p) 
			<< "x potion of " << Potion::name[p] << '\n';
	}

	std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

int main()
{	
	std::cout << "Welcome to Roscoe's potion emporium!\n";
	std::cout << "Enter your name: ";

	std::string name{};
	// std::getline(std::cin >> std::ws, name); // read a full line of text int name
	std::cin >> name;

	Player player{name};

	std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

	shop(player);

	std::cout << '\n';

	printInventory(player);

	std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
	return 0;
}

#endif // Question2



#ifdef Question3
#endif // Question3
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include "../../learncppGeneral/Random.h"


// Because identifiers can't start with a number, we'll use a "rank_" prefix for these
struct Card
{
	enum Rank
	{
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks
	};

	// We'll also prefix these for consistency
	enum Suit
	{
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits
	};

	// These need to be static so they are only created once per program, not once per Card
	static constexpr std::array allRanks{rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
	static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart, suit_spade};

	Rank rank{};
	Suit suit{};

	friend std::ostream& operator<<(std::ostream& out, const Card &card)
	{
		static constexpr std::array ranks{'A', 'Z', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
		static constexpr std::array suits{'C', 'D', 'H', 'S'};

		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int value() const
	{
		static constexpr std::array rankValues{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
		return rankValues[rank];
	}
};

class Deck
{
	private:
		std::array<Card, 52> m_cards {};
		std::size_t m_nextCardIndex{0};

	public:
		Deck()
		{
			std::size_t count {0};
			for (auto suit: Card::allSuits)
				for (auto rank: Card::allRanks)
					m_cards[count++] = Card{rank, suit};
		}

		void shuffle()
		{
			std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
			m_nextCardIndex = 0;
		}

		Card dealCard()
		{
			assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
			return m_cards[m_nextCardIndex++];
		}
};



int main()
{
	Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}













