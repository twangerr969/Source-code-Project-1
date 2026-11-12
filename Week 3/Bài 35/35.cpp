#include<iostream>
#include<vector>
#include<queue>
struct state {
    int x, y, step;
};
using namespace std;
int a, b, c;
vector<vector<bool>> visited;
bool solve() {
    queue<state> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y;
        if(x == c || y == c) {
            cout << cur.step;
            return true;
        }
        vector<pair<int, int>> v;
        v.push_back({a, y});
        v.push_back({x, b});
        v.push_back({0, y});
        v.push_back({x, 0});
        int z = min(x,  b - y);
        v.push_back({x - z, y + z});
        z = min(a - x, y);
        v.push_back({x + z, y - z});
        for(auto [nx, ny] : v) {
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
    return false;
}
int main() {
    cin >> a >> b >> c;
    visited.resize(a + 1, vector<bool>(b + 1));
    if(!solve()) return !(cout << -1);
    return 0;
}
