CC=g++

core: main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp
	g++ -o TradeForge main.cpp TradingSystemController.cpp MarketData.cpp TradeForgeCLI.cpp