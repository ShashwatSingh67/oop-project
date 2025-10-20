#ifndef TRADING_BOTS_H
#define TRADING_BOTS_H

#include "MarketData.h"
#include "Trader.h"

#include <string>

class TradingBot : public Trader {
    private:
        std::string strategyType;
        double riskTolerance;
        bool varianceEnabled;

    public:

        TradingBot(int pc, int bal, vector<string> secList)
            : Trader(pc, bal, secList) {}; // upon instantiating TradingBot, carry all args to Trader.

        virtual vector<int> makeTradingDecision(vector<MarketState>* data, vector<int> portfolio) = 0; 
        // take in marketdata and decide what position to hold
};

#endif
