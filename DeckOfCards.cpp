# include <iostream>
# include "DeckOfCards.h"
# include "Card.h"


using namespace std;

deckOfCards::deckOfCards() {

	static int x = 0;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 13; ++j) {
			this->deck[x] = Card(j, i);
			++x;
			currentCard = 52;
		}
	}
}


void deckOfCards::shuffleCard() {

	Card temp;
	for (int i = 0; i < 1000; i++) {

		int firstCard = rand() % 52;
		int secondCard = rand() % 52;
		temp = this->deck[firstCard];
		deck[firstCard] = deck[secondCard];
		deck[secondCard] = temp;
	}
}

Card deckOfCards::dealCard() { 
							  
		cout << "\nDealing card ";
		currentCard -= 1;
		return deck[currentCard];
}

deckOfCards::~deckOfCards() {

	delete[]deck;
}