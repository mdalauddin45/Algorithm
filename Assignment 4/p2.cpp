#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
    }

    int q;
    cin >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        vector<int> distance(n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[x] = 0;
        pq.emplace(0, x);

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distance[node]) {
                continue;
            }

            for (auto neighbor : graph[node]) {
                int next_node = neighbor.first;
                int edge_weight = neighbor.second;

                if (distance[node] + edge_weight < distance[next_node]) {
                    distance[next_node] = distance[node] + edge_weight;
                    pq.emplace(distance[next_node], next_node);
                }
            }
        }

        if (distance[y] == INF) {
            cout << -1 << endl;
        } else {
            cout << distance[y] << endl;
        }
    }

    return 0;
}
