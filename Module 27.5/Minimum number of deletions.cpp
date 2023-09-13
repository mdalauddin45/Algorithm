#include<bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n) { 
    string str2=str;
    reverse(str2.begin(),str2.end());
    int m=str2.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
           if(i==0 || j==0) dp[i][j]=0; 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs_length = dp[n][m];
    return n-lcs_length;
}
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    cout<<minDeletions(str,n)<<endl;
    return 0;
}