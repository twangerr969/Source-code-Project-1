#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
int n;
int main() {
    cin >> n;
    int RMQ[n][15];
    int max_ele = -1001, min_ele = 1001, sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> RMQ[i][0];
        if(RMQ[i][0] > max_ele) max_ele = RMQ[i][0];
        if(RMQ[i][0] < min_ele) min_ele = RMQ[i][0];
        sum += RMQ[i][0];
    }
    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            RMQ[i][j] = max(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
        }
    }
    string s;
    getline(cin, s);
    while(getline(cin, s)) {
        if(s == "*") continue;
        if(s == "***") return 0;
        if(s == "find-max") cout << max_ele << endl;
        else if(s == "find-min") cout << min_ele << endl;
        else if(s == "sum") cout << sum << endl;
        else {
            stringstream ss(s);
            string s1;
            int x, y;
            ss >> s1 >> x >> y;
            int k = log2(y - x + 1);
            cout << max(RMQ[x - 1][k], RMQ[y - (1 << k)][k]) << endl;
        }
    }
    return 0;
}
