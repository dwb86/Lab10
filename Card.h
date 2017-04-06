#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
using namespace std;


class Card {
public:
	Card(int = 0, int = 0); 
	void printCard(); 

private:
	int face;
	int suit;
};




#endif // HEADER_H_INCLUDED