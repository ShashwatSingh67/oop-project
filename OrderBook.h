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
        
};

#endif
