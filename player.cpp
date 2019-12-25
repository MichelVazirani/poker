
#include "player.hpp"

Player::Player(){
    
    *bet = 0;

}

Player::~Player(){

    delete hand;
    delete bankroll;
    delete bet;
    delete maxBet;
    delete returnCards;

}

Player::Player(const Player &p){

    *bet = p.getBet();
    *hand = p.getHand();
    *bankroll = p.getBankRoll();
    *maxBet = *(p.maxBet);
    *returnCards = *(p.returnCards);

}

Player& Player::operator=(const Player &p){

    *bet = p.getBet();
    *hand = p.getHand();
    *bankroll = p.getBankRoll();
    *maxBet = *(p.maxBet);
    *returnCards = *(p.returnCards);
    return *this;
}

void Player::addCard(Card c){
    hand->push_back(c);
}

void Player::removeCard(Card c){

    std::vector<Card>::iterator it3;
    for(it3 = hand->begin(); it3 != hand->end(); ++it3){
        if(*it3 == c){
            it3 = hand->erase(it3);
            --it3;
        }
    }
}

void Player::winnings(double odds){

    *bankroll += odds;
    std::cout << "You now have " << *bankroll << " tokens." << std::endl;

}

double Player::getBankRoll() const{
    return *bankroll;
}

double Player::getBet() const{
    return *bet;
}

void Player::printHand() const{

    std::cout << "Here is your hand." << std::endl;
    for(Card c : *hand){
        c.printCard();
    }
}

int Player::getHandSize() const{
    return hand->size();
}

std::vector<Card> Player::getHand() const{
    return *hand;
}


void Player::sortHand(){
    std::sort(hand->begin(), hand->end());
}


void Player::clearHand(){
    hand->clear();
}

double Player::askBet(){

    using namespace std;
    
    cout << "Please enter your bet." << endl;

    int amt;
    cin >> amt;

    if(*bankroll < 5){
        *maxBet = *bankroll;
    }

    if(amt >= 1 && amt <= *maxBet){
        cout << "You bet " << amt << " tokens." << endl;
        return (double) amt;
    } else {
        while(!(amt >= 1 && amt <= *maxBet)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please bet between 1.0 and " 
                 << *maxBet << " tokens." << endl;
            cin >> amt;
        }
        cout << "You bet " << amt << " tokens." << endl;
        return (double) amt;
    }
}


void Player::bets(double amt){

    *bet = amt;
    *bankroll -= amt;
    std::cout << "You now have " << *bankroll << " tokens." << std::endl;
}


void Player::discardCards(){
    
    using namespace std;

    // satisfiedWithChoices helps ensure that the player is able to
    // chose again if they make a mistake.
    
    bool satisfiedWithChoices = false;
    string answer;

    while(!satisfiedWithChoices){
        for(Card c : *hand){
            cout << "Would you like to discard the " << c << "? [y/n]" << endl;
            cin >> answer;
        
            if(answer == "y"){
                returnCards->push_back(c);
            }
        }

        if(returnCards->size() > 0){
            cout << "Here are the cards you chose to discard." << endl;
            for(Card c : *returnCards){
                cout << c << endl;
            }
            cout << "Are you satisfied with these choices? [y/n]" << endl;
        } else {
            cout << "You chose not to return any cards." << endl;
            cout << "Are you satisfied with these choices? [y/n]" << endl;
        }

        cin >> answer;
        if(answer == "y"){
            satisfiedWithChoices = true;
        } else {
            returnCards->clear();
        }
    }

    if(returnCards->size() > 0){
        for(Card c : *returnCards){
            cout << "Removing the " << c << "." << endl;
            this->removeCard(c);
        }
    }
    returnCards->clear();
}





