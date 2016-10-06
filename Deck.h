using namespace std;

const char *VictoryCondition[10] = { "High card" "Two of a Kind" " Three of a Kind" "Four of a Kind" "Two Pair" "Full House" "Straight" "Flush" "Straight Flush" "Royal Flush" };
const char *Suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
const char *Weight[10] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King",};
int Counter = 0;

class Card {

	private:
		Card *Card;
		int weight;
		int suit;

	public:
		Card();
		Card *GetCard() {return Card;}
		int SetSuit() { return Suit; }
		int SetWeight() { return Weight; }
		void SetCard(int a_Suit, int a_Weight);
};

void Card::SetCard(int a_Suit, int a_Weight)
{
	Suit = a_Suit;
	Weight = a_Weight;
}

Card * Shuffle(Card *Deck)
{
	Card *Stack = new Card[52];
	for (int x = 0; x < 52; x++)
		{
			Stack[x] = Deck[x];
		}

	for (int y = 0; y < 52; y++)
		{
			top:
			int r = rand() % 52;

			if (Stack[r].SetWeight() == 20 && Stack[r].SetSuit() == 20)
				{
					goto top;
				}

			Deck[y] = Stack[y];
			Stack[y].SetCard(20, 20);
		}
	return Deck;
}

Card * Deal(Card *Deck)
{
	Card *Stack = new  Card[5];
	
	for (int x = 0; x < 5; x++)
		{
			Counter++;
			Stack[x] = Deck[x];
			cout << "Card #" << x + 1 << ": " << Weight[Stack[x]SetWeight()] << " of " << Suit[Stack[x]SetSuit()] << endl;
		}
	return Stack;
}

Card *ReDeal(Card)
{
	for (int x = 0; x < 5; x++)
		{
			if (Hand[x].SetSuit() == 20 && Hand[x].SetWeight() == 20)
				{
					Hand[x] = Deck[Counter];
					Counter++;
				}
		}
	cout << "Your new hand is: " << endl;

	for (x = 0; x < 5; x++)
		{
			cout << "Card #" << x + 1 << ": " << Weight[Stack[x]SetWeight()] << " of " << Suit[Stack[x]SetSuit()] << endl;
		}
	return Hand;
}

Card * Discard(Card *Hand, int Discard)
{
	int Trash[Discard];

	if (discard == 0)
		{
			return Hand;
		}

	if (discard == 5)
		{
			for (int x = 0; x < 5; x++)
				{
					Hand[x].SetCard(20, 20);
				}
			return Hand;
		}

	for (int x = 0; x < Discard; x++)
		{
			cout << "Discard #" << x + 1 << ".  Please enter the card you'd like to discard: ";
			cin >> number; 

			for (int y = -1; y < x; y++)
				while (number < 1 || number > 5)
					{
						cout "Invalid card selected.  Please enter a valid card to be discarded.  ";
						cin >> number;
					}
				if (Trash[y] == number)
					{
						cout "This card has already been discarded.  Please enter a valid card to be discarded.  ";
						cin >> number;
					}
				else
					{
						Trash[x] = number;
						Hand[number - 1].SetCard(20, 20);
					}
		}
	return Hand;
}

int Total(Card *Hand)
{
	int *Sorted;
	Sorted = Sort(Hand[0].SetWeight(), Hand[1].SetWeight(), Hand[2].SetWeight(), Hand[3].SetWeight(), Hand[4].SetWeight());

	if (Sorted[0] == Sorted[1] || Sorted[1] == Sorted[2] || Sorted[2] == Sorted[3] || Sorted[3] == Sorted[4])
		{
			if (Sorted[0] == Sorted[1] == Sorted[2] == Sorted[3] || Sorted[1] == Sorted[2] == Sorted[3] == Sorted[4])  //check for four of a kind
				{
					return 3; //four of a kind
				}

			if (Sorted[0] == Sorted[1] && Sorted[0] == Sorted[2] || Sorted[2] == Sorted[3] && Sorted[2] == Sorted[4] || Sorted[1] == Sorted[2] && Sorted[1] == Sorted[3])//check for full house or three of a kind
				{
					if (Sorted[0] == Sorted[1] && Sorted[0] == Sorted[2] == Sorted[4])
						{
							return 5; //Full House
						}
					else if (Sorted[2] == Sorted[3] && Sorted[2] == Sorted[4] && Sorted[0] == Sorted[1])
						{
							return 5; //Full House
						}
					else
						{
							return 2; //three of a kind
						}
				}
			

			if (Sorted[0] == Sorted[1] && Sorted[2] == Sorted[3]) //Check for Two Pair
				{
					return 4;//Two Pair First and Second, Third and Fourth
				}
			if (Sorted[0] == Sorted[1] && Sorted[3] == Sorted[4])//Check for Two Pair
				{
					return 4;//Two Pair First and Second, Fourth and Fifth
				}
			if (Sorted[1] == Sorted[2] && Sorted[3] == Sorted[4])//Check for Two Pair
				{
					return 4; //Two Pair Second and Third, Fourth and Fifth
				}

			else //If none of these options, just a pair
			{
				return 1; //Two of a Kind
			}

		}

	if (Hand[0].SetSuit() == Hand[1].SetSuit() == Hand[2].SetSuit() == Hand[3].SetSuit() == Hand[4].SetSuit()) //Check for flushes
		{
			if (Sorted[0] + 1 = Sorted[1] && Sorted[1] + 1 = Sorted[2] && Sorted[2] + 1 = Sorted[3] && Sorted[3] + 1 = Sorted[4])
			{
				if (Sorted[0] == 0 && Sorted[1] == 9 && Sorted[2] == 10 && Sorted[3] == 11 && Sorted[4] == 12) //Check for Royal Flush
					{
						return 9; //Royal Flush
					}

				else 
					{
						return 8; //Straight Flush
					}
			}


		}


	if (Sorted[0] + 1 = Sorted[1] && Sorted[1] + 1 = Sorted[2] && Sorted[2] + 1 = Sorted[3] && Sorted[3] + 1 = Sorted[4]) //Check for straight
		{
			return 6;	// Straight
		}

	else
		{
			return 0; //High Card
		}

}