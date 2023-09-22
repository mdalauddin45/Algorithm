#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int parent[N];
int parentLevel[N];
class Edge {
public:
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
void dsu_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}
int dsu_find(int node) {
    if (parent[node] == -1) return node;
    return parent[node] = dsu_find(parent[node]);
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
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    dsu_set(n);
    for (int i = 0; i < m; i++) {
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back(Edge(a,b,w));
    }
    sort(edges.begin(), edges.end(), cmp);
    int removedEdges = 0;
    long long total_const_cost = 0;
    
    for (Edge edge : edges) {
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
    if(removedEdges >=n-1) cout<<removedEdges<<" "<<total_const_cost<<endl;
    else cout<<"Not Possible"<<endl;
    
    return 0;
}