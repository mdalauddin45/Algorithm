#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
void bfs(int s,int level) {
    queue<pair<int,int>>q;
    vector<int>shops;
    q.push({s, 0});
    visited[s] = true;
    while (!q.empty()) {
        int first = q.front().first;
        int second = q.front().second;
        q.pop();
        if (second == level) shops.push_back(first);
        for (int v : adj[first]) {
            if (visited[v]) continue;
            visited[v] = true;
            int newLevel = second + 1;
            q.push({v,newLevel}); 
        }
    }
    if (!shops.empty()) {
        sort(shops.begin(), shops.end());
        for (int i=0;i<shops.size();i++) cout<<shops[i]<<" ";
    } else cout<<-1;
}

int main() {
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++) {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
    int l;
    cin>>l;
    bfs(0,l);
    return 0;
}
