#include "UnoPlayer.h"

UnoPlayer::UnoPlayer(string name, Queue<UnoCard> deck, int numCards)
{
	m_name = name;
	for (int i = 0; i < numCards; i++)
		m_hand.insert(deck.dequeue());	//Insert cards into the player's hand from the deck
}

UnoCard UnoPlayer::playCard(UnoCard top, int maxNumber)
{

	//Check if the player has a card that has the same number as the top card
	for (unsigned int i = 1; i <= m_hand.getLength(); i++) {
		if (m_hand.retrieve(i).getDenom() == top.getDenom()) {
			UnoCard temp = m_hand.remove(i);
			return temp;
		}
	}

	//Check if the player has a card that has the same colour as the top card
	for (unsigned int i = 1; i <= m_hand.getLength(); i++) {
		if (m_hand.retrieve(i).colourToChar() == top.colourToChar()) {
			UnoCard temp = m_hand.remove(i);
			return temp;
		}
	}

	//Return a card that has a denomination greater than what is possible in the deck
	UnoCard temp(RED, maxNumber + 1);
	return temp;
}

void UnoPlayer::setName(string name)
{
	m_name = name;
}

string UnoPlayer::getName() const
{
	return m_name;
}

void UnoPlayer::getHand(Queue<UnoCard> &deck, int numCards)
{
	for (int i = 0; i < numCards; i++) {
		m_hand.insert(deck.dequeue());	//Insert cards into the player's hand from the deck
	}
}

int UnoPlayer::getSize() const
{
	return m_hand.getLength();
}

std::ostream& operator<<(std::ostream& os, const UnoPlayer &c) {
	os << c.getName() << "'s hand: " << endl;
	for (unsigned int i = 1; i <= c.m_hand.getLength(); i++) {
		os << c.m_hand.retrieve(i) << endl;
	}
	return os;
}