#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    bool taken[n + 1]{};
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        bool b = false;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (taken[x] || b) continue;
            taken[x] = 1;
            b = true;
        }
        if (!b) ans = i + 1;
    }
    if (ans == -1) { cout << "OPTIMAL\n"; return; }
    int p = 0;
    for (int i = 1; i <= n; i++) if (!taken[i]) {
        p = i;
        break;
    }
    cout << "IMPROVE\n";
    cout << ans << ' ' << p << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
