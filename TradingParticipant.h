//skeleton code

#ifndef TRADINGPARTICIPANT_H
#define TRADINGPARTICIPANT_H

#include <string>
#include <unordered_map>

using namespace std;

class TradingParticipant {
protected:
    std::string participant_id;
    double balance;
    std::unordered_map<string, int> portfolio;

public:
    // Constructor
    TradingParticipant(const string& id, double initial_balance);

    // Destructor
    virtual ~TradingParticipant();

    // Methods
    virtual bool place_order(const string& order) = 0;
    virtual double get_portfolio_value() = 0;
};

#endif 