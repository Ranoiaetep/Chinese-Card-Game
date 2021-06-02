//
//  Card.cpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#include "Card.hpp"
#include <iterator>

Card::Card(int suite, int number)
: suite(static_cast<Suite>(suite))
, number(number)
{}

std::string Card::ToNumberSymbol() const
{
	if (suite != Suite::Joker) {
		return NumberSymbol.at(number);
	}
	else
	{
		auto print = {"Black", "Red"};
		return *std::next(print.begin(), number - 13);
	}
}

std::pair<std::ostream&, Card> operator<< (std::ostream& os, const Card& card)
{
    os << card.ToSuiteSymbol();
	os << card.ToNumberSymbol();
    return {os << ' ', card};
}

std::pair<std::ostream&, Card> operator<< (std::pair<std::ostream&, Card> last, const Card& card)
{
    auto [os, last_card] = last;
    if (last_card.suite != card.suite) {
		os << card.ToSuiteSymbol();
    }
	os << card.ToNumberSymbol();
    return {os << ' ', card};
}
