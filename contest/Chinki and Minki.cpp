#include<bits/stdc++.h>
using namespace std;
int minDiff(int n, vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    int m = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
            dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
    }
    int ans = INT_MAX;
    for (int j = m; j >= 0; j--) {
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
