#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    string s; cin >> s;
    int pre[n+1], a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] ^ a[i];
        if (s[i] == '1') a1 ^= a[i];
        else a2 ^= a[i];
    }

    int q; cin >> q;
    while (q--) {
        int t, x, y; cin >> t;
        if (t == 1) {
            cin >> x >> y;
            a1 ^= (pre[y] ^ pre[x-1]);
            a2 ^= (pre[y] ^ pre[x-1]);
        } else {
            cin >> x;
            cout << (x == 0 ? a2 : a1) << ' ';
        }
    } cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
