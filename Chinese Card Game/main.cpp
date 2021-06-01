//
//  main.cpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"

int main(int argc, const char * argv[])
{
    Deck d{0};
    std::cout << d << "\n";
    auto c = d.draw();
    std::cout << c << "\n" << d << "\n";
    return 0;
}
