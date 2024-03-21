#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int l[n + 1], r[n + 1]; l[n] = r[n] = 0;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	
	sort(l, l + n + 1, greater<int>());
	sort(r, r + n + 1);
	
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (l[i] <= r[i]) break;
		ans += l[i] - r[i];
	}
	
	cout << ans * 2;
}
