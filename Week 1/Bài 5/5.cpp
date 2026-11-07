#include<iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    if(s[2] != ':' || s[5] != ':') return !(cout << "INCORRECT");
    if(!isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[3]) || !isdigit(s[4]) || !isdigit(s[6]) || !isdigit(s[7])) return !(cout << "INCORRECT");
    int hh, mm, ss;
    sscanf(s.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    if(hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) return !(cout << "INCORRECT");
    cout << hh * 3600 + mm * 60 + ss;
    return 0;
}
