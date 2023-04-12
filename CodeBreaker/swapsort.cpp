#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q, cnt = 0, ans = 0; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != i + 1) cnt++;
	}
	cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		if (a[l] == l + 1) cnt++;
		else if (a[l] == r + 1) cnt--;
		if (a[r] == r + 1) cnt++;
		else if (a[r] == l + 1) cnt--;
		swap(a[l], a[r]);
		if (!cnt) ans++;
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
