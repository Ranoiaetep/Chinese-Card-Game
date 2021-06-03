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

auto operator<< (std::ostream& os, const Card& card) -> std::pair<std::ostream&, const Card*>
{
    os << card.ToSuiteSymbol();
	os << card.ToNumberSymbol();
    return {os << ' ', &card};
}

auto operator<< (std::pair<std::ostream&, const Card*> last, const Card& card) -> std::pair<std::ostream&, const Card*>
{
    auto [os, last_card] = last;
    if (last_card->suite != card.suite)
    {
		os << card.ToSuiteSymbol();
    }
	os << card.ToNumberSymbol();
    return {os << ' ', &card};
}
