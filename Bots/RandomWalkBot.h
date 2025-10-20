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
    
    pair<vector<int>, vector<int>> makeTradingDecision(vector<MarketState>* data, vector<int> port) override {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(1,10);
        // for each stock, take the average of the last 50, add 10% random variance, make that order.
        int result = dist(rng);
        int sc = port.size();
        vector<int> prices(sc, 0);
        if(result > 5) {

            for(int i=0; i<sc; i++) {
                port[i] += dist(rng);
                port[i] -= dist(rng);
                prices[i] = ((*data)[data->size()-1]).prices[i] += dist(rng)/2;
            }
        }
        pair<vector<int>, vector<int>> ret;
        ret.first = port;
        ret.second = prices;
        return ret;
    }
};


#endif