#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	while (q--) {
		int x, y, z; cin >> x >> y >> z;
		int cnt = 0;
		for (int i = 0; i < n; i++) if (a[i] >= x && b[i] >= y && (a[i] + b[i]) >= z) cnt++;
		cout << cnt << '\n';
	}
}
