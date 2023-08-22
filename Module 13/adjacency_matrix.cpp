#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]=0;
            if(i==j)
            {
                adj[i][j]=1;
            }
        }
    }
    
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}