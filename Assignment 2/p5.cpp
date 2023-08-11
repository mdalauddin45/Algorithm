#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, int& componentSize) {
    visited[node] = true;
    ++componentSize;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, componentSize);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<bool> visited(N + 1, false);
    vector<int> componentSizes;

    for (int node = 1; node <= N; ++node) {
        if (!visited[node]) {
            int componentSize = 0;
            dfs(node, graph, visited, componentSize);

            if (componentSize > 1) {
                componentSizes.push_back(componentSize);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes) {
        cout << size << " ";
    }

    return 0;
}
