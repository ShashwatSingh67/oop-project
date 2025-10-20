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

        if(words.size()!= 5) {
            cout << "Incorrect use.\nCorrect format:\n";
            cout << "makebuyorder   traderID   tickerLabel   amount   price\n";
            return true;
        }

        bool result = tsc.placeBuyOrder(stoi(words[1]), words[2], stoi(words[3]), stoi(words[4]));

        if(result) {
            cout << "order placed successfully.\n";
        } else {
            cout << "order unsuccessful.\n";
        }
        return true;
        
    } else if (words[0] == "makesellorder") {
        
        if(words.size()!= 5) {
            cout << "Incorrect use.\nCorrect format:\n";
            cout << "makesellorder   traderID   tickerLabel   amount   price\n";
            return true;
        }

        bool result = tsc.placeSellOrder(stoi(words[1]), words[2], stoi(words[3]), stoi(words[4]));

        if(result) {
            cout << "order placed successfully.\n";
        } else {
            cout << "order unsuccessful.\n";
        }
        return true;
    } else if (words[0] == "maketrader") {
        int id;
        unordered_map<string, int> secs;
        if(words.size()==2) {
            id = tsc.addTrader(stoi(words[1]));
        } else if (words.size() > 2) {
            for(int i=2; i<words.size()-1; i+=2) {
                secs[words[i]] = stoi(words[i+1]);
            }
            id = tsc.addTrader(stoi(words[1]), secs);
        } else {
            id = tsc.addTrader();
        }
        cout << "Created trader with ID " << id << endl;

        return true;
    } else if (words[0] == "dumptraderinfo") {
        tsc.dumpTraderInfo(stoi(words[1]));
        return true;
    } else if (words[0] == "listorders") {
        tsc.dumpOrders();
        return true;
    } else if (words[0] == "startsim") {
        // FILL IN
        return true;
    } else if (words[0] == "endsim") {
        // FILL IN
        return true;
    }

    return false;
}