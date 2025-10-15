#include "TradingSystemController.h"

#include <iostream>

using namespace std;

TradingSystemController::TradingSystemController() {
    
}

TradingSystemController::TradingSystemController(string filepath) {

}

bool TradingSystemController::dumpPerformanceInfo() {
    this->marketdata.listSecurities();
    return true;
}