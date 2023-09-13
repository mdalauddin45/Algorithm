#include<bits/stdc++.h>
using namespace std;
int shortestCommonSupersequence(string X, string Y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return m+n - dp[m][n];
}
int main()
{
    string X,Y;
    cin>>X>>Y;
    int m=X.size();
    int n =Y.size();
    cout<<shortestCommonSupersequence(X,Y,m,n)<<endl;
    return 0;
}