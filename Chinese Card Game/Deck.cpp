//
//  Deck.cpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#include "Deck.hpp"
#include <algorithm>
#include <iterator>
#include <random>

Deck::Deck(bool shuffles)
{
    cards.reserve(54);
    std::generate_n(std::back_inserter(cards), 54, [index = 54]() mutable {
        --index;
        return Card(index / 13, index % 13 + index / 52 * 13);
    });
    if (shuffles) {
        shuffle();
    }
}

auto Deck::shuffle() -> void
{
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

auto Deck::draw() -> Card&&
{
    auto&& temp = std::move(cards.back());
    cards.pop_back();
    return std::move(temp);
}

auto operator<< (std::ostream& os, Deck& deck) -> std::ostream&
{
    if (deck.cards.size())
    {
        auto o = os << *deck.cards.rbegin();
        for(auto it = std::next(deck.cards.rbegin()); it != deck.cards.rend(); std::advance(it, 1))
            o.second = (o << *it).second;
    }
    else
    {
        os << "Deck empty.";
    }
    return os;
}
