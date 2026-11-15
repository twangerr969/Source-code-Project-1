#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    string a, b;
    unordered_set<string> s;
    while(a != "*") {
        cin >> a;
        s.insert(a);
    }
    while(1) {
        cin >> a;
        if(a == "***") return 0;
        if(a == "find") {
            cin >> b;
            if(s.find(b) != s.end()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            cin >> b;
            if(s.find(b) == s.end()) {
                s.insert(b);
                cout << 1 << endl;
            } else cout << 0 << endl;
        }
    }
}
