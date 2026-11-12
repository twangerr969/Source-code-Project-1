#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<char> st;
    string s;
    getline(cin, s);
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if(st.empty()) return !(cout << 0);
            char top = st.top();
            if(c == ')' && top != '(' || c == ']' && top != '[' || c == '}' && top != '{') return !(cout << 0);
            st.pop();
        }
    }
    cout << (st.empty() ? 1 : 0);
    return 0;
}
