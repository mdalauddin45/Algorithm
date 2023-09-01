#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 105;
long long dist[N][N];
int n,m;
void dist_initialization()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
}
int main() {
    cin>>n>>m;
    dist_initialization();
    while (m--)
    {
       int a,b,w;
       cin>>a>>b>>w;
       if (dist[a][b] > (long long)w)  dist[a][b] = (long long)w;
    }
    for(int i=1;i<=n;i++) dist[i][i]=0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int q;
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        if(dist[x][y]==INF) cout<<-1<<endl;
        else cout<<dist[x][y]<<endl;
    }

    return 0;
}
