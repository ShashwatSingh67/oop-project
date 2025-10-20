#include "TradingSystemController.h"
#include "TradeForgeCLI.h"

#include <iostream>

using namespace std;

// main file that's gonna be handling all the big stuff

int main() {

    TradingSystemController Controller;

    TradeForgeCLI cli(Controller);

    Controller.dumpPerformanceInfo();

    cin.ignore();

    string input;
    while(true) {
        cout << "> ";
        getline(cin, input);

        if(!cli.parseCommand(input)) {
            cout << "Not a valid command.\n";
        }
    }

    cout << "Retrieve ticker data for stock: ";
    cin >> input;

    Controller.marketdata.getHistoricalPrices(input);

    return 0;
}
