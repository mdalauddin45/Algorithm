#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int w[n];
    for(int i=0;i<n;i++) cin>>w[i];
    int ss;
    cin>>ss;
    int dp[n+1][ss+1];
    dp[0][0]=1;
    for(int i=1;i<=ss;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=ss;j++){
            if(w[i-1]<=j){
                dp[i][j]=dp[i][j-w[i-1]] + dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][ss]<<endl;
    return 0;
}