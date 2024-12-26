#include <iostream>
using namespace std;
int josephus(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result + 1;
}

int main() {
    int n, k;
    cout << "Enter the number of friends (n): ";
    cin >> n;
    cout << "Enter the step count (k): ";
    cin >> k;
    
    int winner = josephus(n, k);
    cout << "The winner is friend number: " << winner << endl;
    
    return 0;
}