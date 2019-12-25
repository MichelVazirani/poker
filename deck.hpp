#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "card.hpp"

using namespace std;
class Deck{

    vector<Card> *cards = new vector<Card>();

    int *top = new int;

    public:
        
        Deck();
        
        ~Deck();
        
        Deck(const Deck &d);
        
        Deck& operator=(const Deck &d);
        
        void shuffle();
        
        Card deal();
        
        void resetTop();
        
        int getTop() const;

        vector<Card> getCards() const;


};




