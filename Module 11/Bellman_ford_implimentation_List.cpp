#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int inf=1e9+10;
typedef pair<int,int> pii;
vector<pii>g[N];
vector<pair<pii,int>>list_of_edges;
int dis[N];
int n,m;
void bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }
    dis[s]=0;
    for(int i=1;i<n;i++)
    {
        for(auto e:list_of_edges)
        {
            int u=e.first.first;
            int v=e.first.second;
            int w=e.second;
            // dis[v]=min(dis[v],dis[u]+w);
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }

}
int main()
{
    cin>>n>>m;
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        // g[u].push_back({v,w});
        list_of_edges.push_back({{u,v},w});
    }
    bellman_ford(1);
    for(int i=1;i<=n;i++)
    {

        cout<<"List of "<<i<<": "<<dis[i]<<" "<<endl;
    }
    
    return 0;
}


