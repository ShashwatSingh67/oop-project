CC=g++

core:                 main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp OrderData/Order.cpp OrderData/OrderBook.cpp Trade.cpp Trader.cpp
	g++ -o TradeForge main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp OrderData/Order.cpp OrderData/OrderBook.cpp Trade.cpp Trader.cpp