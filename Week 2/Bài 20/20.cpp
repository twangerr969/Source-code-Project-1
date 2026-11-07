#include<iostream>
using namespace std;
int a[10][10];
int cnt;
bool check(int x, int y, int num) {
    for(int i = 1; i < 10; i++) {
        if(a[x][i] == num) return false;
    }
    for(int i = 1; i < 10; i++) {
        if(a[i][y] == num) return false;
    }
    int startX = (x - 1) / 3 * 3 + 1;
    int startY = (y - 1) / 3 * 3 + 1;
    for(int i = startX; i < startX + 3; i++) {
        for(int j = startY; j < startY + 3; j++) {
            if(a[i][j] == num) return false;
        }
    }
    return true;
}
void Try(int x, int y) {
    if(x == 10) {
        cnt++;
        return;
    }
    if(a[x][y]) {
        if(y == 9) {
            Try(x + 1, 1);
        } 
        else Try(x, y + 1);
        return;
    }
    for(int i = 1; i < 10; i++) {
        if(check(x, y, i)) {
            a[x][y] = i;
            if(y == 9) Try(x + 1, 1);
            else Try(x, y + 1);
            a[x][y] = 0;
        }
    }
}
int main() {
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) cin >> a[i][j];
    }
    Try(1, 1);
    cout << cnt;
    return 0;
}
