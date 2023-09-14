#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)  dp[i][0] = 0;
    
    for (int j = 1; j <= amount; j++) dp[0][j] = INT_MAX - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    int amount;
    cin >> amount;

    int result = coinChange(coins, amount);
    cout << result << endl;
    
    return 0;
}
