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
        int arr[n],s=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            s=s+arr[i];
        }
        if(s%2==0){
            int mid=s/2;
            bool dp[n+1][mid+1];
            for(int i=1;i<=n;i++) dp[0][i] = false;

            for(int i=1;i<=n;i++){
                for(int j=0;j<=mid;j++){
                    if(arr[i-1]<=j){
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            if(dp[n][mid]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}