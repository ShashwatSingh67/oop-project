#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include "StockData.h"

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class MarketData {
    private:
        int securityCount = 0;
        vector<string> securities;
        unordered_map<string, StockData*> securityData;

    public:
        MarketData();
        MarketData(string filepath);

        void loadHistoricalData(string filepath="data.csv");

        void listSecurities();

};

#endif