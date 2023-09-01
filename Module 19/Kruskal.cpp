#include<bits/stdc++.h>
using namespace std;
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
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int parent[1000];
int parentLevel[1000];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<Edge>v;
    vector<Edge>ans;
    dsu_set(n);
    while (m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    for(Edge val:v)
    {
        // cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
        int a=val.a;
        int b=val.b;
        int w=val.w;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA==leaderB) continue;
        ans.push_back(val);
        dsu_union(a,b);
    }
    for(Edge val:ans)
    {
        cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
    }
    return 0;
}