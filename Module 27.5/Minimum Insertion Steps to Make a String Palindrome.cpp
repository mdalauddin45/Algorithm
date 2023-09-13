#include<bits/stdc++.h>
using namespace std;
int minInsertions(string s) {
    int n=s.size();
    string b=s;
    reverse(b.begin(),b.end());
    int m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
           if(i==0 || j==0) dp[i][j]=0; 
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs_length = dp[n][m];
    int inser = m-lcs_length;
    return inser;
}
int main()
{
    string s;
    cin>>s;
    cout<<minInsertions(s)<<endl;
    // int n=s.size();
    // string b=s;
    // reverse(b.begin(),b.end());
    // int m=b.size();
    // int dp[n+1][m+1];
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //        if(i==0 || j==0) dp[i][j]=0; 
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s[i-1]==b[j-1]){
    //             dp[i][j] = dp[i-1][j-1]+1;
    //         }else{
    //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    // }
    // int lcs_length = dp[n][m];
    // int del = m-lcs_length;
    // cout<<del<<endl;
    return 0;
}