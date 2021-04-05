#include <iostream>
#include <iomanip>
#include "deck.h"
#include "card.h"
#include "rank.h"
#include "pokerhand.h"

const int HAND_SIZE = 5;
const int NUM_HOLE_CARDS = 2;
const int NUM_COMM_CARDS = 5;
const int NUM_POSITIONS = 2;

int main(){
    string userChoice;

    // declare variables for the user's and computer's hands
    Card userCards[NUM_HOLE_CARDS];
    Card compCards[NUM_HOLE_CARDS];
    Card currCommCard;
    Card communityCards[HAND_SIZE];

    // declare the deck of cards to be used
    Deck gameDeck;

    gameDeck.createDeck(); // generate a 52 card deck of cards
    gameDeck.shuffleDeck();

    do {
        cout << "Welcome to Texas Hold'Em! \n" ;
        cout << "Press any key to Start \n" ;
        cout << "Press 'q' or 'Q' to quit: " << endl;
        
        cin >> userChoice;
        cin.ignore (256, '\n');

        // If user selection is invalid, keep getting user input until they enter something valid
        while (cin.fail ())
        {
        cin.clear (); //Clear fail flag
        cin.ignore (256, '\n'); //Ignore the non user selection characters
        cout << "Invalid character.";
        cin >> userChoice;
        cin.ignore (256, '\n');
        }

        if (userChoice != "q" && userChoice != "Q"){
            
            // Deal two cards to user
            userCards[0] = gameDeck.deal_a_card();
            userCards[1] = gameDeck.deal_a_card();
            cout << "Your Hand: \n\t";
            userCards[0].print(); 
            cout << "\n\t\t";
            userCards[1].print(); 
            cout << endl;

            // Deal two cards to computer
            compCards[0] = gameDeck.deal_a_card();
            compCards[1] = gameDeck.deal_a_card();
            cout << "\nComputer's Hand: \n\t";
            compCards[0].print(); 
            cout << "\n\t\t";
            compCards[1].print(); 
            cout << endl;

            cout << "\nCommunity Cards:" << endl;
            // Draw 5 cards from game deck, display them one at a time, 
            // then add them to an array of community cards
            for (int i=0; i < NUM_COMM_CARDS; i++){
                currCommCard = gameDeck.deal_a_card();
                currCommCard.print();
                cout << "\t";
                communityCards[i] = currCommCard;
            }
            cout << "\n" << endl;            
            
            PokerHand currUserHand;
            PokerHand currCompHand;
            Card placeHolder;
            Card placeHolderTwo; // just for use when replacing multiple cards from community cards
            PokerHand bestUserHand;
            PokerHand bestCompHand;

            //both hold two values, first is position of the community card 
            //  that was replaced by the user/computers card that is at the position stored in second value
           // int userPosition[NUM_POSITIONS]; 
            //int compPosition[NUM_POSITIONS];


            // set first poker hand to get first rank to reference to find best rank
            placeHolder = communityCards[0]; // set temp card to hold card that will be replaced
            communityCards[0] = userCards[0]; 
            bestUserHand.setPokerHand(communityCards, HAND_SIZE);
            communityCards[0] = placeHolder; // put old card back where it was originally

            //same as above, but for computers hand
            placeHolder = communityCards[0]; 
            communityCards[0] = compCards[0]; 
            bestCompHand.setPokerHand(communityCards, HAND_SIZE); 
            communityCards[0] = placeHolder;

            // Find all possible hands, compare their ranks, find which is of highest rank
            for (int i=0; i < 2; i++){
                
                // loop through community cards, replacing one at a time with one of user's cards
                //  then find its rank, and put old community card back where it was
                for (int j=0; j<HAND_SIZE; j++){

                    for (int k=j+1; k<HAND_SIZE; k++){
                        placeHolder = communityCards[j];
                        placeHolderTwo = communityCards[k];

			            communityCards[j] = userCards[0];
			            communityCards[k] = userCards[1];
                        
                        currUserHand.setPokerHand(communityCards, HAND_SIZE);
                        communityCards[j] = placeHolder;
                        communityCards[k] = placeHolderTwo;

                        placeHolder = communityCards[j];
                        placeHolderTwo = communityCards[k];

			            communityCards[j] = compCards[0];
			            communityCards[k] = compCards[1];
                        
                        currCompHand.setPokerHand(communityCards, HAND_SIZE);
                        communityCards[j] = placeHolder;
                        communityCards[k] = placeHolderTwo;

                        // if current user hand rank is greater than best, set it as new best and record what the hand was
                        if (currUserHand.compareHand(bestUserHand) > 0){
                            bestUserHand = currUserHand;
                        }

                        // same as user, but for computer
                        if (currCompHand.compareHand(bestCompHand) > 0){
                            bestCompHand = currCompHand;
                        }
		            }
                    // set a new poker hand for user
                    placeHolder = communityCards[j];
                    communityCards[j] = userCards[i];
                    currUserHand.setPokerHand(communityCards, HAND_SIZE);
                    communityCards[j] = placeHolder;

                    // set a new poker hand for the computer
                    communityCards[j] = compCards[i];
                    currCompHand.setPokerHand(communityCards, HAND_SIZE);
                    communityCards[j] = placeHolder;

                    // if current user hand rank is greater than best, set it as new best and record what the hand was
                    if (currUserHand.compareHand(bestUserHand) > 0){
                        bestUserHand = currUserHand;
                    }

                    // same as user, but for computer
                    if (currCompHand.compareHand(bestCompHand) > 0){
                        bestCompHand = currCompHand;
                    }
                }
            }
            cout << "\n*****Your Best Hand*****" << endl;
            bestUserHand.print();

            cout << "\n*****Best Computer Hand*****" << endl;
            bestCompHand.print();

            cout << "\nThe Best Hand is:" << endl;

            if (bestUserHand.compareHand(bestCompHand) > 0){
                cout << "Your Hand: \n";
                bestUserHand.print();
            }
            else if (bestUserHand.compareHand(bestCompHand) < 0){
                cout << "Computer's Hand: \n";
                bestCompHand.print();
            }
            else{
                cout << "Hands are tied." << endl;
            }
        }
        
        // create a new deck and shuffle, so that program has fresh deck for each loop 
        gameDeck.createDeck();
        gameDeck.shuffleDeck();

    } while (userChoice != "q" && userChoice != "Q");

    cout << "\nThank you for playing Texas Hold'Em! \nSee you again soon!" << endl;  

    return 0;
}