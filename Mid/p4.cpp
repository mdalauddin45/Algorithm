#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9;

vector<pair<int, int>> graph[N];
int dist[N];

void dijkstra(int source, int n) {
    fill(dist, dist + n + 1, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    int source;
    cin >> source;

    int t;
    cin >> t;

    while (t--) {
        int destination, costThreshold;
        cin >> destination >> costThreshold;

        dijkstra(source, n);

        if (dist[destination] <= costThreshold) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
