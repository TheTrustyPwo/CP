#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n; int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp; int ans = 0;
    for (int i = 0; i < n; i++) {
        int d = round((log2(a[i]) - a[i]) * 1000000000);
        ans += mp[d];
        mp[d]++;
    } cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
