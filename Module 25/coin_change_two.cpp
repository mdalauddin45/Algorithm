#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n];
    for(int i = 0; i < n; i++) cin >> w[i];
    int ss;
    cin >> ss;
    int dp[n + 1][ss + 1];
    dp[0][0]=1;
    for(int i=1;i<=ss;i++)dp[0][i]=INT_MAX-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=ss;j++){
            if(w[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-w[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // if (dp[n][ss] == INT_MAX) {
    //     cout << "Not possible to make the sum." << endl;
    // } else {
    //     cout << dp[n][ss] << endl;
    // }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=ss;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//minimum coin for unbounded knapsack