#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k, a, b; cin >> n >> k >> a >> b; a--; b--;
    pair<int, int> c[n]; for (int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;
    if (a < k && b < k) { cout << 0 << '\n'; return; }
    int mn1 = 1e18, mn2 = 1e18;
    for (int i = 0; i < k; i++) {
        mn1 = min(mn1, abs(c[i].first - c[b].first) + abs(c[i].second - c[b].second));
        mn2 = min(mn2, abs(c[i].first - c[a].first) + abs(c[i].second - c[a].second));
    }
    if (a < k) { cout << mn1 << '\n'; return; }
    if (b < k) { cout << mn2 << '\n'; return; }
    int cost = abs(c[a].first - c[b].first) + abs(c[a].second - c[b].second);
    cout << min(cost, mn1 + mn2) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
