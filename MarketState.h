#ifndef MARKETSTATE_H
#define MARKETSTATE_H

#include <vector>

using namespace std;

struct MarketState {
    bool historical;
    int time;
    vector<double> prices;
};

#endif