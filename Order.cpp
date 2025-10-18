#include "Order.h"

Order::Order(int orderID, int traderID, std::string sec, bool type,
    	int quantity, int price, int time) {
	this->orderID = orderID;
	this->traderID = traderID;
	this->security = sec;
	this->orderType = type;
	this->quantity = quantity;
	this->price = price;
	this->timestamp = time;
}

int Order::getAmount() {
	return this->quantity;
}

void Order::partiallyFulfill(int quantityFulfilled) {
	this->quantity -= quantityFulfilled;
}

int Order::getTraderID() {
	return this->traderID;
}

int Order::getTimestamp() {
	return this->timestamp;
}

int Order::getOrderID() {
	return this->orderID;
}