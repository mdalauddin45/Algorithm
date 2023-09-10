#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n];
    for(int i = 0; i < n; i++) cin >> w[i];
    int ss;
    cin >> ss;
    int dp[n + 1][ss + 1];
    for(int i = 0; i <= n; i++)  dp[i][0] = 0;
    for(int i = 1; i <= ss; i++) dp[0][i] = INT_MIN;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= ss; j++) {
            if(w[i - 1] <= j){
                int op1 = dp[i][j - w[i - 1]] + 1;
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][ss] == INT_MIN) {
        cout << "Not possible to make the sum." << endl;
    } else {
        cout << dp[n][ss] << " coins needed." << endl;
    }

    return 0;
}
