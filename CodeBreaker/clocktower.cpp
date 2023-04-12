#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, h; cin >> n >> h;
	ll a[n-1]; for (int i = 0; i < n - 1; i++) cin >> a[i];
	ll m = h / n, ans = 0;
	for (ll i = 1; i < n; i++)
		if (a[i-1] >= m * i) ans++;
	if (ans == 0) cout << "YES";
	else cout << "NO" << endl << ans;
}
