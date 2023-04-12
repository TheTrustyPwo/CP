#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a = 0, b = 0, i = 0;
    bool q = false;
    while (n) {
        int digit = n % 10;
        if (digit & 1) {
            int temp = digit / 2;
            if (q) {
                a += temp * pow(10, i);
                b += (digit - temp) * pow(10, i); 
            } else {
                b += temp * pow(10, i);
                a += (digit - temp) * pow(10, i);  
            }
            q = !q;
        } else {
            digit /= 2;
            a += digit * pow(10, i);
            b += digit * pow(10, i);
        }
        n /= 10;
        i++;
    }
    cout << a << ' ' << b << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
