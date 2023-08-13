#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
vector<string> g(N);
int visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];  // Change here
int n, m;
int si, sj, di, dj;
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int i, int j) {
    queue<pii> q;
    q.push({i, j});
    visited[i][j] = true;
    level[i][j] = 0;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;

        for (auto d : direc) {
            int ni = x + d.first;
            int nj = y + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#') {
                visited[ni][nj] = true;
                level[ni][nj] = level[x][y] + 1;
                parent[ni][nj] = {x, y};
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                si = i;
                sj = j;
            } else if (g[i][j] == 'B') {
                di = i;
                dj = j;
            }
        }
    }
    bfs(si, sj);
    
    if (!visited[di][dj]) cout << "NO" << endl;
    else {
        cout << "YES" << endl << level[di][dj] << endl;
        
        vector<pii> path;
        pii cur = {di, dj};
        while (cur != make_pair(si, sj)) {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());
        for (int i = 1; i < path.size(); i++) {
            int x = path[i].first - path[i-1].first;
            int y = path[i].second - path[i-1].second;
            if (x == 1) cout << "D";
            else if (x == -1) cout << "U";
            else if (y == 1) cout << "R";
            else cout << "L";
        }
        cout << endl;
    }

    return 0;
}
