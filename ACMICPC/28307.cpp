#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[2][n]; for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	int ans = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (a[0][i] == 0) {
			if (cur >= 1) ans += 2 + cur;
			cur = 0;
		} else cur++;
	}
	if (cur >= 1) ans += 2 + cur; cur = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0 && a[0][i] == 1 && a[1][i] == 1) ans -= 2;
		if (a[1][i] == 0) {
			if (cur >= 1) ans += 2 + cur;
			cur = 0;
		} else cur++;
	}
	if (cur >= 1) ans += 2 + cur; cur = 0;
	cout << ans;
}
