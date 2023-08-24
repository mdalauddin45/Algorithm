#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1005;
bool vis[N][N];
vector<pii> path={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void bfs(char arr[][N], int si, int sj) {
    queue<pii> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        for (auto cell : path) {
            int new_x = x + cell.first;
            int new_y = y + cell.second;

            if (isValid(new_x, new_y) && !vis[new_x][new_y] && arr[new_x][new_y] != '-') {
                q.push({new_x, new_y});
                vis[new_x][new_y] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    char arr[N][N];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs(arr, si, sj);

    if (vis[di][dj]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
