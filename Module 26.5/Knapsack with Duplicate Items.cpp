#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapSack(int N, int W, int val[], int wt[]){
    if(N==0 || W==0) return 0;
    if(dp[N][W]!=-1) return dp[N][W];
    if(wt[N-1]<=W){
        int op1=val[N-1]+knapSack(N,W-wt[N-1],val,wt);
        int op2 = knapSack(N-1,W,val,wt);
        return dp[N][W] = max(op1,op2);
    }else{
       return dp[N][W] = knapSack(N-1,W,val,wt);
    }
}
int main()
{
    int n,w;
    cin>>n>>w;
    int val[n],wt[n];
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<knapSack(n,w,val,wt)<<endl;
    return 0;
}