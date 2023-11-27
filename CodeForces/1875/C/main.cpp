#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int p[32];

void test_case(int test) {
    int n, m; cin >> n >> m;
    int gcd = __gcd(n, m);
    n /= gcd; m /= gcd;
    if ((m & (m - 1)) == 0) {
        int g = __builtin_popcountll(m - 1);
        int ans = 0;
        for (int i = 0; i < g; i++) if ((n & (1ll << i)) != 0) {
            ans += p[g] - p[i];
        }
        cout << ans * gcd << '\n';
    } else {
        if (n % m == 0) cout << 0 << '\n';
        else cout << -1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    p[0] = 0ll;
    for (int i = 1; i < 32; i++) p[i] = p[i - 1] + (1ll << (i - 1));
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
