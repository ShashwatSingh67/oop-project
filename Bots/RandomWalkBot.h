#ifndef RANDOM_WALK_BOT
#define RANDOM_WALK_BOT

#include "../TradingBots.h"
#include "../MarketData.h"

#include <random>

using namespace std;

class RandomWalkBot : public TradingBot {
    public: 

    RandomWalkBot(int pc, int bal, vector<string> secList)
            : TradingBot(pc, bal, secList) {}
    
    vector<int> makeTradingDecision(vector<MarketState>* marketState, vector<int> portfolio) override {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(1,10);
        // for each stock, take the average of the last 50, add 10% random variance, make that order.
        int result = dist(rng);
        if(result > 5) {
            int sc = portfolio.size();
            for(int i=0; i<sc; i++) {
                portfolio[i] += dist(rng);
                portfolio[i] -= dist(rng);
                
            }
        }
        return portfolio;
    }
};


#endif