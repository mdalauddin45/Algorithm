#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
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
        adj[u].push_back(v);
    }

    int k;
    cin>>k;
    dfs(k);
    int houses=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i] && i!=k) houses++;
    }
    cout <<houses<<endl;
    return 0;
}
