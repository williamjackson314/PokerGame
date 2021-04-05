/* File: rank.cpp
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 * Name: Todd Jackson, II
 */
#include <iostream>
#include <iomanip>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
	kind = hRanks::NoRank;
    	point = 0;
}

// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    if (p < 2 || p > 14){
        point = 0;
    }
    else {
        point = p;
    }
    if (r < hRanks::HighCard || r > hRanks::StraightFlush){
        kind = hRanks::NoRank;
    }
    else{
        kind = r;
    }
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{   

    switch(point){
        case 11:
            cout << RANK_NAMES[(int)kind] << "( J)" << endl;
            break;
        case 12:
            cout << RANK_NAMES[(int)kind] << "( Q)" << endl;
            break;
        case 13:
            cout << RANK_NAMES[(int)kind] << "( K)" << endl;
            break;
        case 14:
            cout << RANK_NAMES[(int)kind] << "( A)" << endl;       
            break;
        default:    
            cout << RANK_NAMES[(int)kind] << "(" << setw(2) << point << ")" << endl;
            break;
    }
}

