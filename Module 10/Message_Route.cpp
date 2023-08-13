#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
vector<bool>visited(N,false);
vector<int>level(N,0);
vector<int>parent(N,-1);
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v]=true;
            parent[v]=u;
            level[v]=level[u]+1;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if(!visited[n]) cout<<"IMPOSSIBLE"<<endl;
    else{
        int curr=n;
    vector<int>path;
    while (curr!=-1)
    {
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto p:path)
    {
        cout<<p <<" ";
    }
    }
    return 0;
}