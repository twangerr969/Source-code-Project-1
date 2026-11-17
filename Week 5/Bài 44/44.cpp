#include<iostream>
#include<vector>
using namespace std;
vector<int> buildLPS(const string& p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len > 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int KMP(const string& t, const string& p) {
    int n = t.size();
    int m = p.size();
    if (m == 0) return 0;
    vector<int> lps = buildLPS(p);
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        }
        if (j == m) {
            cnt++;
            j = lps[j - 1];
        }
        else if (i < n && t[i] != p[j]) {
            if (j > 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return cnt;
}
int main() {
    string p, t;
    getline(cin, p);
    getline(cin, t);
    cout << KMP(t, p);
    return 0;
}
