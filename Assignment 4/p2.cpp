#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int N, E;
    cin >> N >> E;

    // Initialize the distance matrix with INF
    vector<vector<int>> distance(N + 1, vector<int>(N + 1, INF));

    // Initialize the diagonal elements with 0
    for (int i = 1; i <= N; ++i) {
        distance[i][i] = 0;
    }

    // Read edge weights and populate the distance matrix
    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        distance[A][B] = W;
    }

    // Perform the Floyd-Warshall algorithm
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;

    // Answer the queries
    for (int q = 0; q < Q; ++q) {
        int X, Y;
        cin >> X >> Y;
        
        if (distance[X][Y] == INF) {
            cout << -1 << endl;
        } else {
            cout << distance[X][Y] << endl;
        }
    }

    return 0;
}
