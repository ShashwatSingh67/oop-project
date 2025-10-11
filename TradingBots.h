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

        double makeTradingDecision(); // take in marketData
        double applyRiskManagement(); // MIGHT REMOVE
};

#endif
