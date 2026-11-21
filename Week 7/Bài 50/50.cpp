#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, s, t;
vector<int> p;
vector<vector<int>> cap;
bool BFS() {
    p.assign(n + 1, -1);
    queue<int> q;
    q.push(s);
    p[s] = s;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 1; v <= n; v++) {
            if(cap[u][v] > 0 && p[v] == -1) {
                q.push(v);
                p[v] = u;
                if(v == t) return true;
            }
        }
    }
    return false;
}
int Edmonds_Karp() {
    int max_flow = 0;
    while(BFS()) {
        int minCost = 1e9;
        int v = t;
        while(v != s) {
            int u = p[v];
            minCost = min(minCost, cap[u][v]);
            v = u;
        }
        v = t;
        while(v != s) {
            int u = p[v];
            cap[u][v] -= minCost;
            cap[v][u] += minCost;
            v = u;
        }
        max_flow += minCost;
    }
    return max_flow;
}
int main() {
    cin >> n >> m;
    p.resize(n + 1);
    cap.resize(n + 1, vector<int>(n + 1, 0));
    cin >> s >> t;
    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        cap[u][v] = w;
    }
    cout << Edmonds_Karp();
    return 0;
}
