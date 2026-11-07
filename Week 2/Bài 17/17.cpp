#include<iostream>
using namespace std;
int a[21];
int n;
void Try(int pos) {
    if(pos == n) {
        for(int i = 0; i < n; i++) cout << a[i];
        cout << endl;
        return;
    }
    a[pos] = 0;
    Try(pos + 1);
    a[pos] = 1;
    Try(pos + 1);
}
int main() {
    cin >> n;
    Try(0);
    return 0;
}
