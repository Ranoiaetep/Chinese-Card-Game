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
    std::generate_n(std::back_inserter(deck), 54, [index = 54]() mutable {
        --index;
        return Card(index / 13, index % 13);
    });
    if (shuffles) {
        shuffle();
    }
}

void Deck::shuffle()
{
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

Card&& Deck::draw()
{
    auto&& temp = std::move(deck.back());
    deck.pop_back();
    return std::move(temp);
}

std::ostream& operator<< (std::ostream& os, Deck deck)
{
    if (deck.deck.size())
    {
        auto o = os << *deck.deck.rbegin();
        for(auto it = std::next(deck.deck.rbegin()); it != deck.deck.rend(); std::advance(it, 1))
            o.second = (o << *it).second;
    }
    else
    {
        os << "Deck empty.";
    }
    return os;
}
