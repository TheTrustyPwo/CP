#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first >= a[0].first) mx = max(mx, a[i].second);
    }
    if (mx < a[0].second) cout << a[0].first << '\n';
    else cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
