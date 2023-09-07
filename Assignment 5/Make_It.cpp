#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        bool dp[n+1];
        for (int i = 0; i <= n; i++) dp[i] = false;
        dp[1]=true;
        for(int i=1;i<=n;i++)
        {
            if(dp[i] && i+3<=n) dp[i+3] =true;
            if(dp[i] && i*2<=n) dp[i*2] =true;
        }
         if(dp[n]) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
    }
    return 0;
}