#include<bits/stdc++.h>
using namespace std;
int knapSack(int N, int W, int val[], int wt[]){
    vector<int>dp(W+1,0);
    for(int i=1;i<=W;i++){
        for(int j=0;j<N;j++){
            if(wt[j]<=i){
                dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    }
    return dp[W];
}
int main()
{
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<knapSack(n,w,val,wt)<<endl;
    return 0;
}