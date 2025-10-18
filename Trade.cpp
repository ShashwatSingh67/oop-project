#include "Trade.h"

Trade::Trade(int tradeID, int buyerID, int sellerID, int timePlaced, int timeFulfilled,
            int price, int amount, string tickerLabel) {
	this->tradeID = tradeID;
	this->buyerID = buyerID;
	this->sellerID = sellerID;

	this->timePlaced = timePlaced;
	this->timeFulfilled = timeFulfilled;

	this->price = price;
	this->amount = amount;

	this->tickerLabel = tickerLabel;
}

int Trade::getTradeID() {
    return this->tradeID;
}

int Trade::getBuyerID() {
    return this->buyerID;
}

int Trade::getSellerID() {
	return this->sellerID;
}


int Trade::getPrice() {
	return this->price;
}

int Trade::getAmount() {
	return this->amount;
}

int Trade::getTradeValue() {
	return this->amount * this->price;
}

string Trade::getSecID() {
	return this->tickerLabel;
}