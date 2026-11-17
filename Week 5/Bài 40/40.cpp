#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<vector<int>> a;
vector<bool> visited;
vector<int> path;
bool hamilton(int pos) {
    for(int i = 2; i <= n; i++) {
        if(!visited[i] && a[path[pos - 1]][i] == 1) {
            path[pos] = i;
            visited[i] = true;
            if(pos == n && a[path[n]][1] == 1) return true;
            else if(pos < n) {
                if(hamilton(pos + 1)) return true;
            }
            visited[i] = false;
        }
    }
    return false;
}
int main() {
    int q;
    cin >> q;
    int u, v;
    while(q--) {
        cin >> n >> m;
        a.assign(n + 1, vector<int>(n + 1, 0));
        visited.assign(n + 1, false);
        path.assign(n + 1, 0);
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[u][v] = a[v][u] = 1;
        }
        path[1] = 1;
        visited[1] = true;
        cout << hamilton(2) << endl;
    }
    return 0;
}
