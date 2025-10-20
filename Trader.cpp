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
            actual++;
        }
    }
    availPortfolio = portfolio;
}

Trader::Trader(int ID, double bal, unordered_map<string, int>* securities) {
    participantID = ID;
    cashBalance = bal;
    availBalance = bal;
    portfolio = *securities;
    availPortfolio = *securities;
}

vector<int> Trader::getLastIdealPortfolio() {
    return lastIdealPortfolio;
}

void Trader::setLastIdealPortfolio(vector<int> p) {
    lastIdealPortfolio = p;
}

vector<int> Trader::getPortfolioVector(vector<string> securities) {
    int ss = securities.size();
    vector<int> result(ss, 0);
    for(int i=0; i<ss; i++) {
        if(portfolio.find(securities[i]) != portfolio.end()) {
            result[i] = portfolio[securities[i]];
        }
    }
    return result;
}

void Trader::dumpPortfolio(vector<string> securities) {
    cout << "Cash Available  : " << cashBalance << endl;
    int secSize = securities.size();
    for(int i=0; i<secSize; i++) {
        string sec = securities[i];
        if(portfolio.count(sec) != 0) {
            cout << sec << " : " << portfolio[sec] << endl;
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

unordered_map<string, int> Trader::getAvailPortfolio() {
    return availPortfolio;
}

void Trader::changeAvailPortfolio(string tickerLabel, int diff) {
    availPortfolio[tickerLabel] += diff;
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