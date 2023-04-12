#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x) {
    int cur = 1;
    while (cur < x) cur *= 2;
    return cur;
}

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << i + 1 << ' ' << f(a[i]) - a[i] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
