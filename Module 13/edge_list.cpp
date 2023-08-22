#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> vac;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        vac.push_back({u,v});
    }
    for(int i=0;i<vac.size();i++)
        {
            cout<<vac[i].first<<" "<<vac[i].second<<" "<<endl ;
        }
    return 0;
}