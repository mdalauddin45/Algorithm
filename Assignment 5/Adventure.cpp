#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>w(n);
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>w[i];
        for(int i=0;i<n;i++) cin>>v[i];
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(w[i-1]<=j){
                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
          cout << dp[n][m] << endl;
    }
    
    return 0;
}