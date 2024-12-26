#include <iostream>
using namespace std;

bool PredictTheWinner(int nums[], int n) {
    int dp[20][20] = {0}; 
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
    }
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}

int main() {
    int nums[] = {1, 5, 2};  
    int n = sizeof(nums) / sizeof(nums[0]);

    if (PredictTheWinner(nums, n)) {
        cout << "Player 1 can win." << endl;
    } else {
        cout << "Player 1 cannot win." << endl;
    }

    return 0;
}