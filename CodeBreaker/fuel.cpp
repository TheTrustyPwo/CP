#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l, t; cin >> n >> l >> t;
	int a[n + 2]; a[0] = 0, a[n + 1] = l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 2);
	int last = 0, cnt = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] - a[i - 1] > t) {
			cout << -1;
			return 0;
		}
		if (a[i] - last > t) {
			last = a[i - 1];
			cnt++;
		}
	}
	cout << cnt;
}
