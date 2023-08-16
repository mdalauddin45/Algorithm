#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
const int INF = 1e9+7;
int d[N][N];
int n,m;
void dist_initialization()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
        }
    }
}
void print_matrix()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]==INF) cout<<"x"<<" ";
            else
            {
                cout<<d[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    cin>>n>>m;
    dist_initialization();
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
        d[v][u]=w;
    }
    print_matrix();

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    cout<<"After Floyd-Warshall algorithm: "<<endl;
    print_matrix();
    return 0;
}


