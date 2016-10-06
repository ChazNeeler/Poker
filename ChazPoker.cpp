#include <cstdlib>
//#include <conio.h>
#include <iostream>
//#include <windows.h>
#include <time.h>
#include "Deck.h"

using namespace std;


int main()
{
	srand(time(NULL)); //seed RNG

	Card *Deck = new Card[52];
	Card *Hand = new Card[5];
	int Discard, Score, Players;
	char again;

	Deck = Initalize(Deck);  //setup our deck

	//player loop

	do
	{
		system("cls");


		for (int x = 0; x < 10; x++)
		{
			Deck = Shuffle(Deck);
		}

		Hand = Deal(Deck);

		cout << "Please enter the amount of cards to be discarded:  ";
		cin >> discard;
		while (Discard < 0 || Discard > 5)
		{
			cout << "Invalid discard amount entered.  Please enter a valid amount of cards to be discarded:  ";
			cin >> discard;
		}

		Hand = Discard(Hand, discard);
		Hand = ReDeal(Deck, Hand);

		Score = Total(Hand);
		
		cout << "You have a: " << ScoreTotal[Score] << endl << "Would you like to continue?" << endl << "Please enter Y/N: ";
		cin >> again;
	} while (again == 'y');

	return 0;
}