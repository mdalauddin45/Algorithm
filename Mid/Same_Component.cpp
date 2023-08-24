#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1005;
bool vis[N][N];
int dis[N][N];
vector<pii> path={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
bool isValid(int x,int y)
{
  return(x>=0 && y>=0 && x<n && y<m);
}
void bfs(char arr[][N],int si,int sj)
{
    queue<pii>q;
    q.push({si,sj});
    vis[si][sj]=true;
    while (!q.empty())
    {
        pii u=q.front();
        q.pop();
        int x=u.first;
        int y=u.second;
        for(auto v:path)
        {
            int nx=x+v.first;
            int ny=y+v.second;
            if(isValid(nx,ny) && !vis[nx][ny] && arr[nx][ny] !='-')
            {
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    char arr[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    bfs(arr, si, sj);
    if(vis[di][dj])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}