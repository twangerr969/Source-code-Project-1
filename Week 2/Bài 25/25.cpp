#include<iostream>
using namespace std;
int N, r, c;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int curX, curY;
int curSum;
int maxSum;
int board[11][11];
bool visited[11][11];
bool check(int dx, int dy) {
    if(curX + dx < 1 || curX + dx > N || curY + dy < 1 || curY + dy > N) return false;
    if(visited[curX + dx][curY + dy]) return false;
    return true;
}
void Try(int r, int c) {
    for(int i = 0; i < 8; i++) {
        if(check(dx[i], dy[i])) {
            curX += dx[i];
            curY += dy[i];
            visited[curX][curY] = true;
            curSum += board[curX][curY];
            maxSum = max(curSum, maxSum);
            Try(curX, curY);
            visited[curX][curY] = false;
            curSum -= board[curX][curY];
            curX -= dx[i];
            curY -= dy[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> r >> c;
    curX = r;
    curY = c;
    visited[r][c] = true;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> board[i][j];
    }
    curSum = board[r][c];
    maxSum = curSum;
    Try(r, c);
    cout << maxSum;
    return 0;
}
