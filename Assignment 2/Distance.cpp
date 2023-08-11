#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int level[N];
void bfs(int s, int destination) {
    queue<int>q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v:adj[u]) {
            if (level[v]==-1) {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin>>q;
    while (q--) {
        int s,d;
        cin>>s>>d;
        for(int i=0;i<N;i++) level[i]=-1;
        bfs(s,d);
        cout<<level[d]<<endl;
    }
    return 0;
}
