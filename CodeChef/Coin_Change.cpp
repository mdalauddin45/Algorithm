#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, n, m;
        cin >> p >> n >> m;
        int val[n], wt[m];
        for(int i = 0; i < n; i++) cin >> val[i];
        for(int i = 0; i < m; i++) cin >> wt[i];
        bool dp[n+1][m+1];
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) dp[0][i] = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][m]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
