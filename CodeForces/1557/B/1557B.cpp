#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		
		sort(a, a + n);
		
		int ans = 1;
		for (int i = 1; i < n; i++)
			if (a[i - 1].second + 1 != a[i].second) ans++;
			
		cout << (ans <= k ? "YES\n" : "NO\n");
	}
}
