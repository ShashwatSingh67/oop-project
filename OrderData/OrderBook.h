#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "OrderList.h"
#include "../Trade.h"

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct OrderLocation {
    bool type; // TRUE: BUY, FALSE: SELL
    string tickerLabel;
    int price;
    int index;
};

class OrderBook {
    private:
        int orderCounter = 0;
        int tradeCounter = 0;
        unordered_map<string, OrderList> buyOrders;
        unordered_map<string, OrderList> sellOrders;

        unordered_map<string, int> lastSoldPrices;

        map<int, OrderLocation> allOrders;

        vector<Trade> completeTrades;

    public:

        bool submitBuyOrder(int traderID, string tickerLabel, int time, int price, int amount);
        bool submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount);

        vector<Trade>* getCompleteTrades();
        void clearTradeNotes();
        void listAllOrders();
        void listCompleteTrades();
        void listCompleteTrades(string label);
        void cancelTraderOrders(int traderID, string tickerLabel);
        void setLastSoldPrices(vector<int> prices);
        vector<double> getLastSoldPrice(vector<string> labels);
};




#endif
