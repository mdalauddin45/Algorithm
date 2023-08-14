#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1005;
vector<string>g(N);
int visited[N][N];
int level[N][N];
pii parent[N][N];
int n,m;
int si,sj,di,dj;
vector<pii>direc={{1,0},{-1,0},{0,1},{0,-1}};
bool isValid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
void bfs(int i,int j)
{
    queue<pii>q;
    q.push({i,j});
    visited[i][j]=true;
    level[i][j]=0;
    while(!q.empty())
    {
        pii u=q.front();
        q.pop();
        int x=u.first;
        int y=u.second;

        for(auto d:direc)
        {
            int ni=x+d.first;
            int nj=y+d.second;
            if(!isValid(ni,nj)) continue;
            if(visited[ni][nj]) continue;
            if(g[ni][nj]=='x') continue;
            visited[ni][nj]=true;
            level[ni][nj]=level[x][y]+1;
            parent[ni][nj]={x,y};
            q.push({ni,nj});
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='s')
            {
                si=i;
                sj=j;
            }
            else if(s[j]=='e')
            {
                di=i;
                dj=j;
            }
        }
        g[i]=s;
    }
    bfs(si,sj);

    if(level[di][dj]==0) cout<<"-1"<<endl;
    else cout<<level[di][dj]<<endl;

    // vector<pii>path;
    // pii curr={di,dj};
    // while (curr!=make_pair(si,sj))
    // {
    //     path.push_back(curr);
    //     curr = parent[curr.first][curr.second];
    // }
    // path.push_back({si,sj});
    // reverse(path.begin(),path.end());
    // for(int i=1;i<path.size();i++)
    // {
    //     int x=path[i].first;
    //     int y=path[i].second;
    //     if(x==1) cout<<"D";
    //     else if(x==-1) cout<<"U";
    //     else if(y==1) cout<<"R";
    //     else if(y==-1) cout<<"L";
    //     else cout<<"-1";
    // }
    return 0;
}