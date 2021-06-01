//
//  Deck.hpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#pragma once

#include <vector>
#include <iostream>
#include "Card.hpp"

struct Deck
{
    Deck(bool shuffles = true);
    std::vector<Card> deck;
    void shuffle();
    Card&& draw();
    bool has_card(){return deck.size();}
    friend std::ostream& operator<< (std::ostream& os, Deck deck);
};
