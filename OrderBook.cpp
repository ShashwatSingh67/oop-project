#include "OrderBook.h"

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
        queue<Order>* competingSellOrders = &sellOrders[tickerLabel].orders[price];

        while(!sellOrders[tickerLabel].orders[price].empty()
        && amountFulfillable > 0) {
            Order* topSellOrder = &(*competingSellOrders).front();

            if((*topSellOrder).getAmount() > amountFulfillable) {
                // remove both buy and sell orders, mark the buy order as
                // completely fulfilled, make a new replica sell order
                // holding the difference as the desired amount. send
                // both portions of the fulfilled buy and sell orders to
                // completed notebook.
                // set amountFulfillable to 0
            } else if ((*topSellOrder).getAmount() < amountFulfillable) {
                // remove both buy and sell orders, mark the sell order
                // as complete and place a replica smaller buy order into
                // the respective book. send the portions to completed notebook.
                // change amountFulfillable accordingly and let it repeat
                // to see if there's more sell orders that can fulfill the buy.
            } else if ((*topSellOrder).getAmount() < amountFulfillable) {
                // remove both and mark them as complete. place nothing new into
                // the orderBook.
            }
        }
    } else {
        buyOrders[tickerLabel].orders[price].push(neword);
    }

    return true;
}
bool OrderBook::submitSellOrder(int traderID, string tickerLabel, int time, int price, int amount){ 
    orderCounter++;
    // FILL THIS IN 
    return true;
}

vector<Trade>* OrderBook::getCompleteTrades(){ 
    return &completeTrades;
}
void OrderBook::clearTradeNotes(){ 
    // clear completeTrades
}