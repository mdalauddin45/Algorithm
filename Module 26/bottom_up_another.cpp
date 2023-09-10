#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            if(a[n-1]!=b[m-1]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }else{
                dp[i][j]=1+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}