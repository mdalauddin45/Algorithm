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
        int w[n], v[n];
        for(int i=0;i<n;i++) cin>>w[i];
        for(int i=0;i<n;i++) cin>>v[i];
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w[i-1]<=j){
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
          cout << dp[n][m] << endl;
    }
    
    return 0;
}