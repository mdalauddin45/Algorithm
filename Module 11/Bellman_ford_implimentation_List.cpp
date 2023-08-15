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
    for(int i=1;i<=n;i++)
    {
        //all edges relaxtion
        for(int j=1;j<=n;j++)
        {
            for(pii vpair:g[j])
            {
                int v=vpair.first;
                int w=vpair.second;
                if(dis[j]!=inf && dis[v]>dis[j]+w)
                {
                    dis[v]=dis[j]+w;
                }
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
        g[u].push_back({v,w});
    }
    bellman_ford(1);
    for(int i=1;i<=n;i++)
    {

        cout<<"Distance of "<<i<<": "<<dis[i]<<" "<<endl;
    }
    
    return 0;
}


