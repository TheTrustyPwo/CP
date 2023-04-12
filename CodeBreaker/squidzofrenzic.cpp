#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[1000000];

int valid(int k) {
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > k) return false;
		if (sum + a[i] <= k) sum += a[i];
		else { sum = a[i]; cnt++; }
	}
	return cnt <= m - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (valid(mid)) { ans = mid; r = mid - 1; }
		else l = mid + 1;
	}
	cout << ans;
}
