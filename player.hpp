#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "card.hpp"

class Player;
class Player{

    std::vector<Card> *hand = new std::vector<Card>();
    double *bankroll = new double(5);
    double *bet = new double;
    double *maxBet = new double(5);
    std::vector<Card> *returnCards = new std::vector<Card>();

    public:

        Player();

        ~Player();

        Player(const Player &p);

        Player& operator=(const Player &p);

        void addCard(Card c);

        void removeCard(Card c);

        void winnings(double odds);

        double getBankRoll() const;

        double getBet() const;

        void printHand() const;

        int getHandSize() const;

        std::vector<Card> getHand() const;

        void sortHand();

        void clearHand();

        double askBet();

        void bets(double amt);

        void discardCards();

};





