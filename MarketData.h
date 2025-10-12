#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include "StockData.h"
#include "MarketState.h"

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class MarketData {
    private:
        int time = 0; // counts how many ticks the simulation has gone on for
        int historyDuration = 0; // counts how many ticks pastPrices lasts for
        int securityCount = 0;
        vector<string> securities; // 
        unordered_map<string, StockData> securityData;

        vector<MarketState> pastPrices;

    public:
        MarketData();
        MarketData(string filepath);

        void loadHistoricalData(string filepath="data.csv");
        bool getHistoricalPrices(string tickerLabel);

        void listSecurities();

};

#endif