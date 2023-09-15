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
        int w[n];
        for(int i=0;i<n;i++) cin>>w[i];
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=INT_MIN;
            }
        }
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-w[i-1]]+1);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][1000-m]==INT_MIN) cout<<0<<endl;
        else cout<<dp[n][1000-m]<<endl;
    }
    
    return 0;
}