// Created by Ariel Villaseñor on 2019-03-22.
//
/* "PokerHand.hpp" is the file that holds all the functions for the PokerHand class.
 * Private Data members "Hand", "HighCards" and "BestHand". Functions that are included
 * are the functions to figure out what type of hand it is. Here we also overload the
 * operator functions ">" "<" and "==". I also have a "HighCard" function that organizes
 * the best hands in order of the winning cards, then to its highest to lowest cards.
 */
#ifndef CARDTEST_POKERHAND_HPP
#define CARDTEST_POKERHAND_HPP

#include "Card.cpp"
#include <string>
#include "52Cards.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

enum class WinningHands {
    None = 0,
    HighCard = 1,
    OnePair = 2,
    TwoPair = 3,
    ThreeOfAKind = 4,
    Straight = 5,
    Flush = 6,
    FullHouse = 7,
    FourOfAKind = 8,
    StraightFlush = 9
};

class PokerHand {
private:
    std::vector<Card> Hand;
    std::vector<int> HighCards;
    WinningHands BestHand;
public:
    PokerHand(const Card &A, const Card &B, const Card &C, const Card &D, const Card &E) {
        Hand.push_back(A);
        Hand.push_back(B);
        Hand.push_back(C);
        Hand.push_back(D);
        Hand.push_back(E);
        std::sort(Hand.begin(), Hand.end());
        GetHighHand();
    }

    bool operator==(const PokerHand &OtherObject) const {
        if (ReturnBestHand() == OtherObject.ReturnBestHand()) {
            for (int i = 0; i < OtherObject.HighCards.size(); i++) {
                if (HighCards[i] < OtherObject.HighCards[i]) {
                    return false;
                } else if (HighCards[i] > OtherObject.HighCards[i]) {
                    return false;
                }
            }
            return true;
        }
        return ReturnBestHand() == OtherObject.ReturnBestHand();
    }

    bool operator<(const PokerHand &OtherObject) const {
        if (ReturnBestHand() == OtherObject.ReturnBestHand()) {
            for (int i = 0; i < OtherObject.HighCards.size(); i++) {
                if (HighCards[i] < OtherObject.HighCards[i]) {
                    return true;
                } else if (HighCards[i] > OtherObject.HighCards[i]) {
                    return false;
                }
            }
            return false;
        }
        return ReturnBestHand() < OtherObject.ReturnBestHand();
    }

    /* ">"
     * Compares the value of the HighCard vector. It first checks to
     * see if one player has a betterhand, like a "Straight" vs. a "Pair"
     * If this is the case, those 2 values are compared. If they are the
     * same, like a "pair" and a "pair", we begin to compare the HighCard
     * vector to see which has the highest pair and,if needed, the highest card.
     * */
    bool operator>(const PokerHand &OtherObject) const {
        if (ReturnBestHand() == OtherObject.ReturnBestHand()) {
            for (int i = 0; i < OtherObject.HighCards.size(); i++) {
                if (HighCards[i] < OtherObject.HighCards[i]) {
                    return false;
                } else if (HighCards[i] > OtherObject.HighCards[i]) {
                    return true;
                }
            }
            return false;
        }
        return ReturnBestHand() > OtherObject.ReturnBestHand();
    }

    int HighCard() const {
        return Hand[Hand.size() - 1].getValue();
    }

    int ReturnBestHand() const {
        return (int) BestHand;
    }

    int NumberOfPairs() const {
        std::vector<int> repeats{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int NumberOfPairs = 0;
        for (auto i = 0; i < Hand.size(); i++) {
            repeats[Hand[i].getValue()] += 1;
        }
        for (auto i = 0; i < repeats.size(); i++) {
            if (repeats[i] == 2) {
                NumberOfPairs++;
            }
        }
        return NumberOfPairs;
    }

    bool ThreeOfAKind() const {
        std::vector<int> repeats{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //repeats{D,D,2,3,4,5,6,7,8,9,10,j,Q,K,A};
        for (auto i = 0; i < Hand.size(); i++) {
            repeats[Hand[i].getValue()] += 1;
        }
        for (auto i = 0; i < repeats.size(); i++) {
            if (repeats[i] == 3) {
                return true;
            }
        }
        return false;
    }

    bool FullHouse() const {
        if (ThreeOfAKind() and NumberOfPairs() == 1) {
            return true;
        }
        return false;
    }

    bool FourOfAKind() const {
        std::vector<int> repeats{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //repeats{D,D,2,3,4,5,6,7,8,9,10,j,Q,K,A};
        for (auto i = 0; i < Hand.size(); i++) {
            repeats[Hand[i].getValue()] += 1;
        }
        for (auto i = 0; i < repeats.size(); i++) {
            if (repeats[i] == 4) {
                return true;
            }
        }
        return false;
    }

    bool Straight() const {
        if ((Hand[1].getValue() == Hand[0].getValue() + 1) and (Hand[2].getValue() == Hand[0].getValue() + 2) and
            (Hand[3].getValue() == Hand[0].getValue() + 3) and (Hand[4].getValue() == Hand[0].getValue() + 4)) {
            return true;
        } else if (Hand[0].getValue() == 2 and Hand[1].getValue() == 3 and Hand[2].getValue() == 4 and
                   Hand[3].getValue() == 5 and Hand[4].getValue() == 14) {
            //highCard=1;
            return true;
        }
        return false;
    }

    bool Flush() const {
        if (Hand[0].getSuit() == Hand[1].getSuit() and Hand[0].getSuit() == Hand[2].getSuit() and
            Hand[0].getSuit() == Hand[3].getSuit() and Hand[0].getSuit() == Hand[4].getSuit()) {
            return true;
        }
        return false;
    }

    /* "GetHighHand"
     * Figures out the best possible hand for the player.
     */
    void GetHighHand() {
        if (Straight() and Flush()) {
            BestHand = WinningHands::StraightFlush;
            GetHighCards(9);
        } else if (FourOfAKind()) {
            BestHand = WinningHands::FourOfAKind;
            GetHighCards(8);
        } else if (FullHouse()) {
            BestHand = WinningHands::FullHouse;
            GetHighCards(7);
        } else if (Flush()) {
            BestHand = WinningHands::Flush;
            GetHighCards(6);
        } else if (Straight()) {
            BestHand = WinningHands::Straight;
            GetHighCards(5);
        } else if (ThreeOfAKind()) {
            BestHand = WinningHands::ThreeOfAKind;
            GetHighCards(4);
        } else if (NumberOfPairs() == 2) {
            BestHand = WinningHands::TwoPair;
            GetHighCards(3);
        } else if (NumberOfPairs() == 1) {
            BestHand = WinningHands::OnePair;
            GetHighCards(2);
        } else {
            BestHand = WinningHands::HighCard;
            GetHighCards(1);
        }
    }

    /* "GetHighCards"
     * Organizes HighCards function to have the best group of
     * cards at the beginning of the vector, then sorts from highest
     * to lowest card values.
     */
    void GetHighCards(int operation) {
        if (operation == 1 or operation == 6) {
            //Highcard, Flush
            for (int i = Hand.size() - 1; i >= 0; i--) {
                HighCards.push_back(Hand[i].getValue());
            }
        } else if (operation == 2) {
            //OnePair
            for (int i = 0; i < Hand.size() - 1; i++) {
                if (Hand[i].getValue() == Hand[i + 1].getValue()) {
                    HighCards.push_back(Hand[i].getValue());
                    for (int j = Hand.size() - 1; j >= 0; j--) {
                        if (j != i and j != i + 1) {
                            HighCards.push_back(Hand[j].getValue());
                        }
                    }
                }
            }
        } else if (operation == 3) {
            //TwoPair
            std::vector<int> temp;
            for (int i = 0; i < Hand.size() - 1; i++) {
                if (Hand[i].getValue() == Hand[i + 1].getValue()) {
                    temp.push_back(Hand[i].getValue());
                }
            }
            sort(temp.begin(), temp.end());
            HighCards.push_back(temp[1]);
            HighCards.push_back(temp[0]);
            for (int i = 0; i < Hand.size(); i++) {
                if (Hand[i].getValue() != HighCards[0] and Hand[i].getValue() != HighCards[1]) {
                    HighCards.push_back(Hand[i].getValue());
                }
            }
        } else if (operation == 4) {
            //ThreeOfAKind
            for (int i = 0; i < Hand.size() - 2; i++) {
                if (Hand[i].getValue() == Hand[i + 1].getValue() and Hand[i].getValue() == Hand[i + 2].getValue()) {
                    HighCards.push_back(Hand[i].getValue());
                    for (int j = Hand.size() - 1; j >= 0; j--) {
                        if (Hand[j].getValue() != HighCards[0]) {
                            HighCards.push_back(Hand[j].getValue());
                        }
                    }
                }
            }
        } else if (operation == 5 or operation == 9) {
            //Straight, StraightFlush
            if (Hand[Hand.size() - 1].getValue() == 14 and Hand[0].getValue() == 2) {
                HighCards.push_back(5);
            } else {
                HighCards.push_back(Hand[Hand.size() - 1].getValue());
            }
        } else if (operation == 7) {
            //FullHouse
            for (int i = 0; i < Hand.size() - 2; i++) {
                if (Hand[i].getValue() == Hand[i + 1].getValue() and Hand[i].getValue() == Hand[i + 2].getValue()) {
                    HighCards.push_back(Hand[i].getValue());
                    if (i == 0) {
                        HighCards.push_back(Hand[i + 3].getValue());
                    } else {
                        HighCards.push_back(Hand[0].getValue());
                    }
                }
            }
        } else if (operation == 8) {
            //FourOfAKind
            for (int i = 0; i < Hand.size() - 3; i++) {
                if (Hand[i].getValue() == Hand[i + 1].getValue() and Hand[i].getValue() == Hand[i + 2].getValue() and
                    Hand[i].getValue() == Hand[i + 3].getValue()) {
                    HighCards.push_back(Hand[i].getValue());
                    if (i == 0) {
                        HighCards.push_back(Hand[4].getValue());
                    } else {
                        HighCards.push_back(Hand[0].getValue());
                    }
                }
            }
        }
    }

    /* "WinningString"
     * Return the winning hand in a string version.
     */
    string WinningString() {
        if (BestHand == WinningHands::Straight) {
            return "Straight";
        } else if (BestHand == WinningHands::Flush) {
            return "Flush";
        } else if (BestHand == WinningHands::FourOfAKind) {
            return "Four Of A Kind";
        } else if (BestHand == WinningHands::FullHouse) {
            return "Full House";
        } else if (BestHand == WinningHands::ThreeOfAKind) {
            return "Three Of A Kind";
        } else if (BestHand == WinningHands::HighCard) {
            return "High Card";
        } else if (BestHand == WinningHands::OnePair) {
            return "Pair";
        } else if (BestHand == WinningHands::TwoPair) {
            return "Two Pair";
        } else if (BestHand == WinningHands::StraightFlush) {
            return "Straight Flush";
        }
        return "";
    }

    vector<Card> ReturnCards() {
        return Hand;
    }

};

#endif //CARDTEST_POKERHAND_HPP