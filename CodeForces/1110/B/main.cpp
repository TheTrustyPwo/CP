#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m, k; cin >> n >> m >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<int> v;
    for (int i = 1; i < n; i++) v.push_back(a[i] - a[i - 1]);
    sort(v.begin(), v.end());
    int ans = k;
    for (int i = 0; i < max(0, (int) v.size() - k + 1); i++) ans += v[i];
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
