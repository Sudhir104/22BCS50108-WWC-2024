#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

struct Trade {
    string timestamp; 
    string stockSymbol;
    double tradePrice;
    int tradeVolume;

    Trade(string ts, string symbol, double price, int volume)
        : timestamp(ts), stockSymbol(symbol), tradePrice(price), tradeVolume(volume) {}
};

bool compareByTimestamp(const Trade &a, const Trade &b) {
    return a.timestamp < b.timestamp;
}

void groupByStockSymbol(const vector<Trade> &trades) {
    map<string, pair<int, double> > stockData;

    for (size_t i = 0; i < trades.size(); ++i) {
        const Trade &trade = trades[i];
        stockData[trade.stockSymbol].first += trade.tradeVolume; 
        stockData[trade.stockSymbol].second += trade.tradePrice; 
    }

    cout << "Stock Symbol | Total Volume | Average Price\n";
    cout << "---------------------------------------------\n";
    for (map<string, pair<int, double> >::iterator it = stockData.begin(); it != stockData.end(); ++it) {
        const string &symbol = it->first;
        int totalVolume = it->second.first;
        double averagePrice = totalVolume > 0 ? it->second.second / totalVolume : 0.0;
        cout << setw(12) << symbol << " | " << setw(12) << totalVolume << " | " << setw(14) << fixed << setprecision(2) << averagePrice << endl;
    }
}

int main() {
    vector<Trade> trades;
    trades.push_back(Trade("2023-10-01 09:30:00", "AAPL", 150.00, 100));
    trades.push_back(Trade("2023-10-01 09:31:00", "GOOGL", 2800.00, 50));
    trades.push_back(Trade("2023-10-01 09:30:30", "AAPL", 151.00, 200));
    trades.push_back(Trade("2023-10-01 09:32:00", "MSFT", 300.00, 150));
    trades.push_back(Trade("2023-10-01 09:31:30", "GOOGL", 2795.00, 75));
    trades.push_back(Trade("2023-10-01 09:33:00", "AAPL", 152.00, 300));

    sort(trades.begin(), trades.end(), compareByTimestamp);

    cout << "Trades sorted by timestamp:\n";
    for (size_t i = 0; i < trades.size(); ++i) {
        const Trade &trade = trades[i];
        cout << trade.timestamp << " | " << trade.stockSymbol << " | " << trade.tradePrice << " | " << trade.tradeVolume << endl;
    }

    cout << "\nGrouping by stock symbol:\n";
    groupByStockSymbol(trades);

    return 0;
}