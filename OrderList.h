#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include "Order.h"

#include <queue>

struct OrderList {
    unordered_map<int, vector<Order>> orders;
    string state;
};

#endif
