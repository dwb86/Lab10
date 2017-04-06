# include <iostream>
# include <stdlib.h>
# include <ctime>
# include <iomanip>
# include "Card.h"
# include "DeckOfCards.h"

using namespace std;

int main() {
	srand(time(0));
	// make a dreck of cards, shuffle cards, deal cards
	deckOfCards deck;
	deck.shuffleCard();
	Card dealtCard;
	for (int i = 0; i < 2; i++) {
		dealtCard = deck.dealCard();
		dealtCard.printCard();
	}
	cout << endl << endl;
	system("pause");
	return 0;

}