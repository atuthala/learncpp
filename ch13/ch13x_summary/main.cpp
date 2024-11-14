#ifdef Question_1
#include <iostream>
#include <string>
#include <string_view> // C++17

// Our monster struct represents a single monster

struct Monster
{
	// Define our defferent monster types as an enum
	enum Type
	{
		ogre,
		dragon,
		orc,
		giant_spider,
		slime,
	};

	Type type{};
	std::string name{}; // the Monster should be an owner of its name
	int health{};
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
constexpr std::string_view getMonsterTypeString(Monster::Type type)
{
	switch(type)
	{
	case Monster::ogre: return "Ogre";
	case Monster::dragon: return "Dragon";
	case Monster::orc: return "Orc";
	case Monster::giant_spider: return "Giant Spider";
	case Monster::slime: return "Slime";
	}

	return "Unknown";
}

// Print our monster's stats
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<
		" is named " << monster.name <<
		" and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{Monster::ogre, "Torg", 145};
	Monster slime{Monster::slime, "Blurp", 23};

	printMonster(ogre);
	printMonster(slime);

	return 0;
}
#endif // Question_1



#ifdef Question_3
#endif // Question_3
#include <iostream>

template <typename T>
struct Triad
{
	T first {};
	T second {};
	T third {};
};

// If using C++17, we need to provide a deduction guide (not required in C++20)
// A Triad with three arguments of the same type should deduce to a Triad<T>
// template <typename T>
// Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& t)
{
	std::cout << '[' << t.first << ", " << t.second << ", " << t.third << ']';
}

int main()
{
	Triad t1{1, 2, 3};
	print(t1);

	Triad t2{1.2, 3.4, 5.6};
	print(t2);

	std::cout << '\n';
	return 0;
}























