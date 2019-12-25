#include "deck.hpp"

       
Deck::Deck(){

    *top = 0;
    
    for(int j = 1; j <= 13; ++j){
        for(int k = 1; k <= 4; ++k){
            Card cur = Card(k, j);
            cards->push_back(cur);
        }
    }

}

Deck::~Deck(){
    delete top;
    delete cards;
}


Deck::Deck(const Deck &d){

    *top = d.getTop();
    *cards = d.getCards();

}
        

Deck& Deck::operator=(const Deck &d){
 
    *top = d.getTop();
    *cards = d.getCards();
    return *this;
}
       

void Deck::shuffle(){

    srand(time(NULL));
    int rand1;
    int rand2;

    for(int i = 0; i < 300; ++i){

        rand1 = rand() % 52;
        rand2 = rand() % 52;

        Card temp = (*cards)[rand1];
        (*cards)[rand1] = (*cards)[rand2];
        (*cards)[rand2] = temp;
    }

}

Card Deck::deal(){
    return (*cards)[(*top)++];
}

void Deck::resetTop(){
    *top = 0;
}

int Deck::getTop() const{
    return *top;
}

vector<Card> Deck::getCards() const{
    return *cards;
}


