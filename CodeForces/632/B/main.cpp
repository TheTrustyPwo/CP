#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    int total = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'B') total += a[i];

    int mx = total;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') total += a[i];
        else total -= a[i];
        mx = max(mx, total);
    }

    total = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'B') total += a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') total += a[i];
        else total -= a[i];
        mx = max(mx, total);
    }

    cout << mx;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
