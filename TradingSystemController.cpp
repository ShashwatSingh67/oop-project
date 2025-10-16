#include "TradingSystemController.h"

#include <iostream>

using namespace std;

TradingSystemController::TradingSystemController() {
    
}

TradingSystemController::TradingSystemController(string filepath) {

}

bool TradingSystemController::dumpPerformanceInfo() {
    this->marketdata.listSecurities();
    return true;
}

int TradingSystemController::addTrader() {
    Trader newTrader(participantCount, 5000);
    participants.push_back(&newTrader);
    participantCount++;
    return participantCount-1;
}

void TradingSystemController::incrementTime() {
    time++;
}

bool TradingSystemController::placeBuyOrder(int traderID, string tickerLabel, int amount, int price) {
    // check if the given trader has enough money to complete the trade
    // place the given order into the order book

    double tradeCost = price * amount;

    if(participants[traderID]->getAvailableBalance() < tradeCost) {
        orderbook.submitBuyOrder(traderID, tickerLabel, time, price, amount);
        participants[traderID]->changeAvailBalance(-tradeCost);
    } else {
        return false;
    }

    vector<Trade>* results = orderbook.getCompleteTrades();
    if(!(*results).empty()) {
        for(Trade tr : *results) {
            participants[tr.getBuyerID()]->fulfillOrder(&tr);
            participants[tr.getSellerID()]->fulfillOrder(&tr);
        }
        orderbook.clearTradeNotes();
    }

    return true;
}
bool TradingSystemController::placeSellOrder(int traderID, string tickerLabel, int amount, int price) {
    // FILL THIS IN
    return true;
}

int TradingSystemController::getTraderCount() {
    return participantCount;
}