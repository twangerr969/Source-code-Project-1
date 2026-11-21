#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int N, K;
vector<vector<vector<int>>> graphs;
vector<vector<int>> deg;
vector<vector<int>> check_graph;
vector<int> p, n, m;
vector<int> used;
vector<int> deg_check;
int n_check, m_check;
unordered_map<string, vector<int>> Hash; //Mã hash được tạo từ số đỉnh, số cạnh và dãy bậc của đồ thị, ánh xạ tới các id của đồ thị có chung mã Hash
string getHash(int n, int m, vector<int> degree) {
    vector<int> d;
    for(int i = 1; i <= n; i++) {
        d.push_back(degree[i]);
    }
    sort(d.begin(), d.end());
    string key = to_string(n) + "|" + to_string(m) + "|";
    for(int x : d) {
        key += to_string(x) + ",";
    }
    return key;
}
bool Try(int k, int idGraph) {
    if(n_check != n[idGraph] || m_check != m[idGraph]) return false;
    for(int i = 1; i <= n[idGraph]; i++) {
        if(used[i]) continue;
        if(deg_check[k] != deg[idGraph][i]) continue;
        bool ok = true;
        for(int j = 1; j < k; j++) {
            if(check_graph[k][j] != graphs[idGraph][i][p[j]]) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        p[k] = i;
        used[i] = true;
        if(k == n_check) return true;
        else if(Try(k + 1, idGraph)) return true;
        used[i] = false;
        p[k] = 0;
    }
    return false;
}
void check() {
    string key = getHash(n_check, m_check, deg_check);
    if(Hash.find(key) == Hash.end()) {
        cout << 0 << '\n';
        return;
    }
    for(int id : Hash[key]) {
        used.assign(n_check + 1, false);
        p.assign(n_check + 1, 0);
        if(Try(1, id)) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    graphs.resize(N + 1);
    deg.resize(N + 1);
    n.resize(N + 1);
    m.resize(N + 1);
    int u, v;
    for(int i = 1; i <= N; i++) {
        cin >> n[i] >> m[i];
        graphs[i].assign(n[i] + 1, vector<int>(n[i] + 1, 0));
        deg[i].assign(n[i] + 1, 0);
        for(int j = 0; j < m[i]; j++) {
            cin >> u >> v;
            graphs[i][u][v] = 1;
            graphs[i][v][u] = 1;
            deg[i][u]++;
            deg[i][v]++;
        }
        string key = getHash(n[i], m[i], deg[i]);
        Hash[key].push_back(i);
    }
    char c;
    cin >> c;
    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> n_check >> m_check;
        check_graph.assign(n_check + 1, vector<int>(n_check + 1, 0));
        used.assign(n_check + 1, false);
        p.assign(n_check + 1, 0);
        deg_check.assign(n_check + 1, 0);
        for(int j = 0; j < m_check; j++) {
            cin >> u >> v;
            check_graph[u][v] = 1;
            check_graph[v][u] = 1;
            deg_check[u]++;
            deg_check[v]++;
        }
        check();
    }
    return 0;
}
