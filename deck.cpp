/* File: deck.cpp
 * Course: CS216
 * Project: Project 2
 * Purpose: the implementation of member functions for the Deck class
 * Author: Todd Jackson, II
 */
#include "deck.h"

using namespace std;

// create a standard 52-card deck
void Deck::createDeck(){

    for (int i = (int)Card::cSuits::Spade;i < (int)Card::cSuits::Spade + SUITS; i++){
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++){

            Card::cSuits suit = static_cast<Card::cSuits>(i); //
            Card newcard(suit, val);
            deck.push_back(newcard);
        
        }
    }
}

// shuffle the cards in 52-card deck
void Deck::shuffleDeck(){

    Card temp; 
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// return a card from the tail of the deck
Card Deck::deal_a_card(){
    Card dealtCard;
    dealtCard = deck[deck.size()-1];
    deck.pop_back();

    return dealtCard;
}
