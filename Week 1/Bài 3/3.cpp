#include<iostream>
using namespace std;
int n, m;
int main() {
    cin >> n;
    int a[n], prefSum[n + 1];
    for(int i = 0; i < n; i++) cin >> a[i]; 
    prefSum[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefSum[i] = prefSum[i - 1] + a[i - 1];
    }
    cin >> m;
    int i1, j1, i2, j2;
    while(m--) {
        cin >> i1 >> j1 >> i2 >> j2;
        if(prefSum[j1] - prefSum[i1 - 1] < prefSum[j2] - prefSum[i2 - 1]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
