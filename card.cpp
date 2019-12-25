#include "card.hpp"


Card::Card(int s, int r){
    
    suit = new int();
    rank = new int();
    
    *suit = s;
    *rank = r;
}

Card::Card(const Card &c){
    
    suit = new int();
    rank = new int();
    
    *suit = *(c.suit);
    *rank = *(c.rank);

}


Card& Card::operator=(const Card &c){

    suit = new int();
    rank = new int();

    *suit = *(c.suit);
    *rank = *(c.rank);
    return *this;
}


Card::~Card(){

    delete suit;
    delete rank;
}



bool operator <(const Card &c1, const Card &c2){

    if(c1.getRank() != c2.getRank()){
        if(std::max(c1.getRank(), c2.getRank()) == c1.getRank()){
            return false;
        } else {
            return true;
        }
    } else {
         if(std::max(c1.getSuit(), c2.getSuit()) == c1.getSuit()){
            return false;
        } else {
            return true;
        } 
    }
}


bool operator >(const Card &c1, const Card &c2){
    return !(c1 < c2);
}

bool operator ==(const Card &c1, const Card &c2){
    return c1.getSuit() == c2.getSuit() && c1.getRank() == c2.getRank();
}


int Card::getRank() const{
    return *rank;
}

int Card::getSuit() const{
    return *suit;
}

void Card::printCard(){

    std::string rankString = "";
    std::string suitString = "";
    
    
    // This section is ugly but necessary.
    if(*rank == 1){
        rankString = "Ace";
    } else if (*rank == 2){
        rankString = "2";
    } else if (*rank == 3){
        rankString = "3";
    } else if (*rank == 4){
        rankString = "4";
    } else if (*rank == 5){
        rankString = "5";
    } else if (*rank == 6){
        rankString = "6";
    } else if (*rank == 7){
        rankString = "7";
    } else if (*rank == 8){
        rankString = "8";
    } else if (*rank == 9){
        rankString = "9";
    } else if (*rank == 10){
        rankString = "10";
    } else if (*rank == 11){
        rankString = "Jack";
    } else if (*rank == 12){
        rankString = "Queen";
    } else if (*rank == 13){
        rankString = "King";
    }
    
    if(*suit == 1){
        suitString = "Clubs";
    } else if (*suit == 2){
        suitString = "Diamonds";
    } else if (*suit == 3){
        suitString = "Hearts";
    } else if (*suit == 4){
        suitString = "Spades";
    }

    std::cout << rankString << " of " << suitString << std::endl;

}


std::ostream& operator<<(std::ostream& os, const Card &c){

    std::string rankString = "";
    std::string suitString = "";
    
    
    // This section is ugly but necessary.
    if(*(c.rank) == 1){
        rankString = "Ace";
    } else if (*(c.rank) == 2){
        rankString = "2";
    } else if (*(c.rank) == 3){
        rankString = "3";
    } else if (*(c.rank) == 4){
        rankString = "4";
    } else if (*(c.rank) == 5){
        rankString = "5";
    } else if (*(c.rank) == 6){
        rankString = "6";
    } else if (*(c.rank) == 7){
        rankString = "7";
    } else if (*(c.rank) == 8){
        rankString = "8";
    } else if (*(c.rank) == 9){
        rankString = "9";
    } else if (*(c.rank) == 10){
        rankString = "10";
    } else if (*(c.rank) == 11){
        rankString = "Jack";
    } else if (*(c.rank) == 12){
        rankString = "Queen";
    } else if (*(c.rank) == 13){
        rankString = "King";
    }
    
    if(*(c.suit) == 1){
        suitString = "Clubs";
    } else if (*(c.suit) == 2){
        suitString = "Diamonds";
    } else if (*(c.suit) == 3){
        suitString = "Hearts";
    } else if (*(c.suit) == 4){
        suitString = "Spades";
    }

    os << rankString << " of " << suitString;
    return os;

}




