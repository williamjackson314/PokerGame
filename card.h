/* File: card.h
 * Course: CS216-00x
 * Project: Project 2
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iomanip>

using namespace std;

// define the unicode for four suits for display purpose
const char SPADE[] = "\e[0;30;47m\xe2\x99\xa0\e[0;37;40m";
const char CLUB[] = "\e[0;30;47m\xe2\x99\xa3\e[0;37;40m";
const char HEART[] = "\e[0;31;47m\xe2\x99\xa5\e[0;37;40m";
const char DIAMOND[] = "\e[0;31;47m\xe2\x99\xa6\e[0;37;40m";

class Card 
{
    public:
        // Type definition for the suits of a playing card.
        // Invalid means the Card object has not been initialized.
        // Note: outside Card member functions, refer this type using Card::cSuits, 
        // Card::Spades, Card::Hearts, ...
        //
        typedef enum class cSuits {Invalid, Spade, Club, Heart, Diamond} cSuits;

        // Type definition for the point value of a playing card.
        // A point value of 0 means the Card object has not been initialized.
        // J = 11, Q = 12, K = 13, A = 14.
        // A point value of 1 is not used.
        // Note: outside Card member functions, refer this type using Card::cPoints
        //
        typedef unsigned int cPoints;

        // Default constructor.
        // We allow uninitialized Cards to be created.
        // This allows arrays of Cards.
        // Uninitialized cards should have Invalid for its suit
        // and 0 for its points.
        Card(); 

        // Alternate constructor
        // Create a Card with specified suit and points.
        Card(cSuits s, cPoints p);

        // access the card point value
        cPoints getPoint() const;

        // access the card suit value
        cSuits getSuit() const;

        // compare with another Card object passed in as parameter: other
        // if the object your are working on has higher point than other, return 1;
        // if the object your are working on has lower point than other, return -1;
        // otherwise, return 0
        int compareTo(Card other) const;

        // Display a description of the Card object to standard output.
        // The output should look like:
        //   the sign of suit, followed by the point, then followed by the sign of suit again
        void print() const;

        // Assign the friendship to the class named PokerHand
        friend class PokerHand;

    private:
        cSuits suit;        // suit of the card
        cPoints point;    // point value of the card
};
#endif  /* CARD_H */
