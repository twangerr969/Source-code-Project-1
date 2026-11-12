#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
const long long MOD = 1000000007;
int priority(char op) {
    if (op == '*') return 2;
    if (op == '+') return 1;
    return 0;
}
long long calc(long long a, long long b, char op) {
    if (op == '+')
        return (a + b) % MOD;
    return (a * b) % MOD;
}
bool apply(stack<long long>& values, stack<char>& ops) {
    if (values.size() < 2 || ops.empty())
        return false;
    long long b = values.top();
    values.pop();
    long long a = values.top();
    values.pop();
    char op = ops.top();
    ops.pop();
    values.push(calc(a, b, op));
    return true;
}
int main() {
    string s;
    getline(cin, s);
    stack<long long> values;
    stack<char> ops;
    bool expectOperand = true;
    for (int i = 0; i < (int)s.size(); ) {
        if (isspace(s[i])) {
            i++;
            continue;
        }
        if (isdigit(s[i])) {
            if (!expectOperand) {
                cout << "NOT_CORRECT";
                return 0;
            }
            long long num = 0;
            while (i < (int)s.size() && isdigit(s[i])) {
                num = (num * 10 + (s[i] - '0')) % MOD;
                i++;
            }
            if (num == 0) {
                cout << "NOT_CORRECT";
                return 0;
            }
            values.push(num);
            expectOperand = false;
        }
        else if (s[i] == '(') {
            if (!expectOperand) {
                cout << "NOT_CORRECT";
                return 0;
            }
            ops.push('(');
            i++;
        }
        else if (s[i] == ')') {
            if (expectOperand) {
                cout << "NOT_CORRECT";
                return 0;
            }
            bool foundOpen = false;
            while (!ops.empty()) {
                if (ops.top() == '(') {
                    foundOpen = true;
                    ops.pop();
                    break;
                }
                if (!apply(values, ops)) {
                    cout << "NOT_CORRECT";
                    return 0;
                }
            }
            if (!foundOpen) {
                cout << "NOT_CORRECT";
                return 0;
            }
            i++;
            expectOperand = false;
        }
        else if (s[i] == '+' || s[i] == '*') {
            if (expectOperand) {
                cout << "NOT_CORRECT";
                return 0;
            }
            char op = s[i];
            while (!ops.empty() &&
                   ops.top() != '(' &&
                   priority(ops.top()) >= priority(op)) {
                if (!apply(values, ops)) {
                    cout << "NOT_CORRECT";
                    return 0;
                }
            }
            ops.push(op);
            i++;
            expectOperand = true;
        }
        else {
            cout << "NOT_CORRECT";
            return 0;
        }
    }
    if (expectOperand) {
        cout << "NOT_CORRECT";
        return 0;
    }
    while (!ops.empty()) {
        if (ops.top() == '(') {
            cout << "NOT_CORRECT";
            return 0;
        }
        if (!apply(values, ops)) {
            cout << "NOT_CORRECT";
            return 0;
        }
    }
    if (values.size() != 1) {
        cout << "NOT_CORRECT";
        return 0;
    }
    cout << values.top();
    return 0;
}
