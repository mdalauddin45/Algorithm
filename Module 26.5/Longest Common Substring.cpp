#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr (string S1, string S2, int n, int m){
    int dp[n+1][m+1];
    int result =0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n,m;
    cin>>n>>m;
    cout<<longestCommonSubstr(s1,s2,n,m);
    
    return 0;
}