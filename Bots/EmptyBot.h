#ifndef EMPTY_BOT
#define EMPTY_BOT

#include "../TradingBots.h"
#include "../MarketData.h"

using namespace std;

class EmptyBot : public TradingBot {
    public: 

    EmptyBot(int pc, int bal, vector<string> secList)
            : TradingBot(pc, bal, secList) {}
    
    vector<int> makeTradingDecision(vector<MarketState>* marketState, vector<int> portfolio) override {
        return portfolio;
    }
};


#endif