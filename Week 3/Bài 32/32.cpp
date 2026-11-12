#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> q;
    string s;
    int a;
    while(1) {
        cin >> s;
        if(s == "#") return 0;
        if(s == "PUSH") {
            cin >> a;
            q.push(a);
        } else {
            if(q.empty()) cout << "NULL" << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}
