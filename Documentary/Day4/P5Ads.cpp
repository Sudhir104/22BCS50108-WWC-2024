#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Ad {
    string advertiser;  
    double bidAmount;    
    double engagementRate; 
    double remainingBudget; 

    Ad(string adv, double bid, double engagement, double budget)
        : advertiser(adv), bidAmount(bid), engagementRate(engagement), remainingBudget(budget) {}
};

bool compareAds(const Ad &a, const Ad &b) {
    if (a.bidAmount != b.bidAmount) {
        return a.bidAmount > b.bidAmount; 
    }
    if (a.engagementRate != b.engagementRate) {
        return a.engagementRate > b.engagementRate; 
    }
    return a.remainingBudget > b.remainingBudget; 
}


void displayAds(const vector<Ad> &ads) {
    cout << left << setw(20) << "Advertiser" 
         << setw(15) << "Bid Amount" 
         << setw(20) << "Engagement Rate" 
         << setw(20) << "Remaining Budget" << endl;
    cout << string(75, '-') << endl;

    for (size_t i = 0; i < ads.size(); ++i) {
        const Ad &ad = ads[i];
        cout << left << setw(20) << ad.advertiser 
             << setw(15) << ad.bidAmount 
             << setw(20) << ad.engagementRate 
             << setw(20) << ad.remainingBudget << endl;
    }
}

int main() {
    vector<Ad> ads;
    ads.push_back(Ad("Advertiser A", 500.0, 0.75, 1000.0));
    ads.push_back(Ad("Advertiser B", 300.0, 0.85, 500.0));
    ads.push_back(Ad("Advertiser C", 700.0, 0.60, 1500.0));
    ads.push_back(Ad("Advertiser D", 400.0, 0.90, 800.0));
    ads.push_back(Ad("Advertiser E", 600.0, 0.70, 1200.0));
    sort(ads.begin(), ads.end(), compareAds);
    cout << "Sorted Ads based on Bid Amount, Engagement Rate, and Remaining Budget:\n";
    displayAds(ads);

    return 0;
}