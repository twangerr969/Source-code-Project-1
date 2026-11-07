#include<iostream>
#include<iomanip>
using namespace std;
double calc_elec1(double elec_num) {
    if(elec_num >= 0 && elec_num <= 50) return elec_num * 1728;
    if(elec_num <= 100) return 86400 + (elec_num - 50) * 1786;
    if(elec_num <= 200) return 175700 + (elec_num - 100) * 2074;
    if(elec_num <= 300) return 383100 + (elec_num - 200) * 2612;
    if(elec_num <= 400) return 644300 + (elec_num - 300) * 2919;
    return 936200 + (elec_num - 400) * 3015;
}
double calc_elec2(double elec_num) {
    if(elec_num >= 0 && elec_num <= 100) return elec_num * 1728;
    if(elec_num <= 200) return 172800 + (elec_num - 100) * 2074;
    if(elec_num <= 400) return 380200 + (elec_num - 200) * 2612;
    if(elec_num <= 700) return 902600 + (elec_num - 400) * 3111;
    return 1835900 + (elec_num - 700) * 3457;
}
int main() {
    double elec_num;
    cin >> elec_num;
    cout << fixed << setprecision(2) << 1.1 * (calc_elec2(elec_num) - calc_elec1(elec_num));
    return 0;   
}
