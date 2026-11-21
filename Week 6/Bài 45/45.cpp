#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<vector<pair<long long, int>>> adj;
vector<long long> dist;
void dijkstra(int s) {
    dist.assign(n + 1, 1e9);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dist[u]) continue;
        for(auto [w, v] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dist[i] != 1e9) cout << dist[i] << ' ';
        else cout << -1 << ' ';
    }
    cout << endl;
}
int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1, 1e9);
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    for(int i = 1; i <= n; i++) dijkstra(i);
    return 0;
}
