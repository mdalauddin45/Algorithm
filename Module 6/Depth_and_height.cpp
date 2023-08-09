#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(visited[v]==true) continue;
        depth[v]=depth[u]+1;
        dfs(v);
        height[u]=max(height[u],height[v]+1);
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
        adj[u].push_back(v); // directed
        // adj[v].push_back(u); // undirected
    }

    dfs(1);

    // cout<<"visited array\n";
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node "<<i<<" Status "<<visited[i]<<endl;
    // }

    cout<<"depth array\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<" depth "<<depth[i]<<endl;
    }

    // cout<<"height array\n";
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node "<<i<<" height "<<height[i]<<endl;
    // }
    return 0;
}