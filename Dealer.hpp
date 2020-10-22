//
// Created by Ariel Villasenor on 2019-04-06.
//
/* The "Dealer.hpp" file holds all the function the Dealer object will use.
 * My private data memmbers includes the vector "Deck" of type "Card" which holds 52 Card
 * objects, "NumberPlayers", a vector of type "Player", a vector of the winnings players,
 * the value of the pot and the indexes of where each winning player is in the "players" vector.
 * Functions that are used include "InitializeDeck", "ShuffleDeck", "DistributeCard", "CalculateWinners"
 * and "PrintWinners".
 */

#ifndef CARDTEST_DEALER_HPP
#define CARDTEST_DEALER_HPP

#include "Card.cpp"
#include <string>
#include "52Cards.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "PokerHand.hpp"
#include <iomanip>

class Dealer {
private:
    vector<Card> Deck;
    int NumberPlayers;
    vector<Player> players;
    vector<Player> Winners;
    double pot;
    vector<int> indexes;
public:
    Dealer(int numplayers) {
        NumberPlayers = numplayers;
        InitializeDeck();
        ShuffleDeck();
    }

    /* "InitializeDeck"
     * Initializes the deck with 52 "Card" objects.
    */
    void InitializeDeck() {
        vector<Card> Cards{C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK, CA,
                           D2, D3, D4, D5, D6, D7, D8, D9, D10, DJ, DQ, DK, DA,
                           S2, S3, S4, S5, S6, S7, S8, S9, S10, SJ, SQ, SK, SA,
                           H2, H3, H4, H5, H6, H7, H8, H9, H10, HJ, HQ, HK, HA};
        Deck = Cards;
        pot = 2.00 * NumberPlayers;
    }

    /* "ShuffleDeck"
     * Shuffles the "Deck" vector.
     */
    void ShuffleDeck() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(Deck.begin(), Deck.end(), std::default_random_engine(seed));
    }

    /* "DistributeCard"
     * Saves the value of the last card, pops it from the vector, then returns the value.
     */
    Card DistributeCard() {
        Card card(Deck[Deck.size() - 1]);
        Deck.pop_back();
        return card;
    }

    /* "SetPlayers"
     * Passes in the player objects from Game.cpp so the dealer can figure out who won the
     * round of Arizona hold em'.
     */
    void SetPlayers(const Player &Players) {
        players.push_back(Players);
    }

    /* "CalculateWinner"
     * Calculates the which player(s) has the best hand. We will save the the winnres
     * in the besthand vector, then at the end of the function, assign it to the private
     * data member "Winners"
     */
    void CalculateWinner() {
        vector<Player> besthand;
        vector<int> index;

        for (int i = 0; i < players.size(); i++) {
            if (i == 0) {
                besthand.push_back(players[i]);
                index.push_back(i + 1);
            } else if (players[i].ReturnHand() > besthand[0].ReturnHand()) {
                besthand.clear();
                index.clear();
                besthand.push_back(players[i]);
                index.push_back(i + 1);
            } else if (players[i].ReturnHand() == besthand[0].ReturnHand()) {
                besthand.push_back(players[i]);
                index.push_back(i + 1);
            }
        }
        players.clear();
        Winners = besthand;
        indexes = index;
    }

    /* "PrintWinners"
     * Prints the winners for the round by displaying their best hand and the players
     * new balance.
     */
    void PrintWinners() {
        vector<Card> temp;
        DividePot(Winners.size());
        if (Winners.size() == 1) {
            Winners[0].AddBalance(pot);
            cout << "Winner: Player " << indexes[0] << " $";
            cout << fixed;
            cout << setprecision(2);
            cout << Winners[0].GetBalance();
            cout << endl << "++++++++++++++++++++++++++++++++++++" << endl;
            temp = Winners[0].ReturnHand().ReturnCards();
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i].toString() << " ";
            }
            cout << "  " << Winners[0].ReturnHand().WinningString() << endl;
        } else {
            cout << "Winning hands (tie)";
            cout << endl << "++++++++++++++++++++++++++++++++++++" << endl;
            for (int i = 0; i < Winners.size(); i++) {
                Winners[i].AddBalance(pot);
                temp = Winners[i].ReturnHand().ReturnCards();
                for (int i = 0; i < temp.size(); i++) {
                    cout << temp[i].toString() << " ";
                }
                cout << Winners[0].ReturnHand().WinningString() << " Player " << indexes[i] << " $";
                cout << fixed;
                cout << setprecision(2);
                cout << Winners[i].GetBalance() << endl;
            }
        }
    }

    /* "DividePot" divides the pot by the number of players.
     */
    void DividePot(double NumWinners) {
        pot = pot / NumWinners;
    }

    /* "WinningIndexes"
     * returns the indexes of the winning players.
     */
    vector<int> WinningIndexes() {
        return indexes;
    }

    /* "ReturnPot"
     * Returns the pot.
     */
    double ReturnPot() {
        return pot;
    }
};

#endif //CARDTEST_DEALER_HPP
