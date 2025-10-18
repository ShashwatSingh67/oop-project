#include "Trader.h"
#include <random>
#include <iostream>

Trader::Trader() {}

Trader::Trader(int ID, double bal) {
    participantID = ID;
    cashBalance = bal;
    availBalance = bal;
}

Trader::Trader(int ID, double bal, vector<string> securities) {
    participantID = ID;
    cashBalance = bal;
    availBalance = bal;

    int target = securities.size() / 5;
    int actual = 0;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> idGenerator(0,securities.size()-1);
    uniform_int_distribution<mt19937::result_type> securityCount(10,1000);

    while(actual < target) {
        int id = idGenerator(rng);
        string tickerLabel = securities[id];
        if(portfolio.find(tickerLabel) == portfolio.end()) {
            portfolio[tickerLabel] += securityCount(rng)*100;
        }
    }
}

Trader::Trader(int ID, double bal, unordered_map<string, int>* securities) {
    participantID = ID;
    cashBalance = bal;
    availBalance = bal;
    portfolio = *securities;
    availPortfolio = *securities;
}

void Trader::dumpPortfolio(vector<string> securities) {
    cout << "dumping trader deets: \n";
    int secSize = securities.size();
    string firstItem = securities[0];
    cout << "first item: " << firstItem << endl;
    for(int i=6; i<secSize; i++) {
        cout << "security #" << i << " out of " << secSize << endl;
        string sec = securities[i];
        cout << "sec : " << sec << " , \n";
        if(portfolio.count(sec) != 0) {
            cout << portfolio[sec] << endl;
        } else {
            cout << " 0 \n";
        }
    }
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