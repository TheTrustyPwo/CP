#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	int sa = 0, sb = 0;
	for (int i = 0; i < n; i++) sa += a[i], sb += b[i];
	
	cout << (sb >= sa ? 1 : -1) << "\n";
	
	while (q--) {
		int t, x, v; cin >> t >> x >> v; x--;
		if (t == 1) {
			sa += (v - a[x]);
			a[x] = v;
		} else {
			sb += (v - b[x]);
			b[x] = v;
		}
		cout << (sb >= sa ? 1 : -1) << "\n";
	}
}
