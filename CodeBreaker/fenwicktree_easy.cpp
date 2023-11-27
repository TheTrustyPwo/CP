#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int d[n]; for (int i = 0; i < n; i++) cin >> d[i];
	int pre[n + 1]; bool f = 0;
	int q; cin >> q;
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) {
			d[a - 1] = b;
		} else {
			if (!f) {
				pre[0] = 0; pre[1] = d[0];
				for (int i = 2; i <= n; i++) pre[i] = pre[i - 1] + d[i - 1];
			}
			cout << pre[b] - pre[a - 1] << '\n';
		}
	}
}
