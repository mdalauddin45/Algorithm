#include<bits/stdc++.h>
using namespace std;
const int N = 20; // Maximum number of houses
vector<int> adj[N];

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // Since the roads are two-way
    }

    int k;
    cin >> k;

    int numConnectedHouses = adj[k].size(); // Count neighbors of Kamal's house

    cout << numConnectedHouses << endl;

    return 0;
}
