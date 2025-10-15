#ifndef TRADEFORGECLI
#define TRADEFORGECLI

#include "TradingSystemController.h"

#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

class TradeForgeCLI {
    public:

    TradingSystemController& tsc;

    TradeForgeCLI(TradingSystemController& tsc);

    void passTSC(TradingSystemController* tsc);

    bool parseCommand(string input);
};

#endif