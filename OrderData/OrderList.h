#ifndef ORDER_LIST_H
#define ORDER_LIST_H

#include "Order.h"

#include <queue>
#include <vector>
#include <unordered_map>
#include <vector>

using namespace std;

struct OrderList {
    unordered_map<int, vector<Order>> orders;
    string state;
};

#endif
