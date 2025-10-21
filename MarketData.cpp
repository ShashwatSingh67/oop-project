#include "MarketData.h"

#include <fstream>
#include <iostream>

MarketData::MarketData() {
    loadHistoricalData("data.csv");
}

void MarketData::loadHistoricalData(string filepath) {
    // DEFAULT DATA FILEPATH: data.txt

    ifstream file(filepath);
    string currentLine;
    getline(file, currentLine);

    // recording security ticker labels to MarketData object
    currentLine+=',';
    string secName;
    for(auto c : currentLine) {
        if(c == ',' && secName!="") {
            this->securities.push_back(secName);
            StockData newSec;
            newSec.abbrev = secName;
            newSec.secID = this->securityCount;
            this->securityCount++;
            this->securityData[secName] = newSec;
            // cout << "Recorded security " << secName << " with ID " << newSec.secID << endl;
            secName = "";
        } else {
            secName += c;
        }
    }

    string val;
    int secCounter = 0;
    int lineCounter = 0;
    while(getline(file, currentLine)) {

        currentLine += ',';
        MarketState thisTime;
        thisTime.historical = true;
        thisTime.time = lineCounter++;
        this->historyDuration++;
        
        for(auto c : currentLine) {
            if(c == ',' && val != "") {
                thisTime.prices.push_back(stod(val));
                val = "";
            } else {
                val += c;
            }
        }
        this->pastPrices.push_back(thisTime);
    }

    file.close();
}

void MarketData::listSecurities() {
    cout << "List of all " << this->securities.size() <<" securities stored:\n";
    for(int i=0; i<this->securities.size(); i++) {
        cout << this->securities[i];
        if(i!=this->securities.size()-1) cout << " - ";
    }
    cout << endl;
    return;
}

bool MarketData::getHistoricalPrices(string tickerLabel) {
    int stockID;
    if(this->securityData.find(tickerLabel) == this->securityData.end()) {
        cout << "Invalid ticker label\n";
        return false;
    }
    stockID = this->securityData[tickerLabel].secID;

    // for(int i=0; i<this->securityCount; i++) {
    //     cout << this->pastPrices[0].prices[i] << " , ";
    // }
    // cout << endl;

    cout << "Past "<< historyDuration << " Prices for " << tickerLabel << ", ID " << stockID << ": \n";
    for(int i=0; i<historyDuration; i++) {
        cout << this->pastPrices[i].prices[stockID] << " - ";
    }
    cout << endl;
    return true;
}

vector<string> MarketData::getSecList() {
    return securities;
}

vector<MarketState>* MarketData::getAllPastPrices() {
    return &pastPrices;
}