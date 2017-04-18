#include "UnoGame.h"
#include <time.h>

void UnoGame::pileToDeck()
{
	UnoCard temp = m_playedCards.pop();	//Store the top of the pile

	while (!m_playedCards.isEmpty())
		m_deck.enqueue(m_playedCards.pop());	//Move all the cards in the pile to the deck
	m_playedCards.push(temp);	//Put the card back into the stack
}

UnoGame::UnoGame(int players, int handSize, int maxCard)
{
	Bag<UnoCard> m_bagOfCards(8*maxCard);	//Holds the cards and randomizes them before they are placed in the deck
	srand(time(NULL));
	//Initialize member variables
	m_maxCardNumber = maxCard;
	m_numCardsInHand = handSize;
	m_numPlayers = players;
	m_players = new UnoPlayer[m_numPlayers];
	

	//Give each player a name
	for (int i = 1; i <= m_numPlayers; i++)
		m_players[i - 1].setName("Player " + std::to_string(i));


	//Populate the bag with 2 of each card
	Colour c[] = { RED,BLUE,GREEN,YELLOW};
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= m_maxCardNumber; j++) {
			UnoCard card(c[i], j);
			m_bagOfCards.add(card);
			m_bagOfCards.add(card);
		}
	}

	//Place all the cards in the bag into the deck
	while(!m_bagOfCards.isEmpty()) {
		m_deck.enqueue(m_bagOfCards.getOne());
	}

	//Populate each player's hand
	for (int i = 0; i < m_numPlayers; i++)
		m_players[i].getHand(m_deck, m_numCardsInHand);

	//Place one card in the face up pile
	m_playedCards.push(m_deck.dequeue());
}

void UnoGame::play()
{
	cout << "WELCOME TO UNO!" << endl << endl << endl;

	//Print the top card
	cout << "START : The first card is a " << m_playedCards.peek() << endl << endl;

	bool gameOver = false;
	int playerNumber = 0;	//Stores which player's turn it is

	while (!gameOver) {

		cout << "It is " << m_players[playerNumber].getName() << "'s turn: " << endl;
		//Store the played card as a temp
		UnoCard temp = m_players[playerNumber].playCard(m_playedCards.peek(), m_maxCardNumber);

		//If the card is 1 greater than  the max denomination, the player must draw a card
		if (temp.getDenom() == m_maxCardNumber + 1) {
			if (m_deck.isEmpty()) {
				pileToDeck();
				cout << "The pile was moved to the deck." << endl << endl;
			}
			m_players[playerNumber].getHand(m_deck, 1);
			cout << m_players[playerNumber].getName() << " Drew a card" << endl << endl;

		}
		//Otherwise put that card on the pile
		else {
			m_playedCards.push(temp);
			cout << m_players[playerNumber].getName() << " Played a " << temp << endl << endl;
		}

		//If the player only has 1 card left call Uno
		if (m_players[playerNumber].getSize() == 1)
			cout << m_players[playerNumber].getName() << " Called UNO!" << endl << endl;
		//If the player has no cardds left set the game to be over and break out of the loop
		if (m_players[playerNumber].getSize() == 0) {
			gameOver = true;
			cout << m_players[playerNumber].getName() << " Won the game!" << endl;
			break;
		}
		
		playerNumber++;

		//If the last player has played, set playerNumber back to 0
		if (playerNumber == m_numPlayers)
			playerNumber = 0;
	}
}