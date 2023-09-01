#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];
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

    int s;
    cin>>s;

    int q;
    cin>>q;

    for (int i =0;i<q;i++) {
        int d;
        cin>>d;

        vector<int> dist(n + 1, INT_MAX);
        dist[s] = 0;

        for (int j = 0; j < n - 1; j++) {
            for (Edge edge : v) {
                int u = edge.a;
                int v = edge.b;
                int w = edge.w;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        bool negativeCycle = false;
        for (Edge edge : v) {
            int u = edge.a;
            int v = edge.b;
            int w = edge.w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) {
            cout << "Negative Cycle Detected" << endl;
            break;
        } else if (dist[d] == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[d] << endl;
        }
    }

    return 0;
}