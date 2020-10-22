//Created by Ariel Villaseñor
/* The "Card.cpp" file holds all the functions and datamembers for the Card objects.
 * Here we have two Enum Classes, one is suit, and the other Rank. I have two private
 * data members. one to hold the rank of the card, and the other for the suit of the
 * card. Functions that are used are "getValue", "getSuit", "getRank" and "toString".
 * Here we also overload their operator errors so we can compare between cards.
 */
#ifndef CARD_CPP
#define CARD_CPP

#include <string>
#include "catch.hpp"
#include <iostream>
#include <vector>     // std::vector
#include <algorithm>

using namespace std;

// Model the Suit of a Poker Card
enum class Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};
enum class Rank {
    DEUCE = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,
};

class Card {
private:
    Rank x_;
    Suit y_;

public:
    Card(Rank x, Suit y) {
        x_ = x;
        y_ = y;
    }

    /* "getValue"
     * Returns the numeric value of the card.
     */
    int getValue() const { return (int) x_; }

    Suit getSuit() const { return y_; }

    Rank getRank() const { return x_; }

    string toString() {
        auto const club{"\xe2\x99\xa3"};
        auto const diamond{"\xe2\x99\xa6"};
        auto const heart{"\xe2\x99\xa5"};
        auto const spade{"\xe2\x99\xa0"};

        string value;

        if (this->getValue() > 10) {
            if (this->getValue() == 11) {
                value = "J";
            } else if (this->getValue() == 12) {
                value = "Q";
            } else if (this->getValue() == 13) {
                value = "K";
            } else if (this->getValue() == 14) {
                value = "A";
            }
        } else {
            value = to_string(this->getValue());
        }
        if (y_ == Suit::CLUBS) {
            return value + club;
        } else if (y_ == Suit::DIAMONDS) {
            return value + diamond;
        } else if (y_ == Suit::SPADES) {
            return value + spade;
        } else {
            return value + heart;
        }

    }

    bool operator<(const Card &OtherObject) const {
        return this->getValue() < OtherObject.getValue();
    }

    bool operator>(const Card &OtherObject) const {
        return this->getValue() > OtherObject.getValue();
    }

    bool operator==(const Card &OtherObject) const {
        return this->getValue() == OtherObject.getValue();
    }

};

#endif

