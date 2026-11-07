#include<iostream>
#include<cctype>
using namespace std;
#define MOD 1000000007
int main() {
    string s;
    getline(cin, s);
    int num = 0;
    long long sum = 0;
    bool hasDigit = false;
    for(char c : s) {
        if(isdigit(c)) {
            num = (num * 10 + (c - '0')) % MOD;
            hasDigit = true;
        }
        else if(c == '+') {
            hasDigit = false;
            sum = (sum + num) % MOD;
            num = 0;
        }
        else return !(cout << "NOT_CORRECT");
    }
    if(!hasDigit) return !(cout << "NOT_CORRECT");
    else sum = (sum + num) % MOD;
    cout << sum;
    return 0;
}
