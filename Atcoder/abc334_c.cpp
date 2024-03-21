#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[k]; for (int i = 0; i < k; i++) cin >> a[i];
	sort(a, a + k);
	if (k & 1) {
		int p1[k], p2[k]; p1[0] = 0; p2[k - 1] = 0;
		for (int i = 1; i < k; i += 2)
			p1[i] = p1[i + 1] = p1[i - 1] + a[i] - a[i - 1];
		for (int i = k - 2; i >= 0; i -= 2)
			p2[i] = p2[i - 1] = p2[i + 1] + a[i + 1] - a[i];
		int ans = 1e9;
		for (int i = 0; i < k; i++) ans = min(ans, p1[i] + p2[i]);
		cout << ans;
	} else {
		int ans = 0;
		for (int i = 0; i < k; i += 2) ans += a[i + 1] - a[i];
		cout << ans;
	}
}
