#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>

struct StockData {
    std::string secName;
    std::string abbrev;
        // abbreviation (i.e. NVIDIA -> NVDA)
    std::string secType;
        // stock, commodity, 
};

#endif