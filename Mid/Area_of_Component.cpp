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
int dfs(char arr[][N],int si,int sj)
{
    vis[si][sj]=true;
    int area=(arr[si][sj]=='.')?1:0;
    for(auto v:path)
    {
        int nx=si+v.first;
        int ny=sj+v.second;
        if(isValid(nx,ny) && !vis[nx][ny] && arr[nx][ny]=='.')
        {
            area+=dfs(arr,nx,ny);
        }
    }
    return area;
}
int main()
{
    cin>>n>>m;
    char arr[N][N];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    int min_area=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && arr[i][j]=='.') min_area=min(min_area,dfs(arr,i,j));
        }
    }
    if(min_area==INT_MAX) cout<<-1<<endl;
    else cout<<min_area<<endl;
    return 0;
}