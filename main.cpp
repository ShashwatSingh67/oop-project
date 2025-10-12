#include "TradingSystemController.h"

#include <iostream>

using namespace std;

// main file that's gonna be handling all the big stuff

int main() {

    TradingSystemController Controller;

    Controller.dumpPerformanceInfo();

    string label;
    cout << "Retrieve ticker data for stock: ";
    cin >> label;

    Controller.marketdata.getHistoricalPrices(label);

    return 0;
}
