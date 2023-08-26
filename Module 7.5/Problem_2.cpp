#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void dfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u]=true;
    level[u]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++)
        {
            if(!visited[adj[v][i]])
            {
                q.push(adj[v][i]);
                visited[adj[v][i]]=true;
                level[adj[v][i]]=level[v]+1;
            }
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