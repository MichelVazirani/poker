#include "game.hpp"



Game::Game(){

    p = new Player();
    cards = new Deck();
    cards->shuffle();

}

Game::~Game(){

    delete p;
    delete cards;
}

Game::Game(const Game &g){

    *p = *(g.p);
    *cards = *(g.cards);
    playerChosesToContinue = g.playerChosesToContinue;
}

Game& Game::operator=(const Game &g){

    *p = *(g.p);
    *cards = *(g.cards);
    playerChosesToContinue = g.playerChosesToContinue;
    return *this;
}

void Game::play(){
    
    int tempHandSize;
    string handType;
    double score;
    string answer;

    std::cout << "You now have " << p->getBankRoll() << " tokens." << std::endl;

    while(p->getBankRoll() > 0 && playerChosesToContinue){
    
        // Shuffle cards and reset top of there aren't enough
        // cards left for a full game.
        if(cards->getTop() > 41){
            cards->resetTop();
            cards->shuffle();
        }

        // p.askBet() will get the betting amount from the player.
        // p.bets() will actually set the player's bet.
        p->bets(p->askBet());



        // Deal 5 cards to the player and sort the player's hand.
        std::cout << "Dealing cards." << std::endl;
        for(int i = 0; i < 5; ++i){
            p->addCard(cards->deal());
        }
        p->sortHand();
        p->printHand();


        // discard method in player class takes care of the full
        // discard process.
        p->discardCards();
        // Deal the player as many cards as they discarded and
        // sort the hand again.
        tempHandSize = p->getHandSize();
        if(tempHandSize != 5){
            std::cout << "Dealing cards." << std::endl;
            for(int i = 0; i < 5 - tempHandSize; ++i){
                p->addCard(cards->deal());
            }
            p->sortHand();
            p->printHand();
        }


        // checkHand() method determines the hand type.
        handType = checkHand(p->getHand());
        std::cout << "Your hand is a " << handType << "." << std::endl;


        // Calculate, print, and reward player's winnings.
        score = (getHandValue(handType))*(p->getBet());
        std::cout << "You win " << score << " tokens." << std::endl;
        p->winnings(score);

        // Clear the player's hand.
        p->clearHand();

        // If the player has tokens left, allow them to chose whether
        // to play again. Otherwise, tell them they're broke.
        if(p->getBankRoll() > 0){
            std::cout << "Would you like to play again? [y/n]" << std::endl;
            std::cin >> answer;
            if(answer != "y"){
                playerChosesToContinue = false;
            }
        } else {
            std::cout << "You have no tokens left. Game over :(" << std::endl;
        }
    }

}

int Game::getHandValue(string handValue){

    // Use final instance variables to determine what
    // type of hand the player has, then print it.
    if(handValue==ROYAL_FLUSH){
        return 250;
    } else if (handValue==STRAIGHT_FLUSH){
        return 50;
    } else if (handValue==FOUR_OF_A_KIND){
        return 25;
    } else if (handValue==FULL_HOUSE){
        return 6;
    } else if (handValue==FLUSH){
        return 5;
    } else if (handValue==STRAIGHT){
        return 4;
    } else if (handValue==THREE_OF_A_KIND){
        return 3;
    } else if (handValue==TWO_PAIRS){
        return 2;
    } else if (handValue==ONE_PAIR){
        return 1;
    } else {
        return 0;
    }

}

string Game::checkHand(vector<Card> hand){

    // this method should take an vector of cards
    // as input and then determine what evaluates to and
    // return that as a String
    
    if(royalFlush(hand)) {
        return "Royal Flush";
    } else if(straightFlush(hand)) {
        return "Straight Flush";
    } else if(fourOfAKind(hand)) {
        return "Four of a Kind";
    } else if(fullHouse(hand)) {
        return "Full House";
    } else if(flush(hand)) {
        return "Flush";
    } else if(straight(hand)) {
        return "Straight";
    } else if(threeOfAKind(hand)) {
        return "Three of a Kind";
    } else if(twoPairs(hand)) {
        return "Two Pair";
    } else if(onePair(hand)) {
        return "Pair";
    } else {
        return "High Card";
    }
}

bool Game::royalFlush(vector<Card> hand){

    bool isRoyalFlush = false;
    if(hand[0].getRank() == 1 && hand[1].getRank() == 10 &&
      hand[2].getRank() == 11 && hand[3].getRank() == 12 &&
      hand[4].getRank() == 13){
        
        if(hand[0].getSuit() == hand[1].getSuit() &&
          hand[1].getSuit() == hand[2].getSuit() &&
          hand[2].getSuit() == hand[3].getSuit() &&
          hand[3].getSuit() == hand[4].getSuit()){
            
            isRoyalFlush = true;
        }
    }
    
    return isRoyalFlush;
}


bool Game::straightFlush(vector<Card> hand){

    bool isStraightFlush = true;
    for(int i = 1; i < hand.size(); i++){
        if(hand[i-1].getRank() + 1 != hand[i].getRank() ||
          hand[i-1].getSuit() != hand[i].getSuit()){
            isStraightFlush = false;
        }
    }
    return isStraightFlush;

}

bool Game::fourOfAKind(vector<Card> hand){

    int sameCounter = 0;
    for(int i = 1; i < hand.size(); ++i){
        if(hand[i-1].getRank() == hand[i].getRank()){
            sameCounter++;
        } else {
            if(sameCounter != 3){
                sameCounter = 0;
            }
        }
    }
    
    if(sameCounter == 3){
        return true;
    }
    return false;

}

bool Game::fullHouse(vector<Card> hand){

    if((hand[0].getRank() == hand[1].getRank() &&
       hand[1].getRank() == hand[2].getRank() &&
       hand[3].getRank() == hand[4].getRank()) ||
      (hand[0].getRank() == hand[1].getRank() &&
      hand[2].getRank() == hand[3].getRank() &&
      hand[3].getRank() == hand[4].getRank())){
        return true;
    }
    return false;

}

bool Game::flush(vector<Card> hand){

    bool isFlush = true;
    for(int i = 1; i < hand.size(); ++i){
        if(hand[i-1].getSuit() != hand[i].getSuit()){
            isFlush = false;
        }
    }
    
    return isFlush;

}

bool Game::straight(vector<Card> hand){

    bool isStraight = true;
    for(int i = 1; i < hand.size(); ++i){
        if(hand[i-1].getRank() + 1 != hand[i].getRank()){
            isStraight = false;
        }
    }
    
    // This if loop takes care of the edge case in which an Ace is
    // meant to be a high card.
    if(hand[0].getRank() == 1 && hand[1].getRank() == 10 &&
      hand[2].getRank() == 11 && hand[3].getRank() == 12 &&
      hand[4].getRank() == 13){
        isStraight = true;
    }
    return isStraight;
}


bool Game::threeOfAKind(vector<Card> hand){

    int sameCounter = 0;
    for(int i = 1; i < hand.size(); ++i){
        if(hand[i-1].getRank() == hand[i].getRank()){
            ++sameCounter;
        } else {
            if(sameCounter != 2){
                sameCounter = 0;
            }
        }
    }
    
    if(sameCounter == 2){
        return true;
    }
    return false;

}

bool Game::twoPairs(vector<Card> hand){

    if((hand[0].getRank() == hand[1].getRank() &&
       hand[2].getRank() == hand[3].getRank()) ||
      (hand[0].getRank() == hand[1].getRank() &&
      hand[3].getRank() == hand[4].getRank()) ||
      (hand[1].getRank() == hand[2].getRank() &&
      hand[3].getRank() == hand[4].getRank())){
        return true;
    }
    return false;
}

bool Game::onePair(vector<Card> hand){

    int sameCounter = 0;
    for(int i = 1; i < hand.size(); ++i){
        if(hand[i-1].getRank() == hand[i].getRank()){
            ++sameCounter;
        } else {
            if(sameCounter != 1){
                sameCounter = 0;
            }
        }
    }
    
    if(sameCounter == 1){
        return true;
    }
    return false;
}
 







