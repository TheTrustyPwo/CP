#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		int mn = 0, mx = 1e9;
		for (int i = 0; i < n - 1; i++) {
			int x = a[i], y = a[i + 1];
			int midf = (x + y) / 2, midc = (x + y + 1) / 2;
			if (x < y) mx = min(mx, midf);
			else if (x > y) mn = max(mn, midc);
		}
		
		cout << (mx >= mn ? mn : -1) << '\n';
	}
}
