#include "OrderBook.h"

#include <iostream>

using namespace std;

bool OrderBook::submitBuyOrder(int traderID, string tickerLabel, int time, int price, int amount){ 
    orderCounter++;
    // FILL THIS IN

    Order neword(orderCounter, traderID, tickerLabel, true, amount, price, time);

    // check if there are sell orders for the same stock at the same price
    int amountFulfillable = amount;

    if(!sellOrders[tickerLabel].orders[price].empty()) { 

        // grab pointer to the queue containing sell orders for the same stock
        // at the same price so you don't have to use that longass reference
        // every single time
        vector<Order>* competingSellOrders = &sellOrders[tickerLabel].orders[price];

        int amountFulfilled = 0;

        while(!sellOrders[tickerLabel].orders[price].empty()
        && amountFulfillable > 0) {
            Order* topSellOrder = &competingSellOrders->front();

            if(topSellOrder->getAmount() > amountFulfillable) {
                topSellOrder->partiallyFulfill(amount);
                amountFulfillable = 0;

                Trade fulfillment = Trade(tradeCounter++, traderID, topSellOrder->getTraderID(),
                    topSellOrder->getTimestamp(), time, price, amount, tickerLabel);

                completeTrades.push_back(fulfillment);

                // remove both buy and sell orders, mark the buy order as
                // completely fulfilled, make a new replica sell order
                // holding the difference as the desired amount. send
                // both portions of the fulfilled buy and sell orders to
                // completed notebook.
                // set amountFulfillable to 0
            } else if (topSellOrder->getAmount() < amountFulfillable) {
                amountFulfillable -= topSellOrder->getAmount();
                amountFulfilled += topSellOrder->getAmount();
                
                allOrders.erase(topSellOrder->getOrderID());
                competingSellOrders->erase(competingSellOrders->begin());

                Trade fulfillment = Trade(tradeCounter++, traderID, topSellOrder->getTraderID(),
                    topSellOrder->getTimestamp(), time, price, amountFulfilled, tickerLabel);
                    
                completeTrades.push_back(fulfillment);
                    
                // remove both buy and sell orders, mark the sell order
                // as complete and place a replica smaller buy order into
                // the respective book. send the portions to completed notebook.
                // change amountFulfillable accordingly and let it repeat
                // to see if there's more sell orders that can fulfill the buy.
            } else if (topSellOrder->getAmount() == amountFulfillable) {

                amountFulfilled = amountFulfillable;
                amountFulfillable = 0;
                
                Trade fulfillment = Trade(tradeCounter++, traderID, topSellOrder->getTraderID(),
                topSellOrder->getTimestamp(), time, price, topSellOrder->getAmount(), tickerLabel);

                allOrders.erase(topSellOrder->getOrderID());

                competingSellOrders->erase(competingSellOrders->begin());
                
                completeTrades.push_back(fulfillment);
                
                // remove both and mark them as complete. place nothing new into
                // the orderBook.
            }
        }
    } else {
        buyOrders[tickerLabel].orders[price].push_back(neword);
        allOrders[orderCounter] = &buyOrders[tickerLabel].orders[price].back();
    }

    cout << "Order made successfully! \n";

    cout << "traderID : " << traderID << endl;
    cout << "tickerLabel : " << tickerLabel << endl;
    cout << "time : " << time << endl;
    cout << "price : " << price << endl;
    cout << "amount : " << amount << endl;

    return true;
}
bool OrderBook::submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount){ 
    orderCounter++;
    // FILL THIS IN 

    Order neword(orderCounter, traderID, tickerLabel, false, amount, price, time);

    int amountFulfillable = amount;

    if(!buyOrders[tickerLabel].orders[price].empty()) {

        vector<Order>* competingBuyOrders = &buyOrders[tickerLabel].orders[price];

        int amountFulfilled = 0;

        while(!buyOrders[tickerLabel].orders[price].empty()
        && amountFulfillable > 0) {
            Order* topBuyOrder = &competingBuyOrders->front();

            if((*topBuyOrder).getAmount() > amountFulfillable) {
                // reduce remaining value of original buy order, completely fulfill current sell.
                (*topBuyOrder).partiallyFulfill(amount);

                amountFulfillable = 0;

                Trade fulfillment = Trade(tradeCounter++, topBuyOrder->getTraderID(), traderID,
                    topBuyOrder->getTimestamp(), time, price, amount, tickerLabel);

                completeTrades.push_back(fulfillment);
                
            } else if (topBuyOrder->getAmount() < amountFulfillable) {
                // adjust amountFulfillable, remove top buy order and repeat

                amountFulfillable -= topBuyOrder->getAmount();
                amountFulfilled   += topBuyOrder->getAmount(); 

                allOrders.erase(topBuyOrder->getOrderID());

                competingBuyOrders->erase(competingBuyOrders->begin());

                Trade fulfillment = Trade(tradeCounter++, topBuyOrder->getTraderID(), traderID,
                    topBuyOrder->getTimestamp(), time, price, amount, tickerLabel);

                completeTrades.push_back(fulfillment);

            } else if (topBuyOrder->getAmount() == amountFulfillable) {
                // remove buy order, completely fulfill sell ord.

                amountFulfilled = amountFulfillable;
                amountFulfillable = 0;

                Trade fulfillment = Trade(tradeCounter++, topBuyOrder->getTraderID(), traderID,
                    topBuyOrder->getTimestamp(), time, price, topBuyOrder->getAmount(), tickerLabel);

                allOrders.erase(topBuyOrder->getOrderID());
                
                competingBuyOrders->erase(competingBuyOrders->begin());

                completeTrades.push_back(fulfillment);

            }
        }
    } else {
        sellOrders[tickerLabel].orders[price].push_back(neword);
        allOrders[orderCounter] = &sellOrders[tickerLabel].orders[price].back();
    }

    return true;
}

vector<Trade>* OrderBook::getCompleteTrades(){ 
    return &completeTrades;
}
void OrderBook::clearTradeNotes(){ 
    // clear completeTrades
}

void OrderBook::listAllOrders() {
    for(int i=0; i<orderCounter+1; i++) {
        if(allOrders.find(i) != allOrders.end()) {
            Order order = *allOrders[i];
            cout << "Order from " << order.getTraderID() << " for " << order.getAmount() << " of something idk. \n";
        }
    }
}