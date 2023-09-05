#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
void initializeDP(int n, int s) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }
    }
}
bool subset_sum(int n,int arr[],int s)
{
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }
    if(dp[n][s]!=-1) return dp[n][s];
    if(arr[n-1]<=s)
    {
        bool choice1=subset_sum(n-1,arr,s-arr[n-1]);
        bool choice2 = subset_sum(n-1,arr,s);
        return dp[n][s] = choice1 || choice2;
    }else{
    return dp[n][s] = subset_sum(n-1,arr,s);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int s;
    cin>>s;
    initializeDP(n,s);
    if(subset_sum(n,arr,s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}