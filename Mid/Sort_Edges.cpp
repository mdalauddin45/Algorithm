#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main()
{
    int n;
    cin>>n;
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}