#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, pre[1000005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pre[i] = pre[i - 1] + x;
	}
	while (q--) {
		int x; cin >> x;
		int ans = lower_bound(pre, pre + n, x) - pre;
		cout << ans + 1 << '\n';
	}
}
