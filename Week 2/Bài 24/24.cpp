#include<iostream>
using namespace std;
int N;
int sum;
int a[30];
void Try(int pos) {
    for(int i = a[pos - 1]; i <= N; i++) {
        if(sum + i <= N) {
            a[pos] = i;
            sum += i;
            if(sum == N) {
                for(int j = 1; j <= pos; j++) cout << a[j] << ' ';
                cout << endl;
            }
            else Try(pos + 1);
            sum -= i;
        }
    }
}
int main() {
    cin >> N;
    a[0] = 1;
    Try(1);
    return 0;
}
