#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> parent, sz;
struct Edge {
    int u, v;
    long long w;
};
vector<Edge> edges;
bool comparator(const Edge &a, const Edge &b) {
    return a.w < b.w;
}
void init() {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
}
int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
int main() {
    cin >> n >> m;
    init();
    edges.resize(m + 1);
    for(int i = 1; i <= m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), comparator);
    int cnt = 0, weight = 0;
    for(int i = 1; i <= m; i++) {
        if(unite(edges[i].u, edges[i].v)) {
            cnt++;
            weight += edges[i].w;
            if(cnt == n - 1) break;
        }
    } 
    cout << weight;
    return 0;
}

