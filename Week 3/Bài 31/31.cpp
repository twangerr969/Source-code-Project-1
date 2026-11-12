#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
int main() {
    int n;
    cin >> n;
    bool exist[1001] = {false};
    int b;
    for(int i = 0; i < n; i++) {
        cin >> b;
        a.push_back(b);
        exist[b] = true; 
    }
    int x, y;
    string s;
    while(1) {
        cin >> s;
        if(s == "#") break;
        if(s == "addlast") {
            cin >> x;
            if(!exist[x]) {
                a.push_back(x);
                exist[x] = true;
            }
        } else if(s == "addfirst") {
            cin >> x;
            if(!exist[x]) {
                a.insert(a.begin(), x);
                exist[x] = true;
            }
        } else if(s == "addafter") {
            cin >> x >> y;
            if(exist[x] || !exist[y]) continue;
            for(auto it = a.begin(); it != a.end(); it++) {
                if(*it == y) {
                    it++;
                    a.insert(it, x);
                    exist[x] = true;
                    break;
                }
            }
        } else if(s == "addbefore") {
            cin >> x >> y;
            if(exist[x] || !exist[y]) continue;
            for(auto it = a.begin(); it != a.end(); it++) {
                if(*it == y) {
                    a.insert(it, x);
                    exist[x] = true;
                    break;
                }
            }
        } else if(s == "remove") {
            cin >> x;
            if(exist[x]) {
                for(auto it = a.begin(); it != a.end(); it++) {
                    if(*it == x) {
                        a.erase(it);
                        exist[x] = false;
                        break;
                    }
                }
            }
        } else reverse(a.begin(), a.end());
    }
    for(int x : a) cout << x << ' ';
    return 0;
}
