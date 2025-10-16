#ifndef TRADINGBOTS_H
#define TRADINGBOTS_H

#include <string>
#include <unordered_map>
#include <memory>
#include "TradingParticipant.h"
#include "MarketData.h"

class TradingBots : public TradingParticipant{
protected:
    std::string strategy_type;
    double risk_tolerance;
    double variance;

public:
    // Constructor
    TradingBots(const std::string& participant_id, double initial_balance,
                const std::string& strat_type, double risk_tol, double var);

    // Destructor
    virtual ~TradingBots();

    // Abstract method - must be implemented by derived classes
    virtual std::unordered_map<std::string, int> make_trading_decision(
        const MarketData& market_data) = 0;

    // getter 
    std::string getTradingStrategy() const;
    double getVariance() const;

    // setter
    void setVariance(double var);
};

#endif