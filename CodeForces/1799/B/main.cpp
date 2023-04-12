#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    bool same = true;
    for (int i = 1; i < n; i++)
        if (a[i] != a[0]) same = false;
    if (same) { cout << 0 << '\n'; return; }

    if (*min_element(a, a + n) == 1) { cout << -1 << '\n'; return; }

    queue<pair<int, int>> op;
    while (true) {
        auto mn = min_element(a, a + n), mx = max_element(a, a + n);
        if (*mn == *mx) break;
        op.emplace(mx - a + 1, mn - a + 1);
        *mx = *mx / *mn + (*mx % *mn != 0);
    }

    cout << op.size() << '\n';
    while (!op.empty()) {
        cout << op.front().first << ' ' << op.front().second << '\n';
        op.pop();
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
