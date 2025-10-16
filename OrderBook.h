#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "OrderList.h"
#include "Trade.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class OrderBook {
    private:
        int orderCounter = 0;
        unordered_map<string, OrderList> buyOrders;
        unordered_map<string, OrderList> sellOrders;

        unordered_map<int, Order*> allOrders;

        vector<Trade> completeTrades;

    public:

        bool submitBuyOrder(int traderID, string tickerLabel, int time, int price, int amount);
        bool submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount);

        vector<Trade>* getCompleteTrades();
        void clearTradeNotes();
};

#endif
