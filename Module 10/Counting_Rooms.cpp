#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char grid[N][N];
bool visited[N][N];
int n,m;
void dfs(int i,int j)
{
    if(i<1 || i>n || j<1 || j>m || visited[i][j] || grid[i][j]=='#') return;
    visited[i][j]=true;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>grid[i][j];
    } 
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!visited[i][j] && grid[i][j]=='.')
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}