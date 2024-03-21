#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int mn = 1e9, ans = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x < mn) ans++;
		mn = min(mn, x);
	}
	cout << ans;
}
