# include <iostream>
# include "Card.h"

using namespace std;

Card::Card(int f, int s) {

	face = f;
	suit = s;
}

void Card::printCard() {
	cout << " " << this->face << " of " << this->suit;
}