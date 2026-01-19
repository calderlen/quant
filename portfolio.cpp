// portfolio.cpp

#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>
#include <chrono>
#include <fstream>
#include <iostream>
#include <cctype>

# 

/*
functions needed

total net return
    - which requires
        - market price
        - accrued interest
            - nominal value
            - coupon rate
            - day-count fraction
        - transaction costs
            - including
                - broker fees
                - exchagne feeds
                - transaction taxes
                - custody feeds prorated over holding period
        - distributions



portfolio risk and return metrics
    - three asset
        - E(R_p) = sum_{i=A}^{C}w_i*E(R_i)
        - sigma_{E(R_p)}^2 = sum_{i=A}^{C}sum_{j=A}^{C}w_i*w_j*sigma_{i,j}
    - n asset
        - E(R_p) = sum_{i=1}^{n}w_i*mu_i
        - sigma_{E(R_p)}^2 = sum_{i=1}^{n}sum_{j=1}^{n}w_i*w_j*sigma_{i,j}

diversification: holding combinations of instruments that are not perfectly positively correlated reduces portfolio risk



*/



/*
TODO: csv parsing
TODO: date handling
*/

using Date = std::chrono::sys_days;



enum class AssetClass {Cash, Equity, FixedIncome, Commodity, Forex, Crypto, Other};

enum class InstrumentType {Spot, Stock, ETF, Bond, CD, Option, Future, Fund, Other};

struct InstrumentID {
    std::string ticker;
    AssetClass asset_class;
    InstrumentType instrument_type;
};

enum class TradeAction {Buy, Sell, SellShort, BuyToCover};
    
struct Trade {
    InstrumentID instrument;
    TradeAction action;
    double quantity;
    double price;
    double fees;
    double taxes;
};

enum class CashflowType {
    Dividend,              // Qualified Dividend, Cash Dividend
    CapitalGainShort,      // Short Term Cap Gain Reinvest
    CapitalGainLong,       // Long Term Cap Gain Reinvest
    WithholdingTax,        // Foreign Tax Paid
    Interest,              // Credit Interest
    Deposit,               // MoneyLink Deposit, Auto S1 Credit
    Withdrawal,            // Auto S1 Debit
    CardPurchase,          // Visa Purchase
    CashInLieu,            // Cash In Lieu
    Fee,                   // standalone fees if they appear
    Other
};


struct SchwabImport{
    std::vector<Trade> trades;
    std::vector<CashflowType> cashflows;
    std::vector<Date> dates;
};


SchwabImport load_schwab_csv(const std::string& path)
{
    
}

