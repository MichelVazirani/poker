#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//class Card;


class Card{

    int *suit;
    int *rank;


    public:
        Card(int s, int r);

        Card(const Card &c);

        ~Card();

        Card& operator=(const Card &c);

        int compareTo(Card c);

        int getRank() const;

        int getSuit() const;
        
        friend bool operator <(const Card &c1, const Card &c2);
        
        friend bool operator >(const Card &c1, const Card &c2);
        
        friend bool operator ==(const Card &c1, const Card &c2);

        void printCard();

        friend std::ostream& operator<<(std::ostream& os, const Card &c);
};



#endif
