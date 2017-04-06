#ifndef DECKOFCARD_H_INCLUDED
#define DECKOFCARD_H_INCLUDED

# include <iostream>
# include "Card.h"

using namespace std;

class deckOfCards {
public:

	deckOfCards(); 
	void shuffleCard();
	Card dealCard();
	~deckOfCards();

private:
	Card *deck = new Card[52];
	int currentCard;
};


#endif // DECKOFCARD_H_INCLUDED