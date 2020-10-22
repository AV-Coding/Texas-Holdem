//
// Created by Ariel Villasenor on 2019-04-06.
//
/* The "Game.cpp" file is the main function for this program. It is what is running
 * everything. It creates an object of class "Dealer" and a vector of class "Player"
 * As long as the user wants to keep on playing, the variable "Replay" will be set to "true".
 * Here I use the functions "PresentPokerTable" to setup what the user will see and
 * "ResetTable" to get a new deck for the next game.
 */
#include "Card.cpp"
#include <string>
#include "52Cards.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "Dealer.hpp"
#include <chrono>
#include <random>
#include "Player.hpp"

using namespace std;

/*Presents the "table" for the user by displaying the community cards, the players
 * hands and their balances.*/
void PresentPokerTable(vector<Card> &Community, vector<Player> &players) {
    for (auto x: Community) {
        cout << x.toString() << " ";
    }

    cout << endl << "++++++++++++++++++++++++++++++++++++" << endl;


    for (int i = 0; i < players.size(); i++) {
        cout << "Player " << i + 1 << ": $";
        cout << fixed;
        cout << setprecision(2);
        cout << players[i].GetBalance() << " - ";
        players[i].ShowCards();
        cout << "    Best Hand:   ";
        players[i].ShowHighHand();
        cout << players[i].Winninghand() << endl;
        cout << endl;
    }
}

/*The "ResetTable" function Re-Initializes the Deck and shuffles the cards. The "Dealer"
 *Gerard also deals out new cards to the players. There is also now a new community.*/
void ResetTable(vector<Card> &Community, vector<Player> &players, Dealer &Gerard) {
    Gerard.InitializeDeck();
    Gerard.ShuffleDeck();

    for (int i = 0; i < players.size(); i++) {
        players[i].GetNewCards(Gerard.DistributeCard(), Gerard.DistributeCard());
    }

    for (int i = 0; i < 5; i++) {
        Community[i] = Gerard.DistributeCard();
    }
}

/*The "main" function starts everything. Asks the user how many players there will be.
 * Initializes a vecotr of type "Card" for the Community cards and a vector of type "Player"
 * to hold the objects of the players.*/
int main() {
    bool Replay = true;
    int NumPlayers;

    cout << "How many Players?";
    cin >> NumPlayers;
    cout << endl;

    Dealer Gerard(NumPlayers);
    vector<Card> Community;
    vector<Player> players;

    for (int i = 0; i < NumPlayers; i++) {
        Player object(Gerard.DistributeCard(), Gerard.DistributeCard());
        players.push_back(object);
    }

    for (int i; i < 5; i++) {
        Community.push_back(Gerard.DistributeCard());
    }

    while (Replay == true) {

        for (int i = 0; i < players.size(); i++) {
            players[i].SetHand(Community);
            players[i].RemoveBalance();
            Gerard.SetPlayers(players[i]);
        }

        Gerard.CalculateWinner();

        PresentPokerTable(Community, players);

        vector<int> indexes = Gerard.WinningIndexes();

        Gerard.PrintWinners();

        double pot = Gerard.ReturnPot();
        for (int i = 0; i < indexes.size(); i++) {
            players[indexes[i] - 1].AddBalance(pot);
        }
        ResetTable(Community, players, Gerard);

        string response;
        cout << "Play another game? <y or n>";
        cin >> response;

        cout << endl;

        if (response == "n") {
            Replay = false;
        }
    }
    return 0;
}



