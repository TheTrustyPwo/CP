#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define double long double

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x; cin >> n >> x;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	pair<double, pair<int, int>> b[n];
	for (int i = 0; i < n; i++) b[i] = make_pair(((double) a[i] / (double) (1ll << i)), make_pair(i, a[i]));
	sort(b, b + n, greater<pair<double, pair<int, int>>>());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int p = (1ll << b[i].second.first);
		if (x < p) continue;
		int amt = x / p;
		ans += amt * b[i].second.second;
		x %= p;
	}
	
	cout << ans;
}
