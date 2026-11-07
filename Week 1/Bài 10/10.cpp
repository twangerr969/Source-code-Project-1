#include<iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0;
    int Q = 0;
    for(int i = 0; i < k; i++) {
        sum += a[i];
    }
    if(sum % 2 == 0) Q++;
    for(int i = k; i < n; i++) {
        sum = sum - a[i - k] + a[i];
        if(sum % 2 == 0) Q++;
    }
    cout << Q;
    return 0;
}
