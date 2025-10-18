#ifndef TRADER_H
#define TRADER_H

#include "Trade.h"
#include "Order.h"

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
        unordered_map<string, int> portfolio;
        unordered_map<string, int> availPortfolio;

    public:

        Trader();
        Trader(int ID, double bal);
        Trader(int ID, double bal, vector<string> securities);
        Trader(int ID, double bal, unordered_map<string, int>* securities);

        void dumpPortfolio(vector<string> securities);
        bool placeOrder();
        double getCashBalance();
        double getAvailableBalance();
        void changeAvailBalance(int diff);
        double getPortfolioValue();
        void fulfillOrder(Trade* tr);
        unordered_map<string, int> getPortfolio();
};

#endif
