#ifndef TRADE_H
#define TRADE_H

class Trade {
    private:
        int tradeID;
        int buyerBotID;
        int sellerBotID;

        int timePlaced;
        int timeFulfilled;

        int price;
        int amount;
        string tickerLabel;
        

    public:

        Trade(int tradeID, int buyerID, int sellerID, int timePlaced, int timeFulfilled,
            int price, int amount, string tickerLabel);

        double calculateFees();
        void updatePortfolios();
        double printTradingInfo(); // print out relevant info

        int getTradeID();
        int getBuyerID();
        int getSellerID();

        int getPrice();
        int getAmount();
        int getTradeValue();
        int getSecID();

};

#endif
