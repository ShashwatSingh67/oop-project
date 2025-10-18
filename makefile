CC=g++

core:                 main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp Order.cpp OrderBook.cpp Trade.cpp Trader.cpp
	g++ -o TradeForge main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp Order.cpp OrderBook.cpp Trade.cpp Trader.cpp