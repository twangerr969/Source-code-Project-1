#include<iostream>
#include<vector>
#include<map>
#include<sstream>
using namespace std;
map<string, vector<string>> famMem;
int countDescendant(string name) {
    if(!famMem.count(name)) return 0;
    int cnt = 0;
    for(auto x : famMem[name]) {
        cnt += 1;
        cnt += countDescendant(x);
    }
    return cnt;
}
int countGeneration(string name) {
    if(!famMem.count(name)) return 0;
    int cnt = 0;
    for(auto x : famMem[name]) {
        cnt = max(cnt, 1 + countGeneration(x));
    }
    return cnt;
}
int main() {
    string s, child, parent;
    while(getline(cin, s)) {
        if(s == "***") break;
        stringstream ss(s);
        ss >> child >> parent;
        famMem[parent].push_back(child);
    }
    while(getline(cin, s)) {
        if(s == "***") return 0;
        stringstream ss(s);
        ss >> child >> parent;
        if(child == "descendants") cout << countDescendant(parent) << endl;
        else cout << countGeneration(parent) << endl;
    }
}
