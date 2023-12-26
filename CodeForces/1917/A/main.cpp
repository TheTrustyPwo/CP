#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    bool b = 0, b2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) b = 1;
        if (a[i] < 0) b2 ^= 1;
    }
    if (b || b2) { cout << "0\n"; return; }
    cout << 1 << '\n' << 1 << ' ' << 0 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
