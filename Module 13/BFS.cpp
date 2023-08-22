#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int dist[N];
bool vis[N];
vector<int>vac[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<vac[u].size();i++)
        {
            int v=vac[u][i];
            if(vis[v]==false)
            {
                q.push(v);
                vis[v]=true;
               dist[v]=dist[u]+1;
            }
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
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"level "<<i<<":"<<dist[i]<<" "<<endl;
    }
    return 0;
}