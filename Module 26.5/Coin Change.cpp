#include<bits/stdc++.h>
using namespace std;
long long int cnt(int coins[], int N, int sum) {
    long long int dp[N+1][sum+1];
    for (int i = 0; i <= N; i++)  dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)  dp[0][i] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][sum];
}
int main()
{
    int n;
    cin>>n;
    int ss;
    cin>>ss;
    int w[n];
    for(int i=0;i<n;i++) cin>>w[i];
    cout<<cnt(w,n,ss)<<endl;
    return 0;
}