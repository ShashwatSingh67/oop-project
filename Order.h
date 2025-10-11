#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
    private:
        int orderID;
        int traderID;
        std::string security;
        bool orderType;   // 0: SELL // 1: BUY
        double quantity;  // how much of the security is desired
        double price;     // duh
        double timestamp; // only set by 
        bool verified;    // checked before being placed into OB, and
                          // checked again before being filled.

    public:

        Order(int orderID, int traderID, std::string sec, bool type,
                double quantity, double price);

        bool validate_order();
        double calculate_total_value();
        bool is_marketable();


};

#endif
