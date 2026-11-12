#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> st;
    string s;
    int a;
    while(1) {
        cin >> s;
        if(s == "#") return 0;
        if(s == "PUSH") {
            cin >> a;
            st.push(a);
        } else {
            if(st.empty()) cout << "NULL" << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }
    }
}
