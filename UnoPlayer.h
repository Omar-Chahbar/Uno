#pragma once
#include <string>
#include "OrderedList.h"
#include "UnoCard.h"
#include "Queue.h"
using namespace std;

class UnoPlayer {

private:
	string m_name;
	OrderedList <UnoCard> m_hand;	//OrderedList to store the cards in the payer's hand
	friend std::ostream& operator<<(std::ostream& os, const UnoPlayer &c);	//Overload the ostream to print the player's hand


public:
	UnoPlayer(string name, Queue<UnoCard> deck, int numCards);
	UnoPlayer() {}
	~UnoPlayer(){}
	UnoCard playCard(UnoCard top, int maxNumber);	//Places a card from the player's hand into the pile
	void setName(string name);	//Sets the name
	string getName() const;	//Returns the name
	void getHand(Queue<UnoCard> &deck, int numCards);	//Adds a specified amount of cards to the player's hand
	int getSize() const;	//Returns the amount of cards in the player's hand
};