#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int l, n; cin >> l >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		int pos, range; cin >> pos >> range;
		a[i] = make_pair(max(pos - range, 0), min(pos + range, l));
	}
	
	sort(a, a + n);
	
	int ending = 0, mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ending >= l) break;
		if (a[i].first <= ending) {
			mx = max(mx, a[i].second);
			if (i == n - 1 || a[i + 1].first > ending) {
				ending = mx;
				cnt++;
			}
		}
	}
	
	if (ending >= l) cout << cnt;
	else cout << -1;
}
