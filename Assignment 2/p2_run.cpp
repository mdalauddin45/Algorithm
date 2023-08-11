#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; // Maximum number of pizza shops
vector<int> adj[N];
bool visited[N];

vector<int> pizzaShopsInLevel(int start, int level) {
    queue<pair<int, int>> q; // Queue to perform BFS
    vector<int> shops; // Stores pizza shop numbers in the same level

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int shop = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLevel == level) {
            shops.push_back(shop);
        }

        for (int neighbor : adj[shop]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, curLevel + 1});
            }
        }
    }

    return shops;
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int level;
    cin >> level;

    // Initialize visited array for each query
    memset(visited, false, sizeof(visited));

    vector<int> shops = pizzaShopsInLevel(0, level);

    if (shops.empty()) {
        cout << -1;
    } else {
        sort(shops.begin(), shops.end());
        for (int i = 0; i < shops.size(); i++) {
            cout << shops[i];
            if (i < shops.size() - 1) {
                cout << " ";
            }
        }
    }

    return 0;
}
