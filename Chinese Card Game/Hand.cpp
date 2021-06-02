//
//  Hand.cpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#include "Hand.hpp"

Hand::Hand(std::initializer_list<Card> cards)
: cards(cards)
{}

Hands Hand::checkHand()
{
	
	return Hands::High;
}
