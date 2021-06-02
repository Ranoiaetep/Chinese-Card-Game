//
//  Hand.hpp
//  Chinese Card Game
//
//  Created by Ranoiaetep on 6/1/21.
//

#pragma once
#include <set>
#include <initializer_list>
#include <map>
#include <string>
#include "Card.hpp"

//struct Card;

enum class Hands
{
	High,
	Pair,
	Three,
	Three_plus_one,
	Three_plus_two,
	Four_plus_ones,
	Four_plus_twos,
	Plane,
	Straight,
	Bomb,
	Jokers,
};

static const std::map<Hands, std::string> HandsSymbol
{
	{Hands::High, "一张"},
	{Hands::Pair, "一对"},
	{Hands::Three, "三张"},
	{Hands::Three_plus_one, "三带一"},
	{Hands::Three_plus_two, "三带二"},
	{Hands::Four_plus_ones, "四代一"},
	{Hands::Four_plus_twos, "四带二"},
	{Hands::Plane, "飞机"},
	{Hands::Straight, "顺子"},
	{Hands::Bomb, "炸弹"},
	{Hands::Jokers, "王炸"},
};

struct Hand
{
	Hand(std::initializer_list<Card>);
	Hands checkHand();
	Hands hand;
	std::set<Card> cards;
};
