#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n], s[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s[i] = a[i];
		}
		
		sort(s, s + n, greater<int>());
		int mx = s[0], mx2 = s[1];
		for (int i = 0; i < n; i++) {
			if (a[i] != mx) cout << a[i] - mx << ' ';
			else cout << mx - mx2 << ' ';
		}
		
		cout << '\n';
	}
}
