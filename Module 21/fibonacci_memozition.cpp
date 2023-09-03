#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N=1e5+5;
ll save[N];
ll fibo(ll n)
{
    if(n==1||n==0) return 1;
    if(save[n]!=-1) return save[n];
    return save[n]= fibo(n-1)+fibo(n-2);
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++) save[i]=-1;
    cout<<fibo(n)<<endl;
    return 0;
}