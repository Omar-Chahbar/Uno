#pragma once
#include "Bag.h"
#include "Stack.h"
#include "UnoPlayer.h"
#define NUM_PLAYERS 3
#define STARTING_HAND 7
#define MAX_DENOM  5


class UnoGame {

private:
	int m_numPlayers;		//Stores the number of players in the game
	int m_numCardsInHand;	//Stores how many cards the player starts with in their hand
	int m_maxCardNumber;	//Stores the highest denomination of the cards
	Queue<UnoCard> m_deck;	//Holds the cards in the deck
	Stack<UnoCard> m_playedCards;	//Holds the cards that have been played
	UnoPlayer* m_players;	//A dynamic array of players
	void pileToDeck();	//If the deck is empty the pile of cards that has been played is moved to the deck

public:
	UnoGame(int players = NUM_PLAYERS, int handSize = STARTING_HAND, int maxCard = MAX_DENOM);
	~UnoGame() {delete[] m_players;}	//Deletes the player array
	void play();	//The function that runs the game
};