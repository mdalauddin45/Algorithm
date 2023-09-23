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
        vector<int>coins(n);
        for(int i=0;i<n;i++) cin>>coins[i];
        sort(coins.begin(),coins.end(), greater<int>());
        int s1=0; int s2=0;
        for(int i=0;i<n;i++){
            if(s1<=s2) s1+=coins[i];
            else s2 += coins[i];
        }
        int ans = abs(s1-s2);
        cout<<ans<<endl;
    }
    
    return 0;
}
