#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const long long int INF = 1e18;
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<Edge>v;
    while (m--)
    {
        int a,b;
        long long int w;
        cin >>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }
    long long int s;
    cin>>s;
    long long int dist[n + 1];
    for (int i=1;i<=n;i++) dist[i] = INF;
    dist[s] = 0;
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<v.size();j++)
        {
            Edge ed = v[j];
            int a = ed.a;
            int b = ed.b;
            long long int w = ed.w;
            if (dist[ed.a] !=INF && dist[ed.a] + ed.w<dist[ed.b]) dist[ed.b] = dist[ed.a] + ed.w;
        }
    }
    bool flag = false;
    for (int j=0;j<v.size();j++)
    {
        Edge ed = v[j];
        int a = ed.a;
        int b = ed.b;
        long long int w = ed.w;
        if (dist[a] != INF && dist[a] + w < dist[b]) flag = true;
    }

    int q;
    cin>> q;
    while (q--)
    {
        int d;
        cin>>d;
        if (flag)
        {
            cout<<"Negative Cycle Detected "<<endl;
            break;
        }
        else if (dist[d] == INF) cout<<"Not Possible "<<endl;
        else cout<<dist[d]<<endl;
    }
    return 0;
}