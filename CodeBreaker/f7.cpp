#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n; 
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	
	int l = 0, r = n - 1, ans = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		bool win = true;
		for (int i = 0; i < m; i++) {
			if (a[m] + n < a[i] + i + 1) {
				win = false;
				break;
			}
		}
		
		// cout << m << ' ' << win << '\n';
		
		if (win) {
			ans = l;
			l = m + 1;
		} else r = m - 1;
	}
	
	cout << ans + 1;
}
