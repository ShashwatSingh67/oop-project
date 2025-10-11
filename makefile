CC=gcc
CFLAGS=-I

core: main.cpp OrderBookData/TradingSystemController.cpp
	gcc -o TradeForge main.cpp OrderBookData/TradingSystemController.cpp -I