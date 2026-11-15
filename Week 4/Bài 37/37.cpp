#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    unordered_set<int> s;
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(s.find(a) != s.end()) cout << 1 << endl;
        else {
            s.insert(a);
            cout << 0 << endl;
        }
    }
    return 0;
}
