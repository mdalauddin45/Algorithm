#include<bits/stdc++.h>
using namespace std;
const int N =20;
vector<int> adj[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    cin>>k;
    int houses=adj[k].size();
    cout<<houses<<endl;
    return 0;
}