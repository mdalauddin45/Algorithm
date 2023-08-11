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
    dfs(0);
    int l;
    cin>>l;
    if(level[l]==-1)
    {
        cout<<"-1";
        return 0;
    }else{
        
    for(int i=0;i<n;i++)
    {
        if(level[i]==l)
        {
            cout<<i<<" ";
        }
    }
    }
    return 0;
}