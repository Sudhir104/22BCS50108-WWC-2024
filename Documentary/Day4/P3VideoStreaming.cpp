#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_ITEMS = 10000;

struct Item {
    char title[100];
    int totalViews;
    double userRating;
    int releaseYear;
    double relevanceScore;
};

bool compareByPopularity(const Item& a, const Item& b) {
    return a.totalViews > b.totalViews;
}

bool compareByRecency(const Item& a, const Item& b) {
    return a.releaseYear > b.releaseYear;
}

bool compareByRelevance(const Item& a, const Item& b) {
    return a.relevanceScore > b.relevanceScore;
}

void sortItems(Item items[], int n, bool (*compare)(const Item&, const Item&)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compare(items[j], items[j + 1])) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

int main() {
    Item catalog[MAX_ITEMS];
    int n;

    cout << "Enter number of catalog items  (max " << MAX_ITEMS << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_ITEMS) {
        cout << "Invalid number of items." << endl;
        return 1;
    }

    cout << "Enter catalog items (title totalViews userRating releaseYear relevanceScore):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> ws;
        cin.getline(catalog[i].title, 100);
        cin >> catalog[i].totalViews >> catalog[i].userRating >> catalog[i].releaseYear >> catalog[i].relevanceScore;
    }

    cout << "Sorting by popularity..." << endl;
    sortItems(catalog, n, compareByPopularity);

    cout << "Top items by popularity:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << catalog[i].title << " " << catalog[i].totalViews << " " << catalog[i].userRating << " " << catalog[i].releaseYear << " " << catalog[i].relevanceScore << endl;
    }

    cout << "Sorting by recency..." << endl;
    sortItems(catalog, n, compareByRecency);

    cout << "Top items by recency:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << catalog[i].title << " " << catalog[i].totalViews << " " << catalog[i].userRating << " " << catalog[i].releaseYear << " " << catalog[i].relevanceScore << endl;
    }

    cout << "Sorting by relevance..." << endl;
    sortItems(catalog, n, compareByRelevance);

    cout << "Top items by relevance:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << catalog[i].title << " " << catalog[i].totalViews << " " << catalog[i].userRating << " " << catalog[i].releaseYear << " " << catalog[i].relevanceScore << endl;
    }

    return 0;
}