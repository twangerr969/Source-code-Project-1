#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;
queue<int> q;
vector<set<int>> adj;
vector<bool> visited;
void BFS(int u) {
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int x = q.front();
        cout << x << ' ';
        q.pop();
        for(int v : adj[x]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
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
        if(!visited[i]) BFS(i);
    }
    return 0;
}
