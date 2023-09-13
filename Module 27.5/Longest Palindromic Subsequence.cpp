#include<bits/stdc++.h>
using namespace std;
int longestPalinSubseq(string A) {
    int n=A.size();
    string B=A;
    reverse(B.begin(),B.end());
    int m=B.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string ans;
    while (i!=0 && j!=0)
    {
        if(A[i-1] == B[j-1]){
            ans+=A[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j]<dp[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
    }
    return ans.size();
}
int main()
{
    string A;
    cin>>A;
    
    cout<<longestPalinSubseq(A)<<endl;
    return 0;
}