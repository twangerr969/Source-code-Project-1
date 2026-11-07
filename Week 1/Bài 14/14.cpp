#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if(delta < 0) return !(cout << "NO SOLUTION");
    else if(delta > 0) {
        double solve1 = (-b - sqrt(delta)) / (2 * a);
        double solve2 = (-b + sqrt(delta)) / (2 * a);
        return !(cout << fixed << setprecision(2) << solve1 << ' ' << solve2);
    }
    else {
        double solve = -b / (2 * a);
        return !(cout << fixed << setprecision(2) << solve);
    }
    return 0;
}
