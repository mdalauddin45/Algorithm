#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=8;
int level[N][N];
int visited[N][N];
vector<pii> direc={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
bool isValid(int i,int j)
{
    return (i>=0 && i<8 && j>=0 && j<8);
}
void bfs(int i,int j)
{
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    level[i][j] = 0;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;

        for (auto d : direc) {
            int ni = x + d.first;
            int nj = y + d.second;

            if (isValid(ni, nj) && !visited[ni][nj]) {
                visited[ni][nj] = true;
                level[ni][nj] = level[x][y] + 1;
                q.push({ni, nj});
            }
        }
    }
}
void reset_level_visit()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            level[i][j]=0;
            visited[i][j]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x,y;
        cin>>x>>y;
        int si,sj,di,dj;
        si=x[0]-'a';
        sj=x[1]-'1';
        di=y[0]-'a';
        dj=y[1]-'1';
        // cout<<si<<" "<<sj<<" "<<di<<" "<<dj<<endl;//index of source and destination
        bfs(si,sj);
        cout<<level[di][dj]<<endl;
       reset_level_visit();
    }
    return 0;
}