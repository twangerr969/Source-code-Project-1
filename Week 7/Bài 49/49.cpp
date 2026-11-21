#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;
unordered_map<string, unordered_set<string>> adj;
unordered_set<string> visited;
int curK = 1;
bool check_cycle(string start_account, string account, int k) {
    for(auto x : adj[account]) {
        if(visited.find(x) == visited.end()) {
            visited.insert(x);
            curK++;
            if(curK == k) {
                if(adj[x].find(start_account) != adj[x].end()) {
                    curK--;
                    visited.erase(x);
                    return true;
                }
            }
            else if(check_cycle(start_account, x, k)) {
                curK--;
                visited.erase(x);
                return true;
            }
            curK--;
            visited.erase(x);
        }
    }
    return false;
}
int main() {
    string s;
    string from_account, to_account, time, atm;
    long long money;
    int number_transactions = 0;
    long long total_money_transaction = 0;
    set<string> listAccount;
    unordered_map<string, long long> total_money_transferred_from;
    while(getline(cin, s)) {
        if(s == "#") break;
        stringstream ss(s);
        ss >> from_account >> to_account >> money >> time >> atm;
        number_transactions++;
        total_money_transaction += money;
        listAccount.insert(from_account);
        listAccount.insert(to_account);
        total_money_transferred_from[from_account] += money;
        adj[from_account].insert(to_account);

    }
    while(getline(cin, s)) {
        if(s == "#") break;
        if(s.find("number_transaction") != string::npos) {
            cout << number_transactions << endl;
        } else if(s.find("total_money_transaction_from") != string::npos) {
            stringstream ss(s);
            string s1;
            ss >> s1 >> from_account;
            cout << total_money_transferred_from[from_account] << endl;
        }
        else if(s.find("list_sorted_accounts") != string::npos) {
            for(auto x : listAccount) cout << x << ' ';
            cout << endl;
        }
        else if(s.find("inspect_cycle") != string::npos) {
            stringstream ss(s);
            string s1;
            int k;
            ss >> s1 >> from_account >> k;
            visited.insert(from_account);
            if(check_cycle(from_account, from_account, k)) cout << 1 << endl;
            else cout << 0 << endl;
            visited.erase(from_account);
        } else {
            cout << total_money_transaction << endl;
        }
    }
    return 0;
}
