#ifndef TRADING_SYSTEM_CONTROLLER_H
#define TRADING_SYSTEM_CONTROLLER_H

#include "Ticker.h"
#include "Trader.h"
#include "OrderBook.h"

#include <vector>
#include <string.h>

using namespace std;

class TradingSystemController {
    private:
        bool isRunning;

        vector<Trader> participants;
        vector<int> botIDs;
        vector<Trade> ticker;
        unordered_map<string, int> simulationConfig;

        OrderBook orderbook;




    public:
        // different instantiators depending on whether the program has
        // a default filepath saved to its most recent dataset used
        TradingSystemController();
        TradingSystemController(string filepath);

        // ints are used as return values to return error codes
        int startSimulation();
        int stopSimulation();

        int addBot(); // returns bot ID
        bool removeBot(int botID);

        bool dumpPerformanceInfo(); // dump all ticker data and performance metrics into external file

        bool loadCustomData(string filepath);
        bool toggleRandomVariance();
};

#endif
