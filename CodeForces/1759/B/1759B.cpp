#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int m, s; cin >> m >> s;
		int a[m]; for (int i = 0; i < m; i++) cin >> a[i];
		sort(a, a + m);
		
		int cnt = 0;
		for (int i = 1; i < m; i++) {
			if (a[i] - a[i - 1] == 1) continue;
			int x = a[i - 1] + 1, y = a[i] - 1;
			cnt += y*(y+1)/2 - x*(x+1)/2 + x;
		}
		
		int cur = a[m - 1] + 1;
		while (cnt < s) cnt += cur, cur++;
		
		if (cnt == s) cout << "YES\n";
		else cout << "NO\n";
	}
}
