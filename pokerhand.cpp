/* File: pokerhand.cpp
 * Course: CS216
 * Project: Project 2
 * Purpose: the implementation of member functions for the PokerHand class.
 * Author: Todd Jackson, II
 */
#include "pokerhand.h"
#include <iostream>


PokerHand::PokerHand(){

    // initialize kind and point to 0 if not already 0
    if ((int)hand_rank.kind != 0 || hand_rank.point != 0 ){
        hand_rank.kind = Rank::hRanks::NoRank;
        hand_rank.point = 0;
    }
}

void PokerHand::setPokerHand(Card in_hand[], int size){
    if (size != HANDS){
        cout << "Invalid number of cards!" << endl;
    }
    else{
        for (int i=0;i<size;i++){ // copy contents of in_hand to cards array
            cards[i] = in_hand[i];
        }
    }
    
    // sort the poker hand
    sort();

    // evaluate the hands rank
    if ((bool)isStraightFlush()){}
    else if ((bool)isFourOfAKind()){}
    else if ((bool)isFullHouse()){}
    else if ((bool)isFlush()){}
    else if ((bool)isStraight()){}
    else if ((bool)isThreeOfAKind()){}
    else if ((bool)isPair()){}
    else if ((bool)isHighCard()) {}

}

int PokerHand::compareHand(const PokerHand &otherHand) const {
    int handDifference = (int)hand_rank.kind - (int)otherHand.hand_rank.kind;
    
    // if rank kind is the same, compare card values for each hand
    if (handDifference == 0){
        handDifference = hand_rank.point - otherHand.hand_rank.point; 
    }
    return handDifference;
}

void PokerHand::print() const{
    for (int i=0;i<HANDS; i++){
        cards[i].print();
        cout << "\t";
    }
    cout << "\nIts rank is: ";
    hand_rank.print(); 
}

Rank PokerHand::getRank() const{
    
    return hand_rank;
}

bool PokerHand::isStraightFlush(){
    bool isSF = isSequence() && isAllOneSuit();
    if (isSF){
        hand_rank.kind = Rank::hRanks::StraightFlush;
        hand_rank.point = cards[START].getPoint(); // since hand is sorted, first card will be highest
    }
    return isSF;
}

bool PokerHand::isFourOfAKind(){
    bool isFK = false;
    Card compareCard = cards[START];
    Card highCard;
    int counter = 1;

    //compare reference card with each other card in hand, if they are the same add one to counter
    // if they are different redefine reference card to be the card just compared to
    for (int i=0; i<HANDS-1; i++){
        if (cards[i+1].getPoint() == compareCard.getPoint()){
           counter++;
           highCard = compareCard;
           
           //if four cards are found to be the same, set boolean flag to true, set the rank of the hand, and set the 
           // card value of the hand
        if (counter == 4){
            isFK = true;
            hand_rank.kind = Rank::hRanks::FourOfAKind;
            hand_rank.point = compareCard.getPoint();
    }
        }
        else {
            compareCard = cards[i+1]; // set next card as the new reference card
            counter = 1; // reset counter
        }
    }
    return isFK;
}

bool PokerHand::isFullHouse(){
    bool isFH;
    Card cardOne = cards[START];
    Card cardTwo = cards[END];
    int cardOneCount = 1;
    int cardTwoCount = 1;

    for (int i=0; i<3;i++){
        if (cards[i+1].getPoint() == cardOne.getPoint()){
            cardOneCount++;
        }
    }
    for (int i=END; i > 1; i--){
        if (cards[i-1].getPoint() == cardTwo.getPoint()){
            cardTwoCount++;
        }
    }
    if (cardOneCount == 2 && cardTwoCount == 3){
        isFH = true;
        hand_rank.point = cardTwo.getPoint();
    }
    else if (cardOneCount == 3 && cardTwoCount == 2){
        isFH = true;
        hand_rank.point = cardOne.getPoint();
    }
    else{
        isFH = false;
    }
    if (isFH){
        hand_rank.kind = Rank::hRanks::FullHouse;
    }
    return isFH;
}

bool PokerHand::isFlush(){
    bool isFlush = isAllOneSuit();
    if (isFlush){
        hand_rank.kind = Rank::hRanks::Flush;
        hand_rank.point = cards[START].getPoint(); // since sorted, card at start is highest card
    }
    return isFlush;
}

bool PokerHand::isStraight(){
    bool isStraight = isSequence();
    if (isStraight){
        hand_rank.kind = Rank::hRanks::Straight;
        hand_rank.point = cards[START].getPoint(); // since sorted, card at start is highest card
    }
    return isStraight;
}


// functions the same as isFourOfAKind, but now boolean is true when counter equals 3
bool PokerHand::isThreeOfAKind(){
    bool isFK = false;
    Card compareCard = cards[START];
    Card highCard;
    int counter = 1;

    for (int i=0; i<HANDS-1; i++){
        if (cards[i+1].getPoint() == compareCard.getPoint()){
            counter++;
            highCard = compareCard;
        
        if (counter == 3){
            isFK = true;
            hand_rank.kind = Rank::hRanks::ThreeOfAKind;
            hand_rank.point = highCard.getPoint();
        }
        }
        else {
            compareCard = cards[i+1];
            counter = 1;
        }
    }

    return isFK;
}

bool PokerHand::isPair(){
    bool isPair = false;
    Card currCard;
    Card highCard = cards[END]; //set base card for reference, use last since it is smallest
    for (int i=0; i<HANDS-1; i++){
        if (cards[i].getPoint() == cards[i+1].getPoint()){ //compare current and next card
            isPair = true; // if the same, a pair has been found
            currCard = cards[i]; //change current card to card at index i
            if (currCard.getPoint() > highCard.getPoint()){ // if the current card is greater than highest, highest equals current
                highCard = currCard;
            }
        }
        if (isPair == true){
            hand_rank.kind = Rank::hRanks::Pair;
            hand_rank.point = highCard.getPoint(); // card value is highest pair by point value
        }
    }
    return isPair;
}
bool PokerHand::isHighCard(){
    
    // poker hand default is high card, so just return values
    hand_rank.kind = Rank::hRanks::HighCard;
    hand_rank.point = cards[START].getPoint(); // since sorted, card at start is highest

    return true;
}

void PokerHand::sort(){
    Card temp;
    for (int i=0; i<HANDS-1; i++){
        for (int j=i+1; j<HANDS;j++){
            if (cards[i].getPoint() < cards[j].getPoint()){ // if current card is less than comparison card, switch them
                temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

bool PokerHand::isAllOneSuit() const{
    bool oneSuit = true;

    // loop through hand, if the suit of any two cards are not equal, then hand not just one suit
    for (int i=0; i<HANDS-1; i++){
        if ((int)cards[i].getSuit() != (int)cards[i+1].getSuit()){
            oneSuit = false;
        }
    }
    return oneSuit;
}

bool PokerHand::isSequence() const{
    bool isSequence = true;
    for (int i=0; i<HANDS-1; i++){
        if ((cards[i].getPoint()-1) != cards[i+1].getPoint()){ //If the next card is not equal to the current card minus one
            isSequence = false;
        }
    }
    return isSequence;    
}