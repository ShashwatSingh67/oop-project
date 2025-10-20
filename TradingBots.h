#ifndef TRADING_BOTS_H
#define TRADING_BOTS_H

#include <string>

#include "Trader.h"

class TradingBot : public Trader {
    private:
        std::string strategyType;
        double riskTolerance;
        bool varianceEnabled;

    public:

        TradingBot();
        TradingBot(std::string strat, bool varianceEnabled);

        vector<int> makeTradingDecision(); // take in marketdata and decide what to do
};

#endif
