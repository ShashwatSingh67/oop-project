#ifndef TRADER_H
#define TRADER_H

#include "Trade.h"
#include "OrderData/Order.h"

#include <unordered_map>
#include <vector>

using namespace std;

class Trader {
    protected:
        int participantID;
        double cashBalance;
        // could change this to be a vector to pointers of pending orders
        // and take their tradeValue, and subtract it from current cash
        // balance for a more thorough check but this is good enough
        double availBalance;
        unordered_map<string, int> availPortfolio;
        unordered_map<string, int> portfolio;
        
    public:

        Trader();
        Trader(int ID, double bal);
        Trader(int ID, double bal, vector<string> securities);
        Trader(int ID, double bal, unordered_map<string, int>* securities);

        void dumpPortfolio(vector<string> securities);
        vector<int> getPortfolioVector(vector<string> securities);
        double getCashBalance();
        double getAvailableBalance();
        void changeAvailBalance(int diff);
        void fulfillOrder(Trade* tr);
        unordered_map<string, int> getPortfolio();
        unordered_map<string, int> getAvailPortfolio();
        void changeAvailPortfolio(string tickerLabel, int diff);
};

#endif
