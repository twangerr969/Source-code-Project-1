#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<set<int>> adj;
vector<bool> visited;
void DFS(int u) {
    cout << u << ' ';
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) DFS(v);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) DFS(i);
    }
    return 0;
}
