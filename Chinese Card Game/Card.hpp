//
//  Card.hpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#pragma once

#include <array>
#include <string>
#include <cstdint>
#include <iostream>
#include <utility>
#include <string_view>

enum class Suite
{
    Diamond,
    Club,
    Heart,
    Spade,
    Joker,
};

static constexpr std::array<std::string_view, 5> SuiteSymbol
{"♦️", "♣️", "♥️", "♠️", "🃏"};

static constexpr std::array<std::string_view, 15> NumberSymbol
{"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "Black", "Red"};

struct Card
{
    Card(int, int);
    Suite suite;
    std::uint8_t number;
    
	auto operator< (const Card& card) const { return number < card.number;}
	auto operator== (const Card& card) const { return number == card.number;}
    auto operator- (const Card& card) const { return number - card.number;}
	
    auto ToNumberSymbol() const { return NumberSymbol[number];}
    auto ToSuiteSymbol() const { return SuiteSymbol[static_cast<int>(suite)];}

    friend auto operator<< (std::ostream& os, const Card& card) -> std::pair<std::ostream&, const Card*>;
    friend auto operator<< (std::pair<std::ostream&, const Card*> last, const Card& card) -> std::pair<std::ostream&, const Card*>;
    
    template<typename T>
    friend std::ostream& operator<< (std::pair<std::ostream&, const Card*> last, const T& t)
    {
        last.first << t;
        return last.first;
    }
};
