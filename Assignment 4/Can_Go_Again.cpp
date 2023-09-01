#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int INF=1e9+10;
typedef pair<int,int> pii;
vector<vector<pii>>adj;
vector<int> dist;
vector<bool> visited;
void dijkstra(int s)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty())
    {
        int x=pq.top().second;
        int y=pq.top().first;
        pq.pop();
        if(visited[x]) continue;
        visited[x]=true;
        for(auto u:adj[x])
        {
            int v=u.first;
            int w=u.second;
            if(dist[v]>dist[x]+w)
            {
                dist[v]=dist[x]+w;
                pq.push({dist[v],v});
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
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int s,t;
    cin>>s>>t;
    dijkstra(s);
    while (t--)
    {
        int d;
        cin>>d;
        if( dist[d]==INF)
            cout<<"Not Possible"<<endl;
        else
            cout<<dist[d]<<endl;
    }
    
    return 0;
}