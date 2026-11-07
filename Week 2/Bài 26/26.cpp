#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> a;
vector<bool> used;
void Try(int k) {
    for(int i = 1; i <= n; i++) {
        if(!used[i - 1]) {
            a[k] = i;
            used[i - 1] = true;
            if(k == n - 1) {
                for(int x : a) cout << x << ' ';
                cout << endl;
            }
            else Try(k + 1);
            used[i - 1] = false;
        }
    }
}
int main() {
    cin >> n;
    a.resize(n);
    used.resize(n, false);
    Try(0);
    return 0;
}
