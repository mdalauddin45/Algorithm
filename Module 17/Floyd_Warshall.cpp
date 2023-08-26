#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int dis[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=INT_MAX;
        }
    }
    while (m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        dis[a][b]=w;
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
   
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]==INT_MAX||dis[k][j]==INT_MAX)  continue;
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}