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
    std::vector<Card> cards;
    
    auto shuffle() -> void;
    auto draw() -> Card&&;
    auto has_card(){return cards.size();}
    
    friend auto operator<< (std::ostream& os, Deck& deck) -> std::ostream&;
};
