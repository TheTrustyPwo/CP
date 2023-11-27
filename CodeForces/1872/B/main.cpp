#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, a[i].first + (a[i].second - 1) / 2);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
