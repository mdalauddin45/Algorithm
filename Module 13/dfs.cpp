#include<bits/stdc++.h>
using namespace std;
const int N=1005;
// int dist[N];
bool vis[N];
vector<int>vac[N];
void dfs(int s)
{
    vis[s]=true;
    cout<<s<<endl;
   for(int i=0;i<vac[s].size();i++){
    int child = vac[s][i];
    if(vis[child]==false)
    {
        vis[child]=true;
        dfs(child);
    }
   }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        vac[u].push_back(v);
        vac[v].push_back(u);
    }
    dfs(1);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"level "<<i<<":"<<dist[i]<<" "<<endl;
    // }
    return 0;
}