#include "Trader.h"

Trader::Trader() {}

Trader::Trader(int ID, double bal) {
    participantID = ID;
    cashBalance = bal;
    availBalance = bal;
}

double Trader::getCashBalance() {
    return cashBalance;
}

double Trader::getAvailableBalance() {
    return availBalance;
}

void Trader::changeAvailBalance(int diff) {
    availBalance += diff;
}

void Trader::fulfillOrder(Trade* tr) {

    // add / subtract relevant amount to cash and available balance
    // when trade is completed
    int diff = tr->getTradeValue();
    if(participantID == tr->getBuyerID()) diff = -diff;
    else availBalance += tr->getTradeValue();
    cashBalance += tr->getTradeValue();
    
    portfolio[tr->getSecID()] = portfolio[tr->getSecID()] + tr->getAmount();

    cashBalance += diff;
}