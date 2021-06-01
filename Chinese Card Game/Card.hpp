//
//  Card.hpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <iostream>
#include <utility>

enum class Suite
{
    Diamond,
    Club,
    Heart,
    Spade,
    Joker,
};

static const std::map<Suite, std::string> SuiteSymbol =
{
    {Suite::Diamond, "♦️"},
    {Suite::Club, "♣️"},
    {Suite::Heart, "♥️"},
    {Suite::Spade, "♠️"},
    {Suite::Joker, "🃏"},
};

struct Card
{
    Card(int, int);
    Suite suite;
    std::uint8_t number;
    friend std::pair<std::ostream&, Card> operator<< (std::ostream& os, const Card& card);
    friend std::pair<std::ostream&, Card> operator<< (std::pair<std::ostream&, Card> last, const Card& card);
    
    template<typename T>
    friend std::ostream& operator<< (std::pair<std::ostream&, Card> last, const T& t)
    {
        last.first << t;
        return last.first;
    }
};

static const std::map<std::uint8_t, char> NumberSymbol
{
    {0, '3'},
    {1, '4'},
    {2, '5'},
    {3, '6'},
    {4, '7'},
    {5, '8'},
    {6, '9'},
    {7, '0'},
    {8, 'J'},
    {9, 'Q'},
    {10, 'K'},
    {11, 'A'},
    {12, '2'},
};
