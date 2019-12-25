#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "player.hpp"
#include "deck.hpp"
#include "card.hpp"

class Game;

class Game{

    Player *p;
    Deck *cards;
    bool playerChosesToContinue = true;
    string HIGH_CARD = "High Card";
    string ONE_PAIR = "Pair";
    string TWO_PAIRS = "Two Pair";
    string THREE_OF_A_KIND = "Three of a Kind";
    string STRAIGHT = "Straight";
    string FLUSH = "Flush";
    string FULL_HOUSE = "Full House";
    string FOUR_OF_A_KIND = "Four of a Kind";
    string STRAIGHT_FLUSH = "Straight Flush";
    string ROYAL_FLUSH = "Royal Flush";

    public:
        
        Game();

        ~Game();

        Game(const Game &g);

        Game& operator=(const Game &g);

        void play();

        int getHandValue(string handValue);

        string checkHand(vector<Card> hand);

        bool royalFlush(vector<Card> hand);
        
        bool straightFlush(vector<Card> hand);
        
        bool fourOfAKind(vector<Card> hand);
        
        bool fullHouse(vector<Card> hand);
        
        bool flush(vector<Card> hand);
        
        bool straight(vector<Card> hand);
        
        bool threeOfAKind(vector<Card> hand);
        
        bool twoPairs(vector<Card> hand);
        
        bool onePair(vector<Card> hand);
        
};


