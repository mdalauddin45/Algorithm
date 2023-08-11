#include<bits/stdc++.h>
using namespace std;
const int N = 20; // Maximum number of houses
vector<int> adj[N];
bool visited[N];

void dfs(int house) {
    visited[house] = true;

    for (int neighbor : adj[house]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int k;
    cin >> k;

    // Initialize visited array
    memset(visited, false, sizeof(visited));

    dfs(k); // Perform DFS starting from Kamal's house

    int numHouses = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            numHouses++;
        }
    }

    // Subtract 1 to exclude Kamal's own house
    cout << numHouses - 1 << endl;

    return 0;
}
