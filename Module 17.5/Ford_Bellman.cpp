#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
     int u;
     int v;
     int w;
     Edge(int u,int v,int w)
     {
            this->u=u;
            this->v=v;
            this->w=w;
     }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<Edge> v;
    while (m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
        // cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<endl;
    }
    int dist[n+1];
    for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v.size();j++)
        {
            Edge ed=v[j-1];
            int a=ed.u;
            int b=ed.v;
            int w=ed.w;
            if(dist[a]!=INT_MAX && dist[a]+w<dist[b])
            {
                dist[b]=dist[a]+w;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]!=INT_MAX)
        {
            cout<<dist[i]<<" ";
        }
        else
        {
            cout<<30000<<" ";
        }
    }
    
    
    return 0;
}