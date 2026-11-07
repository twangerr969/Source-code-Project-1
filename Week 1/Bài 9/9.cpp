#include<iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    if(s[4] != '-' || s[7] != '-') return !(cout << "INCORRECT");
    for(char c : s) {
        if(!isdigit(c) && c != '-') return !(cout << "INCORRECT");
    }
    int year, month, day;
    sscanf(s.c_str(), "%d-%d-%d", &year, &month, &day);
    if(month < 1 || month > 12 || day < 1 || day > 31) return !(cout << "INCORRECT");
    cout << year << ' ' << month << ' ' << day;
    return 0;
}
