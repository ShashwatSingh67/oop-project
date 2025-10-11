CC=g++

core: main.cpp TradingSystemController.cpp MarketData.cpp
	g++ -o TradeForge main.cpp TradingSystemController.cpp MarketData.cpp