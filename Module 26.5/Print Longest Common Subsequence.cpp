#include<bits/stdc++.h>
using namespace std;
string findLCS(int n, int m,string &s1, string &s2){
	int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;  
            } else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    cout<<findLCS(n,m,s1,s2)<<endl;
    return 0;
}