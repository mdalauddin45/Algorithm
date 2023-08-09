#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int>adj[N];
int depth[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
        {
            depth[v]=depth[u]+1;
            dfs(v);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int d;
    cin>>d;
    dfs(1);
    cout<<"Depth of "<<d<<" = "<<depth[d]<<endl;
    return 0;
}