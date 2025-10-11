#ifndef TRADER_H
#define TRADER_H

#include <unordered_map>

class Trader {
    protected:
        int participantID;
        double cashBalance;
        std::unordered_map<int, int> portfolio;

    public:

        Trader();
        Trader(int ID, double balance);

        bool placeOrder();
        double getPortfolioValue();
        std::unordered_map<int, int> getPortfolio();
};

#endif
