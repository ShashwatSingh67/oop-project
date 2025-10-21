#ifndef TRADING_BOTS_H
#define TRADING_BOTS_H

#include "MarketData.h"
#include "Trader.h"

#include <string>
#include <utility>

class TradingBot : public Trader {
    private:
        std::string strategyType;
        double riskTolerance;
        bool varianceEnabled;

    protected:
        // Configuration parameters that bots can use
        int lookbackPeriod;
        int tradeAmount;

    public:

        TradingBot(int pc, int bal, vector<string> secList, int lookback = 10, int amount = 50)
            : Trader(pc, bal, secList), lookbackPeriod(lookback), tradeAmount(amount) {}; 

        virtual pair<vector<int>, vector<int>> makeTradingDecision(vector<MarketState>* data, vector<int> portfolio) = 0; 
        
        // Setters for configuration
        void setLookbackPeriod(int period) { lookbackPeriod = period; }
        void setTradeAmount(int amount) { tradeAmount = amount; }
        
        // Getters for configuration
        int getLookbackPeriod() { return lookbackPeriod; }
        int getTradeAmount() { return tradeAmount; }
};

#endif