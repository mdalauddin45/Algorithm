#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int mxdist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != INF && dist[i][j] > mxdist) {
                mxdist = dist[i][j];
            }
        }
    }
    cout << mxdist << endl;

    return 0;
}
