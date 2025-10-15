#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "OrderList.h"

#include <unordered_map>
#include <string>

using namespace std;

class OrderBook {
    private:
        unordered_map<string, OrderList> buyOrders;
        unordered_map<string, OrderList> sellOrders;

    public:
        bool submitBuyOrder(int traderID, string tickerLabel, int time, int price, int amount);
        bool submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount);
};

#endif
