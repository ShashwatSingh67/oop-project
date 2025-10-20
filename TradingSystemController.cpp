#include "TradingSystemController.h"

// ADD bot model .h files here

#include <iostream>

using namespace std;

TradingSystemController::TradingSystemController() {
    
}

TradingSystemController::TradingSystemController(string filepath) {
    // ADD BOTS HERE
}

int TradingSystemController::startSimulation() {
    //
}


int TradingSystemController::stopSimulation() {
    //
}




bool TradingSystemController::dumpPerformanceInfo() {
    this->marketdata.listSecurities();
    return true;
}

int TradingSystemController::addTrader() {
    Trader* newTrader = new Trader(participantCount, 5000, marketdata.getSecList());
    participants.push_back(newTrader);
    participantCount++;
    return participantCount-1;
}

int TradingSystemController::addTrader(int balance) {
    Trader* newTrader = new Trader(participantCount, balance, marketdata.getSecList());
    participants.push_back(newTrader);
    participantCount++;
    return participantCount-1;
}

int TradingSystemController::addTrader(int balance, unordered_map<string, int>& secs) {
    Trader* newTrader = new Trader(participantCount, balance, &secs);
    participants.push_back(newTrader);
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
    double traderBal = participants[traderID]->getAvailableBalance();

    if(traderBal >= tradeCost) {
        orderbook.submitBuyOrder(traderID, tickerLabel, time, price, amount);
        participants[traderID]->changeAvailBalance(-tradeCost);
    } else {
        cout << "trader available balance: " << traderBal << endl;
        cout << "trade cost:               " << tradeCost << endl;
        return false;
    }

    vector<Trade>* results = orderbook.getCompleteTrades();
    if(!results->empty()) {
        for(Trade tr : *results) {
            cout << "Trade " << tr.getTradeID() << " fulfilled.\n";
            // tr.dumpInfo();
            participants[tr.getBuyerID()]->fulfillOrder(&tr);
            participants[tr.getSellerID()]->fulfillOrder(&tr);
        }
        orderbook.clearTradeNotes();
    }

    return true;
}
bool TradingSystemController::placeSellOrder(int traderID, string tickerLabel, int amount, int price) {
    double traderSecurityBal = participants[traderID]->getAvailPortfolio()[tickerLabel];

    if(traderSecurityBal >= amount) {
        orderbook.submitSellOrder(traderID, tickerLabel, time, price, amount);
        participants[traderID]->changeAvailPortfolio(tickerLabel, -amount);
    } else {
        cout << "trader security balance: " << traderSecurityBal << endl;
        cout << "amount:                  " << amount << endl;
        return false;
    }

    vector<Trade>* results = orderbook.getCompleteTrades();
    if(!results->empty()) {
        for(Trade tr : *results) {
            cout << "Trade " << tr.getTradeID() << " fulfilled.\n";
            // tr.dumpInfo();
            participants[tr.getBuyerID()]->fulfillOrder(&tr);
            participants[tr.getSellerID()]->fulfillOrder(&tr);
        }
        orderbook.clearTradeNotes();
    }
    // FILL THIS IN
    return true;
}

int TradingSystemController::getTraderCount() {
    return participantCount;
}

void TradingSystemController::dumpTraderInfo(int trID) {
    participants[trID]->dumpPortfolio((marketdata.getSecList()));
}

void TradingSystemController::dumpOrders() {
    orderbook.listAllOrders();
}

TradingSystemController::~TradingSystemController() {
    for (Trader* trader : participants) {
        delete trader;
    }
    participants.clear();
}