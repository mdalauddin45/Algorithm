#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        int s=1000;
        int w[n];
        for(int i=0;i<n;i++) cin>>w[i];
        bool dp[n+1][1001]={false};
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                if(w[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i][j-w[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[n][s-m]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}