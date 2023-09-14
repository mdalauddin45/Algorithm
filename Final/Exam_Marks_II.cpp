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
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=0;i<=m;i++) dp[0][i]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w[i-1]<=j){
                    dp[i][j]=dp[i-1][j-w[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    if(dp[n][m]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}