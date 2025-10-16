#include "TradeForgeCLI.h"
#include "TradingSystemController.h"

using namespace std;


TradeForgeCLI::TradeForgeCLI(TradingSystemController& TSC) : tsc(TSC) {
    //tsc = *Trad;
}

bool TradeForgeCLI::parseCommand(string input) {

    input += ' ';

    vector<string> words;
    string word = "";

    for(char c : input) {
        if(c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }

    int ws = words.size();
    if(words[0] == "dumpperfinfo") {
        tsc.dumpPerformanceInfo();
        return true;
    } else if (words[0] == "dumpstockprices") {
        if(ws >= 1) {
            for(int i=1; i<ws; i++) {
                tsc.marketdata.getHistoricalPrices(words[i]);
            }
        } else {
            cout << "not enough terms.\n";
        }
        return true;
    } else if (words[0] == "makebuyorder") {
        
        //tsc.placeBuyOrder()
    } else if (words[0] == "maketrader") {
        tsc.addTrader();
        cout << "Created trader with ID " << tsc.getTraderCount()-1 << endl;
    }

    return false;
}