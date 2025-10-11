#ifndef TRADER_H
#define TRADER_H

class Trader {
    protected:
        int participantID;
        double cashBalance;
        unordered_map<int, int> portfolio;

    public:

        Trader();
        Trader(int ID, double balance);

        bool placeOrder();
        double getPortfolioValue();
        unordered_map<int, int> getPortfolio();
};

#endif
