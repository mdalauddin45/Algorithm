#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty()) {
        int u=q.front();
        q.pop();

        for (int v:adj[u]) {
            if (!visited[v]) {
                visited[v]=true;
                level[v]=level[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
   while (q--) {
        int s,d;
        cin>>s>>d;
        for (int i=0;i<N;i++) {
            visited[i] = false;
            level[i] = -1;
        }
        bfs(s);
        if(level[d]!=-1) cout<<level[d]<<endl;
        else if(s==d) cout<<0<<endl;
        else cout<<-1<<endl;
        
    }
    return 0;
}