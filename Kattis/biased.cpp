#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			string s; cin >> s >> a[i];
		}
		sort(a, a + n);
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(a[i] - i - 1);
		}
		
		cout << ans << '\n';
	}
}
