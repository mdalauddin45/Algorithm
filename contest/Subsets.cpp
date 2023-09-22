#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        vector<vector<int>> dp(n + 1, vector<int>(2*sum + 1, 0));
        dp[0][sum]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2*sum;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2*sum;j++){
                if (j - arr[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - arr[i - 1]];
                    dp[i][j] %= MOD;
                }else{
                dp[i][j]=dp[i-1][j];
                dp[i][j] %= MOD;
                }
                if (j + arr[i - 1] <= 2 * sum) {
                    dp[i][j] += dp[i - 1][j + arr[i - 1]];
                    dp[i][j] %= MOD;
                }
            }
        }
        cout<<dp[n][d+sum]<<endl;
    }
    
    return 0;
}
