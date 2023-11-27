#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, x, y; cin >> n >> x >> y;
    int g = lcm(x, y);
    int m = (n/x - n/g), k = (n/y - n/g);
    int a = (n * m) - (m * (m - 1)) / 2;
    int b = (k * (k + 1)) / 2;
    cout << a - b << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
