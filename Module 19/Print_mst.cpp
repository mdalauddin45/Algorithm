#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int> pii;
vector<pii>v[N];
bool vis[N];
class Edge{
    public:
        int a,b,w;
        Edge(int a,int b,int w)
        {
            this->a=a;
            this->b=b;
            this->w=w;
        }
};
class cmp{
    public:
        bool operator()(Edge a,Edge b){
            return a.w>b.w;
        }
};
void prims(int s)
{
    priority_queue<Edge,vector<Edge>,cmp>pq;
    vector<Edge>edgeList;
    pq.push(Edge(s,s,0));
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a=parent.a;
        int b=parent.b;
        int w=parent.w;
        if(vis[b]) continue;
        vis[b]=true;
        edgeList.push_back(parent);
        for(int i=0;i<v[b].size();i++)
        {
            pii child =v[v][i];
            
        }
    }
    
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    prims(1);
    return 0;
}