#include<iostream>
#define MOD 1000000007
using namespace std;
int main() {
    string s;
    cin >> s;
    long long exp_val = 0, num = 0, product = 1;
    bool nextIsNum = true;
    for(char c : s) {
        if(c >= '0' && c <= '9') {
            num = (num * 10 + c - '0') % MOD;
            nextIsNum = false;
        }
        else if(c == '+' || c == '*') {
            if(nextIsNum) return !(cout << "NOT_CORRECT");
            if(c == '+') {
                product = (product * num) % MOD;
                exp_val = (exp_val + product) % MOD;
                product = 1;
            }
            else product = (product * num) % MOD;
            num = 0;
            nextIsNum = true;
        }
        else return !(cout << "NOT_CORRECT");
    }
    if(nextIsNum) return !(cout << "NOT_CORRECT");
    product = (product * num) % MOD;
    exp_val = (exp_val + product) % MOD;
    cout << exp_val;
    return 0;
}
