#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s, k; cin >> n >> s >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		ans += x * y;
	}
	if (ans < s) ans += k;
	cout << ans;
}
