#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; // Assuming maximum number of nodes
vector<int> adj[N];
int dist[N];

void bfs(int source, int destination) {
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--) {
        int s, d;
        cin >> s >> d;
        memset(dist, -1, sizeof(dist));
        bfs(s, d);
        cout << dist[d] << endl;
    }

    return 0;
}
