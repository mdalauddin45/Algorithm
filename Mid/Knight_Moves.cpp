#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=8;
vector<pii> direc={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
int dist[N][N];
bool isValid(int i,int j,int n,int m)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
int bfs(int n, int m, int ki, int kj, int qi, int qj) {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) dist[i][j]=-1;
    }
    queue<pii> q;
    q.push({ki, kj});
    dist[ki][kj] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==qi && y==qj) return dist[x][y];
        for(auto v:direc)
        {
            int nx=x+v.first;
            int ny=y+v.second;
            if(isValid(nx,ny,n,m) && dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,ki,kj,qi,qj;
        cin>>n>>m>>ki>>kj>>qi>>qj;
        cout<<bfs(n,m,ki,kj,qi,qj)<<endl;
    }

    return 0;
}
