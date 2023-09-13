#include<bits/stdc++.h>
using namespace std;
int minOperations(string str1, string str2) { 
    int n=str1.size();
    int m=str2.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int lcs_length = dp[n][m];
    return n+m- 2 * lcs_length;
} 
int main()
{
     string str1,str2;
    cin>>str1>>str2;
    cout<<minOperations(str1,str2)<<endl;
    return 0;
}