#include<bits/stdc++.h>
using namespace std;

int minDiff(int n, vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // It's possible to make a sum of 0 with any number of coins.
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j]; // Exclude the current coin
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]]; // Include the current coin
            }
        }
    }

    // Find the minimum difference
    int ans = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[n][j]) {
            ans = sum - 2 * j;
            break;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << minDiff(n, arr) << endl;
    }
    return 0;
}
