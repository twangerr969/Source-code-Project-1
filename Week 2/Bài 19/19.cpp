#include<iostream>
using namespace std;
#define MOD 1000000007
int main() {
    int k, n;
    cin >> k >> n;
    long long a[k + 1][n + 1];
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || i == j) a[i][j] = 1; 
            else if(i > j) a[i][j] = 0;
            else a[i][j] = (a[i - 1][j - 1] + a[i][j - 1]) % MOD;
        }
    }
    cout << a[k][n];
    return 0;
}
