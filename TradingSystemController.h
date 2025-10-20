#ifndef TRADINGSYSTEMCONTROLLER_H
#define TRADINGSYSTEMCONTROLLER_H

#include "Ticker.h"
#include "Trader.h"
#include "OrderData/OrderBook.h"
#include "StockData.h"
#include "MarketData.h"

#include <vector>
#include <string>

using namespace std;

class TradingSystemController {
    private:
        bool isRunning;
        int participantCount = 0;
        int time = 0;

        vector<TradingBot*> participants;
        vector<Trade> ticker;
        unordered_map<string, int> simulationConfig;
        
        OrderBook orderbook;
        
    public:

        MarketData marketdata; //MOVE BACK TO PRIVATE FOR FINAL


        // different instantiators depending on whether the program has
        // a default filepath saved to its most recent dataset used
        TradingSystemController();
        TradingSystemController(string filepath);

        // ints are used as return values to return error codes
        int startSimulation();
        int stopSimulation();
        bool completeNextStep();

        int addBot(); // returns bot ID
        bool removeBot(int botID);

        int addTrader();
        int addTrader(int bal);
        int addTrader(int bal, unordered_map<string, int>& secs);
        int getTraderCount();

        bool dumpPerformanceInfo(); // dump all ticker data and performance metrics into external file

        bool loadCustomData(string filepath);
        bool toggleRandomVariance();

        bool placeBuyOrder(int traderID, string tickerLabel, int amount, int price);
        bool placeSellOrder(int traderID, string tickerLabel, int amount, int price);

        void incrementTime();

        void dumpTraderInfo(int trID);
        void dumpOrders();


        /// REMOVE ALL FUNCTIONS BELOW THIS POINT
        // funcs below here are used for debugging purposes and for
        // constructing the final TSC. they should not be included
        // in the final version of this assessment.

        bool parseCommand(string command);

        ~TradingSystemController();
};

#endif
