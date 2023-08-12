#include<bits/stdc++.h>
using namespace std;
const int N=1000;
vector<int> adj[N];
bool visited[N];
void dfs(int u,int &cnt)
{
    visited[u]=true;
    cnt++;
    for(int v:adj[u])
    {
       if(visited[v]) continue;
        dfs(v,cnt);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sizes;
    for(int i=0;i<N;i++)
    {
        if(!visited[i])
        {
            int cnt=0;
            dfs(i,cnt);
            if(cnt>1) sizes.push_back(cnt);
        }
    }
    sort(sizes.begin(),sizes.end());
    for(int size:sizes) cout<<size<<" ";
    return 0;
}