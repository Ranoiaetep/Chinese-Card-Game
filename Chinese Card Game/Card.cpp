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

std::pair<std::ostream&, Card> operator<< (std::ostream& os, const Card& card)
{
    os << SuiteSymbol.at(card.suite);
    if (card.suite != Suite::Joker) {
        os << NumberSymbol.at(card.number);
    }
    else
    {
        auto print = {"Black", "Red"};
        os << *std::next(print.begin(), card.number);
    }
    return {os << ' ', card};
}

std::pair<std::ostream&, Card> operator<< (std::pair<std::ostream&, Card> last, const Card& card)
{
    auto [os, last_card] = last;
    if (last_card.suite != card.suite) {
        os << SuiteSymbol.at(card.suite);
    }
    if (card.suite != Suite::Joker) {
        os << NumberSymbol.at(card.number);
    }
    else
    {
        auto print = {"Black", "Red"};
        os << *std::next(print.begin(), card.number);
    }
    return {os << ' ', card};
}
