#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
const int N = 100;
vector<int> adj[N];
bool visited[N];
void dfs(int u, int k, int s, bool flag) {
    if (u == k && s >= 0) {
        flag = true;
        return;
    }
    if (s <= 0) {
        return;
    }
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, k, s - 1, flag);
        }
    }
    visited[u] = false;
}
int main() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll x, y, k;
    cin >> x >> y >> k;
    bool flag = false;
    memset(visited, false, sizeof(visited));
    if (x == y) flag = true;
    else dfs(x, y, k, flag);
    if (!flag) cout << "YES" << endl;
    else  cout << "NO" << endl;

    return 0;
}