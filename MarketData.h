//skeleton code
//purpose of this class is to manage the market data

#ifndef MARKETDATA_H
#define MARKETDATA_H

#include <string>
#include <unordered_map>

using namespace std;

class MarketData {
private:
    unordered_map<string, double> stock_prices;
    unordered_map<string, double> stock_volumes;

public:
    // Constructor
    MarketData();

    // Destructor
    virtual ~MarketData();

    // Methods
    double getPrice(const string& stock_id) const;
    double getVolume(const string& stock_id) const;
};

#endif // MARKETDATA_H