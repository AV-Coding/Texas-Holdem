//
// Created by Ariel Villasenor on 2019-04-06.
//
/* The "Player.hpp" file holds all the functions for the Player object.
 * Private Data members include "TwoCardHand", "SevenCardHand", "BestHand",
 * "HighHand" and "TwentyOneCombination". Functions include "ShowCards",
 * "GetBalance", "SetHand", "GetNewCards", "Combinations", "CalculateBestHand",
 * "SetHighHand", "ShowHighHand", "AddBalance", "RemoveBalance" and "ReturnHand".
 */
#ifndef CARDTEST_PLAYER_HPP
#define CARDTEST_PLAYER_HPP

#include "Card.cpp"
#include <string>
#include "52Cards.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "PokerHand.hpp"

class Player {
private:
    vector<Card> TwoCardHand;
    double Balance;
    vector<Card> SevenCardHand;
    vector<PokerHand> BestHand;
    vector<Card> HighHand;
public:
    vector<PokerHand> TwentyOneCombination;

    Player(const Card &A, const Card &B) {
        TwoCardHand.push_back(A);
        TwoCardHand.push_back(B);
        Balance = 100.00;
    }

    /* "ShowCards"
     * Displays the players 2 Cards.
     */
    void ShowCards() {
        cout << TwoCardHand[0].toString() << " " << TwoCardHand[1].toString() << endl;
    }

    /* "GetBalance"
     * Returns the Balance of the player.
     */
    double GetBalance() const {
        return Balance;
    }

    /* "SetHand"
     * Set the seven card hand, using the players 2 cards, and the 5 community cards.
     */
    void SetHand(const vector<Card> &community) {
        SevenCardHand = community;
        for (int i = 0; i < 2; i++) {
            SevenCardHand.push_back(TwoCardHand[i]);
        }
        Combinations();
    }

    /* "GetNewCards"
     * Set 2 new cards for the player after a round is done.
     */
    void GetNewCards(const Card &A, const Card &B) {
        TwoCardHand[0] = A;
        TwoCardHand[1] = B;
    }

    /* "Combinations"
     * Sets the 21 possible Hand combinations using the seven cards.
     * We save these "PokerHands" in a vector of type "PokerHand".
     */
    void Combinations() {

        Card Zero = SevenCardHand[0];
        Card One = SevenCardHand[1];
        Card Two = SevenCardHand[2];
        Card Three = SevenCardHand[3];
        Card Four = SevenCardHand[4];
        Card Five = SevenCardHand[5];
        Card Six = SevenCardHand[6];

        PokerHand vec1(Zero, One, Two, Three, Four);
        TwentyOneCombination.push_back(vec1);
        PokerHand vec2(Zero, One, Two, Three, Five);
        TwentyOneCombination.push_back(vec2);
        PokerHand vec3(Zero, One, Two, Three, Six);
        TwentyOneCombination.push_back(vec3);
        PokerHand vec4(Zero, One, Two, Four, Five);
        TwentyOneCombination.push_back(vec4);
        PokerHand vec5(Zero, One, Two, Four, Six);
        TwentyOneCombination.push_back(vec5);
        PokerHand vec6(Zero, One, Two, Five, Six);
        TwentyOneCombination.push_back(vec6);
        PokerHand vec7(Zero, One, Five, Three, Four);
        TwentyOneCombination.push_back(vec7);
        PokerHand vec8(Zero, One, Three, Four, Six);
        TwentyOneCombination.push_back(vec8);
        PokerHand vec9(Zero, One, Three, Five, Six);
        TwentyOneCombination.push_back(vec9);
        PokerHand vec10(Zero, One, Four, Five, Six);
        TwentyOneCombination.push_back(vec10);
        PokerHand vec11(Zero, Two, Three, Four, Five);
        TwentyOneCombination.push_back(vec11);
        PokerHand vec12(Zero, Two, Three, Four, Six);
        TwentyOneCombination.push_back(vec12);
        PokerHand vec13(Zero, Two, Three, Five, Six);
        TwentyOneCombination.push_back(vec13);
        PokerHand vec14(Zero, Two, Four, Five, Six);
        TwentyOneCombination.push_back(vec14);
        PokerHand vec15(Zero, Three, Four, Five, Six);
        TwentyOneCombination.push_back(vec15);
        PokerHand vec16(One, Two, Three, Four, Five);
        TwentyOneCombination.push_back(vec16);
        PokerHand vec17(One, Two, Three, Four, Six);
        TwentyOneCombination.push_back(vec17);
        PokerHand vec18(One, Two, Three, Five, Six);
        TwentyOneCombination.push_back(vec18);
        PokerHand vec19(One, Two, Four, Five, Six);
        TwentyOneCombination.push_back(vec19);
        PokerHand vec20(One, Three, Four, Five, Six);
        TwentyOneCombination.push_back(vec20);
        //PokerHand vec21(C2, C3, C4, C5, C6);
        PokerHand vec21(Two, Three, Four, Five, Six);
        TwentyOneCombination.push_back(vec21);

        CalculateBestHand();
    }

    /* "CalculateBestHand"
     * Calculates the best hand for the player within the 21 possible combinations.
     */
    void CalculateBestHand() {
        vector<PokerHand> besthand;

        for (int i = 0; i < TwentyOneCombination.size(); i++) {
            if (i == 0) {
                besthand.push_back(TwentyOneCombination[0]);
            } else if (TwentyOneCombination[i] > besthand[0]) {
                besthand[0] = TwentyOneCombination[i];
            }
        }
        BestHand = besthand;
        TwentyOneCombination.clear();
        SetHighHand();
    }

    /* "SetHighHand"
     * Gets the 5 "Cards" and puts them in a vector.
     */
    void SetHighHand() {
        HighHand = BestHand[0].ReturnCards();
    }

    /* "ShowHighHand"
     * Displays the 5 Cards
     */
    void ShowHighHand() {
        for (int i = 0; i < HighHand.size(); i++) {
            cout << HighHand[i].toString() << " ";
        }
    }

    string Winninghand() {
        return BestHand[0].WinningString();
    }

    PokerHand ReturnHand() {
        return BestHand[0];
    }

    /* "AddBalance"
     * Takes in the paramenter "amount" and adds it to the Balance of the player.
     */
    void AddBalance(double amount) {
        Balance += amount;
    }

    /* "RemoveBalance"
     * Removes $2.00 from the Balance of the player.
     */
    void RemoveBalance() {
        Balance -= 2.00;
    }


};

#endif //CARDTEST_PLAYER_HPP
