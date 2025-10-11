#include "TradingSystemController.h"

using namespace std;

TradingSystemController::TradingSystemController() {
    
}

TradingSystemController::TradingSystemController(string filepath) {

}

bool TradingSystemController::dumpPerformanceInfo() {
    this->marketdata.listSecurities();
    return true;
}