/* File: card.cpp
 * Course: CS216
 * Project: Project 2
 * Purpose: the implementation of member functions for the Card class.
 * Author: Todd Jackson, II
 */
#include "card.h"

// Default constructor marks card as invalid
Card::Card() {
    suit = cSuits::Invalid;
    point = 0;
}
// Alternate constructor
Card::Card(cSuits s, cPoints p) 
{
	suit = s;
	point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
	return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
	return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
	if (this->point > other.point)
		return 1;
	else if(this->point == other.point)
		return 0;
	else
		return -1;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again   
void Card::print() const{
	
	if (point < 11){	
		switch (int(suit)){
			case 1:
			       cout << SPADE << setw(2) << point << SPADE ;
			       break;
			case 2:	       
                	       cout << CLUB << setw(2) << point << CLUB ;
			       break;
			case 3:
                       	       cout << HEART << setw(2) << point << HEART ;
			       break;
			case 4:
                	       cout << DIAMOND << setw(2) << point << DIAMOND ;
			       break;
			default:
				cout << "Invalid Card" ;		       
		}
	}
	else if (point < 15){
		switch(point){
			case 11:
				switch (int(suit)){
					case 1:
						cout << SPADE << setw(2) << "J" << SPADE ;
						break;
					case 2:
						cout << CLUB << setw(2) << "J" << CLUB ;
						break;
					case 3:
						cout << HEART << setw(2) << "J" << HEART ;
						break;
					case 4:
						cout << DIAMOND << setw(2) << "J" << DIAMOND ;
						break;
					default:
						cout << "Invalid Card" ;
				}
				break;
			case 12:
				switch (int(suit)){
					case 1:
						cout << SPADE << setw(2) << "Q" << SPADE ;
						break;
					case 2:
						cout << CLUB << setw(2) << "Q" << CLUB ;
						break;
					case 3:
						cout << HEART << setw(2) << "Q" << HEART ;
						break;
					case 4:
						cout << DIAMOND << setw(2) << "Q" << DIAMOND ;
						break;
					default:
						cout << "Invalid Card" ;
				}
				break;
			case 13:
				switch (int(suit)){
					case 1:
						cout << SPADE << setw(2) << "K" << SPADE ;
						break;
					case 2:
						cout << CLUB << setw(2) << "K" << CLUB ;
						break;
					case 3:
						cout << HEART << setw(2) << "K" << HEART ;
						break;
					case 4:
						cout << DIAMOND << setw(2) << "K" << DIAMOND ;
						break;
					default:
						cout << "Invalid Card" ;
				}
				break;
			default:
				switch (int(suit)){
					case 1:
						cout << SPADE << setw(2) << "A" << SPADE ;
						break;
					case 2:
						cout << CLUB << setw(2) << "A" << CLUB ;
						break;
					case 3:
						cout << HEART << setw(2) << "A" << HEART ;
						break;
					case 4:
						cout << DIAMOND << setw(2) << "A" << DIAMOND ;
						break;
					default:
						cout << "Invalid Card" ;
				}		
		}
	}
}
