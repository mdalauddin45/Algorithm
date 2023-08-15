#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int inf=1e9+10;
typedef pair<int,int> pii;
vector<pii>g[N];
vector<pair<pii,int>>list_of_edges;
int dis[N];
int n,m;
bool flag=false;
void bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }
    dis[s]=0;
    for(int i=1;i<=n;i++)
    {
        flag=false;
        for(int j=0;j<list_of_edges.size();j++)
        {
            int u=list_of_edges[j].first.first;
            int v=list_of_edges[j].first.second;
            int w=list_of_edges[j].second;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                flag=true;
            }
        }
        if(!flag)
        {
            break;
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
    bellman_ford(1);  //complexity O(n*m)
     if(flag)
    {
        cout<<"Negative cycle found"<<endl;
    }else{
    for(int i=1;i<=n;i++)
    {

        cout<<"List of "<<i<<": "<<dis[i]<<" "<<endl;
    }
    }
    
    return 0;
}


