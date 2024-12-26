#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;  
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long minNonZeroProduct(int p) {
    long long maxNum = (1LL << p) - 1;  // 2^p - 1
    long long complementProduct = power(maxNum - 1, (1LL << (p - 1)) - 1, MOD);
    return (maxNum % MOD * complementProduct % MOD) % MOD;
}

int main() {
    int p;
    cout << "Enter the value of p: ";
    cin >> p;

    cout << "Minimum non-zero product: " << minNonZeroProduct(p) << endl;
    return 0;
}