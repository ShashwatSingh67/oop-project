#ifndef TRADING_PERSON_H
#define TRADING_PERSON_H

#include "Trader.h"

class TradingPerson : public Trader {
    private:

    public:
        TradingPerson();
        void processUIOrders();
        void displayPortfolio();
};

#endif
