#ifndef RANDOM_WALK_BOT
#define RANDOM_WALK_BOT

#include "../TradingBots.h"

#include <random>

class RandomWalkBot : public TradingBot {
    vector<int> makeTradingDecision() {
        // for each stock, take the average of the last 50, add 10% random variance, make that order.
    }
};


#endif