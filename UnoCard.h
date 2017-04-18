#pragma once
#include <iostream>

// User defined Suit and Denomination types (user-defined integers) 
enum Colour { RED = 1, BLUE = 2, GREEN = 3, YELLOW = 4 };

class UnoCard {
	
private:
	Colour m_colour;
	int m_denom;
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);	//Overload the ostream operator to print the card
	friend bool operator<(const UnoCard &c, const UnoCard &d);	//Overload the less than operator to compare the cards

public:
	UnoCard(){}	
	UnoCard(Colour colour, int denom) {m_colour = colour; m_denom = denom;}
	~UnoCard(){}
	Colour getColour() const;	//Returns the colour of the card
	int getDenom() const;	//returns the denomination of the card
	char colourToChar();		//Assigns the colour to a character for comparisons
};