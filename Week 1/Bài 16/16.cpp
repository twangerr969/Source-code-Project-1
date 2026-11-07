#include<iostream>
using namespace std;
int main() {
    string s1, s2, T;
    getline(cin, s1);
    getline(cin, s2);
    while(getline(cin, T)) {
        size_t pos = T.find(s1);
        while(pos != string::npos) {
            T.replace(pos, s1.size(), s2);
            pos = T.find(s1, pos + s2.size());
        }
        cout << T;
    }
    return 0;
}
