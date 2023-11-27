#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[200005];

bool countPairs(ll mid) {
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] < 0) {
            ll x = ceil((long double) mid / a[i]);
            ll amt = lower_bound(a, a + n, x) - a;
            cnt += (n - amt);
        } else if (a[i] > 0) {
            ll x = floor((long double) mid / a[i]);
            cnt += (upper_bound(a, a + n, x) - a);
        } else if (mid >= 0) {
            cnt += n;
        }
        if (a[i] * a[i] <= mid) {
            cnt--;
        }
    }
    cnt /= 2;
    return cnt >= m;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (ll i = 0ll; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
    ll l = -1e18, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (countPairs(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
	
	cout << ans;
}
