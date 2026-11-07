#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int countOdd = 0, countEven = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) countEven++;
        else countOdd++;
    }
    cout << countOdd << ' ' << countEven;
    return 0;
}
