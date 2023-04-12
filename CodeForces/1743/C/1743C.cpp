#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool lid[n]; int a[n];
		for (int i = 0; i < n; i++) {
			char ch; cin >> ch;
			lid[i] = ch == '1';
		}
		
		for (int i = 0; i < n; i++) cin >> a[i];
		
		for (int i = 1; i < n; i++) {
			if (lid[i - 1] || !lid[i]) continue;
			if (a[i] > a[i - 1]) lid[i] = 0, lid[i - 1] = 1;
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += (lid[i] * a[i]);
		
		cout << ans << '\n';
	}
}
