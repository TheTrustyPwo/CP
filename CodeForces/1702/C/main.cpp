#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

struct chash {
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    __gnu_pbds::gp_hash_table<int, pair<int, int>, chash> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = make_pair(i, i);
        else
            mp[a[i]].second = i;
    }

    while (k--) {
        int x, y; cin >> x >> y;
        if (mp.find(x) == mp.end() || mp.find(y) == mp.end()) {
            cout << "NO\n";
        } else if (mp[y].second > mp[x].first) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
