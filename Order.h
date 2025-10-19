#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
    private:
        int orderID;
        int traderID;
        std::string security;
        bool orderType;   // 0: SELL // 1: BUY
        int quantity;  // how much of the security is desired
        int price;     // duh
        int timestamp; // only set by 
        bool verified;    // checked before being placed into OB, and
                          // checked again before being filled.

    public:

        Order(int orderID, int traderID, std::string sec, bool type,
                int quantity, int price, int time);

        bool validate_order();
        double calculate_total_value();
        bool is_marketable();
        int getTraderID();
        int getOrderID();
        int getTimestamp();
        bool getOrderType();
        void partiallyFulfill(int quantityFulfilled);

        int getAmount();


};

#endif
