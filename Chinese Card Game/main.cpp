//
//  main.cpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#include <iostream>
#include "Deck.hpp"

int main(int argc, const char * argv[])
{
    Deck deck{0};
    std::cout << deck << "\n";
    auto card = deck.draw();
    std::cout << card << "\n" << deck << "\n";
    return 0;
}
