#include "OrderBook.h"

#include <iostream>

using namespace std;

bool OrderBook::submitBuyOrder(int traderID, string tickerLabel, int time, int price, int amount) { 
    // Remove all past buy and sell orders for this trader and stock
    cancelTraderOrders(traderID, tickerLabel);

    orderCounter++;
    Order neword(orderCounter, traderID, tickerLabel, true, amount, price, time);

    int amountFulfillable = amount;

    if (!sellOrders[tickerLabel].orders[price].empty()) {
        vector<Order>* competingSellOrders = &sellOrders[tickerLabel].orders[price];

        while (!competingSellOrders->empty() && amountFulfillable > 0) {
            Order* topSellOrder = &competingSellOrders->front();

            if (topSellOrder->getAmount() > amountFulfillable) {
                // Partially fulfill the sell order
                topSellOrder->partiallyFulfill(amountFulfillable);

                // Create a trade for the fulfilled amount
                Trade fulfillment(tradeCounter++, traderID, topSellOrder->getTraderID(),
                                  topSellOrder->getTimestamp(), time, price, amountFulfillable, tickerLabel);
                completeTrades.push_back(fulfillment);

                amountFulfillable = 0; // Fully fulfilled the buy order
            } else {
                // Fully fulfill the sell order and partially fulfill the buy order
                amountFulfillable -= topSellOrder->getAmount();

                Trade fulfillment(tradeCounter++, traderID, topSellOrder->getTraderID(),
                                  topSellOrder->getTimestamp(), time, price, topSellOrder->getAmount(), tickerLabel);
                completeTrades.push_back(fulfillment);

                // Remove the fully fulfilled sell order
                allOrders.erase(topSellOrder->getOrderID());
                competingSellOrders->erase(competingSellOrders->begin());
            }
        }
    }

    // If there is any remaining amount, add the buy order to the order book
    if (amountFulfillable > 0) {
        neword.partiallyFulfill(amount - amountFulfillable); // Adjust the order quantity
        buyOrders[tickerLabel].orders[price].push_back(neword);
        OrderLocation loc = {true, tickerLabel, price, (int)buyOrders[tickerLabel].orders[price].size() - 1};
        allOrders[orderCounter] = loc;
    }

    return true;
}

bool OrderBook::submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount) { 
    // Remove all past buy and sell orders for this trader and stock
    cancelTraderOrders(traderID, tickerLabel);

    orderCounter++;
    Order neword(orderCounter, traderID, tickerLabel, false, amount, price, time);

    int amountFulfillable = amount;

    if (!buyOrders[tickerLabel].orders[price].empty()) {
        vector<Order>* competingBuyOrders = &buyOrders[tickerLabel].orders[price];

        while (!competingBuyOrders->empty() && amountFulfillable > 0) {
            Order* topBuyOrder = &competingBuyOrders->front();

            if (topBuyOrder->getAmount() > amountFulfillable) {
                // Partially fulfill the buy order
                topBuyOrder->partiallyFulfill(amountFulfillable);

                // Create a trade for the fulfilled amount
                Trade fulfillment(tradeCounter++, topBuyOrder->getTraderID(), traderID,
                                  topBuyOrder->getTimestamp(), time, price, amountFulfillable, tickerLabel);
                completeTrades.push_back(fulfillment);

                amountFulfillable = 0; // Fully fulfilled the sell order
            } else {
                // Fully fulfill the buy order and partially fulfill the sell order
                amountFulfillable -= topBuyOrder->getAmount();

                Trade fulfillment(tradeCounter++, topBuyOrder->getTraderID(), traderID,
                                  topBuyOrder->getTimestamp(), time, price, topBuyOrder->getAmount(), tickerLabel);
                completeTrades.push_back(fulfillment);

                // Remove the fully fulfilled buy order
                allOrders.erase(topBuyOrder->getOrderID());
                competingBuyOrders->erase(competingBuyOrders->begin());
            }
        }
    }

    // If there is any remaining amount, add the sell order to the order book
    if (amountFulfillable > 0) {
        neword.partiallyFulfill(amount - amountFulfillable); // Adjust the order quantity
        sellOrders[tickerLabel].orders[price].push_back(neword);
        OrderLocation loc = {false, tickerLabel, price, (int)sellOrders[tickerLabel].orders[price].size() - 1};
        allOrders[orderCounter] = loc;
    }

    return true;
}

// Helper function to cancel all past buy and sell orders for a trader and stock
void OrderBook::cancelTraderOrders(int traderID, string tickerLabel) {
    // Remove trader's buy orders for the given stock
    if (buyOrders.find(tickerLabel) != buyOrders.end()) {
        for (auto& priceOrders : buyOrders[tickerLabel].orders) {
            auto& orders = priceOrders.second;
            orders.erase(remove_if(orders.begin(), orders.end(),
                                   [traderID, this](Order& order) {
                                       if (order.getTraderID() == traderID) {
                                           allOrders.erase(order.getOrderID());
                                           return true;
                                       }
                                       return false;
                                   }),
                         orders.end());
        }
    }

    // Remove trader's sell orders for the given stock
    if (sellOrders.find(tickerLabel) != sellOrders.end()) {
        for (auto& priceOrders : sellOrders[tickerLabel].orders) {
            auto& orders = priceOrders.second;
            orders.erase(remove_if(orders.begin(), orders.end(),
                                   [traderID, this](Order& order) {
                                       if (order.getTraderID() == traderID) {
                                           allOrders.erase(order.getOrderID());
                                           return true;
                                       }
                                       return false;
                                   }),
                         orders.end());
        }
    }
}

vector<Trade>* OrderBook::getCompleteTrades(){ 
    return &completeTrades;
}
void OrderBook::clearTradeNotes(){ 
    completeTrades.clear();
}

void OrderBook::listAllOrders() {
    for(auto ord : allOrders) {
        if(ord.second.type) {
            cout << "Buy order from " << 
            buyOrders[ord.second.tickerLabel].orders[ord.second.price][ord.second.index].getTraderID() << 
            " for " << buyOrders[ord.second.tickerLabel].orders[ord.second.price][ord.second.index].getAmount() <<
            " of " << ord.second.tickerLabel << " at " << ord.second.price;
            cout << endl;
        } else {
            cout << "Sell order from " << 
            sellOrders[ord.second.tickerLabel].orders[ord.second.price][ord.second.index].getTraderID() << 
            " for " << sellOrders[ord.second.tickerLabel].orders[ord.second.price][ord.second.index].getAmount() <<
            " of " << ord.second.tickerLabel << " at " << ord.second.price;
            cout << endl;
        }
    }
}

void OrderBook::listCompleteTrades(string label) {
    for(auto& order : buyOrders[label].orders) {
        for(auto& ord : order.second) {
            cout << "Buy Order ID: " << ord.getOrderID() << ", Trader ID: " << ord.getTraderID() 
                 << ", Amount: " << ord.getAmount() << ", Price: " << ord.getPrice() << endl;
        }
    }
    cout << endl;
    for(auto& order : sellOrders[label].orders) {
        for(auto& ord : order.second) {
            cout << "Sell Order ID: " << ord.getOrderID() << ", Trader ID: " << ord.getTraderID() 
                 << ", Amount: " << ord.getAmount() << ", Price: " << ord.getPrice() << endl;
        }
    }
}