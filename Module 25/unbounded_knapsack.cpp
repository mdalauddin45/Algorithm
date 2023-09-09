#include<bits/stdc++.h>
using namespace std;
int unbounded_knapsack(int n,int s,int val[],int w[])
{
    if(n==0 || s==0) return 0;
    if(w[n-1]<=s){
    int op1=val[n-1]+unbounded_knapsack(n,s-w[n-1],val,w);
    int op2=unbounded_knapsack(n-1,s,val,w);
    return max(op1,op2);
    }else{
    return unbounded_knapsack(n-1,s,val,w);
    }
}
int main()
{
    int n,s;
    cin>>n>>s;
    int val[n],w[n];
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>w[i];
    cout<<unbounded_knapsack(n,s,val,w);
    return 0;
}