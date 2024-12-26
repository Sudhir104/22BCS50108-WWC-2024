#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
const int MAX_TRANSACTIONS = 100000;
struct Transaction {
    string transactionID;
    double amount;
    int frequency;
    string location;
    double suspiciousScore;
};

double calculateSuspiciousScore(double amount, int frequency, const string& location) {
    return (amount * 0.5) + (frequency * 0.3) + (location == "high-risk" ? 20.0 : 0.0);
}

void sortTransactions(Transaction transactions[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (transactions[j].suspiciousScore < transactions[j + 1].suspiciousScore) {
                swap(transactions[j], transactions[j + 1]);
            }
        }
    }
}

void displayTopTransactions(Transaction transactions[], int n, int topN) {
    cout << "\nTop " << topN << " Suspicious Transactions:\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < min(topN, n); ++i) {
        cout << "Transaction ID: " << transactions[i].transactionID
             << ", Score: " << transactions[i].suspiciousScore
             << ", Amount: " << transactions[i].amount
             << ", Frequency: " << transactions[i].frequency
             << ", Location: " << transactions[i].location << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int n;
    cout << "Enter the number of transactions: ";
    cin >> n;
    if (n > MAX_TRANSACTIONS) {
        cout << "Maximum allowed transactions are " << MAX_TRANSACTIONS << ".\n";
        return 1;
    }
    Transaction transactions[MAX_TRANSACTIONS];
    for (int i = 0; i < n; ++i) {
        transactions[i].transactionID = "TXN" + to_string(i + 1);
        transactions[i].amount = rand() % 10000 + 1; 
        transactions[i].frequency = rand() % 100 + 1;
        transactions[i].location = (rand() % 10 < 3) ? "high-risk" : "low-risk"; 
        transactions[i].suspiciousScore = calculateSuspiciousScore(
            transactions[i].amount, transactions[i].frequency, transactions[i].location);
    }

    sortTransactions(transactions, n);

    int topN;
    cout << "Enter the number of top transactions to display: ";
    cin >> topN;
    displayTopTransactions(transactions, n, topN);

    return 0;
}