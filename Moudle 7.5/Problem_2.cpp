#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
        {
            level[v]=level[u]+1;
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
    dfs(1);
    int l;
    cin>>l;
    cout<<"Level of "<<l<<" = "<<level[l]<<endl;
    return 0;
}