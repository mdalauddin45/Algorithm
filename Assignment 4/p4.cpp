#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[1000];
int parentLevel[1000];

void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node) {
    while (parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentLevel[leaderA] > parentLevel[leaderB]) {
            parent[leaderB] = leaderA;
        } else if (parentLevel[leaderB] > parentLevel[leaderA]) {
            parent[leaderA] = leaderB;
        } else {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> v;
    vector<vector<Edge>> graph(n + 1);

    dsu_set(n);

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
        graph[a].push_back(Edge(a, b, w)); // Store the graph
    }

    sort(v.begin(), v.end(), cmp);

    int source;
    cin >> source;

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int destination;
        cin >> destination;

        vector<int> dist(n + 1, INT_MAX);
        dist[source] = 0;

        // Bellman-Ford algorithm to find the minimum cost path
        for (int j = 0; j < n - 1; j++) {
            for (const Edge& edge : v) {
                int u = edge.a;
                int v = edge.b;
                int w = edge.w;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative cycles
        bool negativeCycle = false;
        for (const Edge& edge : v) {
            int u = edge.a;
            int v = edge.b;
            int w = edge.w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle) {
            cout << "Negative Cycle Detected" << endl;
        } else if (dist[destination] == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[destination] << endl;
        }
    }

    return 0;
}
