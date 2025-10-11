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
            this->securityCount++;
            StockData newSec;
            newSec.abbrev = secName;
            newSec.secID = securityCount;
            this->securityData[secName] = &newSec;
            secName = "";
        } else {
            secName += c;
        }
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