#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100001;
int parent[N];
int parentLevel[N];

class Edge {
public:
    ll a, b, w;
    Edge(int a, int b, int w) : a(a), b(b), w(w) {}
};
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int node) {
    return (parent[node] == -1) ? node : parent[node] = dsu_find(parent[node]);
}
void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        if (parentLevel[leaderA] > parentLevel[leaderB]) {
            swap(leaderA, leaderB);
        }
        parent[leaderA] = leaderB;
        if (parentLevel[leaderA] == parentLevel[leaderB]) {
            parentLevel[leaderB]++;
        }
    }
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges;
    dsu_set(n);

    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(a, b, w);
    }
    sort(edges.begin(), edges.end(), cmp);
    int removedEdges = 0;
    ll total_const_cost = 0;
    for (const Edge& edge : edges) {
        int a = edge.a;
        int b = edge.b;
        int w = edge.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA != leaderB) {
            dsu_union(a, b);
          total_const_cost += w;
        } else {
            removedEdges++;
        }
    }
    if (removedEdges >= n - 1) cout << removedEdges << " " << total_const_cost << endl;
    else cout << "Not Possible" << endl;

    return 0;
}