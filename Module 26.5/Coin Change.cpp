#include <bits/stdc++.h>
using namespace std;
 long long int count(int coins[], int N, int sum){
        long long int dp[N+1][sum+1];
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++) dp[0][i] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= sum; j++) {
                if (coins[i - 1] <= j){
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
            }
        }
        return dp[N][sum];
    }
int main()
{
    long long n,s;
    cin>>n>>s;
    long long w[n];
    for(int i=0;i<n;i++) cin>>w[i];
    cout <<count(w,n,s) << endl;
    return 0;
}