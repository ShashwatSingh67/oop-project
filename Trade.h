#ifndef TRADE_H
#define TRADE_H

class Trade {
    private:
        int tradeID;
        int buyerBotID;
        int sellerBotID;
        

    public:
        double calculateFees();
        void updatePortfolios();
        double printTradingInfo(); // print out relevant info

};

#endif
