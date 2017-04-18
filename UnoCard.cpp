#include "UnoCard.h"

std::ostream& operator<<(std::ostream& os, const UnoCard &c) {
	int Colour = c.m_colour;
	switch (Colour) {
	case 1: os << "RED"; break;
	case 2: os << "BLUE"; break;
	case 3: os << "GREEN"; break;
	case 4: os << "YELLOW"; break;
	}

	os << "-" << c.m_denom;
	return os;

}

bool operator<(const UnoCard & c, const UnoCard & d)
{
	if (c.getColour() == d.getColour())
		return c.getDenom() < d.getDenom();
	return c.getColour() < d.getColour();
}

Colour UnoCard::getColour() const
{
	return m_colour;
}

int UnoCard::getDenom() const
{
	return m_denom;
}

char UnoCard::colourToChar()
{
	if(m_colour == RED)   return 'R';
	else if (m_colour == BLUE)    return 'B';
	else if (m_colour == YELLOW)   return 'Y';
	else  return 'G';
}