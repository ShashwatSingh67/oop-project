#include "TradingSystemController.h"

#include "Bots/EmptyBot.h"
#include "Bots/RandomWalkBot.h"
// ADD bot model .h files here

#include <iostream>

using namespace std;

TradingSystemController::TradingSystemController() {
    for(int i=0; i<50; i++) { // ADD 10 RWBs
        RandomWalkBot* rwb = new RandomWalkBot(participantCount++, 500000, marketdata.getSecList());
        participants.push_back(rwb);
    }
}

TradingSystemController::TradingSystemController(string filepath) {

    for(int i=0; i<10; i++) { // ADD 10 RWBs
        RandomWalkBot* rwb = new RandomWalkBot(participantCount++, 500000, marketdata.getSecList());
        participants.push_back(rwb);
    }
    // ADD BOTS HERE
}

int TradingSystemController::startSimulation() {
    return 0;
    //
}


int TradingSystemController::stopSimulation() {
    return 0;
    //
}

bool TradingSystemController::completeNextStep() {
    for(int i=0; i<participantCount; i++) {
        TradingBot* bot = participants[i];
        vector<int> currentPos = bot->getLastIdealPortfolio();
        if(currentPos.empty()) {
            currentPos = bot->getPortfolioVector(marketdata.getSecList());
        }
        pair<vector<int>, vector<int>> desiredPos = bot->makeTradingDecision(marketdata.getAllPastPrices(), currentPos);
        // cout << "called makeTD on bot " << i << endl;
        
        bot->setLastIdealPortfolio(desiredPos.first);
        // cout << "desiredPost.first.size() : " << desiredPos.first.size() << endl;
        // if(currentPos.empty()) {
        //     currentPos = vector<int>(desiredPos.first.size(), 0);
        // }
        int vs = currentPos.size();
        for(int j=0; j<vs; j++) {
            if(desiredPos.first[j] > currentPos[j]) {
                this->placeBuyOrder(i, marketdata.getSecList()[j], abs(currentPos[j]-desiredPos.first[j]), desiredPos.second[j]);
                // cout << "placed buy order\n";
            } else if(desiredPos.first[j] < currentPos[j]) {
                this->placeSellOrder(i, marketdata.getSecList()[j], abs(desiredPos.first[j]-currentPos[j]), desiredPos.second[j]);
                // cout << "placed sell order\n";
            }
        }
    }
    return true;
}


bool TradingSystemController::dumpPerformanceInfo() {
    this->marketdata.listSecurities();
    return true;
}

int TradingSystemController::addTrader() {
    EmptyBot* newTrader = new EmptyBot(participantCount, 500000, marketdata.getSecList());
    participants.push_back(newTrader);
    participantCount++;
    return participantCount-1;
}

int TradingSystemController::addTrader(int balance) {
    EmptyBot* newTrader = new EmptyBot(participantCount, balance, marketdata.getSecList());
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
    double traderBal = participants[traderID]->getCashBalance();

    if(traderBal >= tradeCost) {
        orderbook.submitBuyOrder(traderID, tickerLabel, time, price, amount);
        participants[traderID]->changeAvailBalance(-tradeCost);
    } else {
        // cout << "trader available balance: " << traderBal << endl;
        // cout << "trade cost:               " << tradeCost << endl;
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
    double traderSecurityBal = participants[traderID]->getPortfolioValue(tickerLabel);

    if(traderSecurityBal >= amount) {
        orderbook.submitSellOrder(traderID, tickerLabel, time, price, amount);
        participants[traderID]->changeAvailPortfolio(tickerLabel, -amount);
    } else {
        // cout << "trader security balance: " << traderSecurityBal << endl;
        // cout << "amount:                  " << amount << endl;
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

void TradingSystemController::dumpOrders(string label) {
    orderbook.listCompleteTrades(label);
}

TradingSystemController::~TradingSystemController() {
    for (Trader* trader : participants) {
        delete trader;
    }
    participants.clear();
}