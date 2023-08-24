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
   if(x>=0 && y>=0 && x<n && y<m ) return true;
   else return false;
}
void bfs(int si,int sj)
{
    vis[si][sj]=true;
    dis[si][sj]=0;
    queue<pii> q;
    q.push({si,sj});
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            vis[i][j]=false;
            dis[i][j]=INT_MAX;

        }
    }
    
}
int main()
{
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    bfs(si,sj);
    bool found=false;
    for(auto cell:path)
    {
        int new_x=si+cell.first;
        int new_y=sj+cell.second;
        if(isValid(new_x,new_y) && !vis[new_x][new_y] && arr[new_x][new_y]!='-')
        {
            bfs(new_x,new_y);
            if(vis[di][dj])
            {
                found=true;
                break;
            }
        }
    }
    if(found) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}