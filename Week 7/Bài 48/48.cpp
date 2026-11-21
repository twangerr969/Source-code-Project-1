#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool comparator1(pair<string, int> order, string time) {
    return order.first < time;
}
bool comparator2(string time, pair<string, int> order) {
    return time < order.first;
}
int main() {
    string s;
    vector<pair<string, long long>> order;
    string cusID, productID, shopID, time;
    long long price;
    unordered_map<string, unordered_map<string, long long>> totalConsume;
    unordered_map<string, long long> revenueShop;
    int total_number_orders = 0;
    long long total_revenue = 0;
    while(getline(cin, s)) {
        if(s == "#") break;
        stringstream ss(s);
        ss >> cusID >> productID >> price >> shopID >> time;
        total_number_orders++;
        total_revenue += price;
        totalConsume[shopID][cusID] += price;
        revenueShop[shopID] += price;
        order.push_back({time, price});
    }
    sort(order.begin(), order.end());
    vector<long long> prefSum(order.size() + 1, 0);
    prefSum[0] = 0;
    for(int i = 0; i < order.size(); i++) {
        prefSum[i + 1] = prefSum[i] + order[i].second;
    }
    while(getline(cin, s)) {
        if(s == "#") break;
        if(s.find("total_number_orders") != string::npos) {
            cout << total_number_orders << endl;
        } else if(s.find("total_revenue_in_period") != string::npos) {
            stringstream s3(s);
            string a, b, c;
            s3 >> a >> b >> c;
            int l = lower_bound(order.begin(), order.end(), b, comparator1) - order.begin();
            int r = upper_bound(order.begin(), order.end(), c, comparator2) - order.begin();
            cout << prefSum[r] - prefSum[l] << endl;
        } else if(s.find("revenue_of_shop") != string::npos) {
            stringstream s1(s);
            string a, b;
            s1 >> a >> b;
            cout << revenueShop[b] << endl;
        } else if(s.find("total_consume_of_customer_shop") != string::npos) {
            stringstream s2(s);
            string a, b, c;
            s2 >> a >> b >> c;
            cout << totalConsume[c][b] << endl;
        } else {
            cout << total_revenue << endl;
        }
    }
    return 0;
}
