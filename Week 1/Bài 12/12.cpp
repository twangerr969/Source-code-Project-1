#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a = 100 / n;
    for(int i = a; n * i <= 999; i++) {
        if(n * i >= 100) cout << n * i << ' ';
    }
    return 0;
}
