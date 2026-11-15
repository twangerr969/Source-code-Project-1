#include<iostream>
using namespace std;
long long hashVal(string s, int m) {
    long long val = 0;
    for(char c : s) {
        val = (val * 256 + c) % m;
    }
    return val;
}
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    while(n--) {
        cin >> s;
        cout << hashVal(s, m) << endl;
    }
    return 0;
}
